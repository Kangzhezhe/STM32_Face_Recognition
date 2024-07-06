#include "main.h"
#include "sccb.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ���������ɣ��������������κ���;
//ALIENTEK STM32F407������
//OVϵ������ͷ SCCB ��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//��������:2014/5/14
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) �������������ӿƼ����޹�˾ 2014-2024
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 
//#define SCCB_SDA_IN()    {GPIOB->MODER&=~(3<<(9*2));GPIOB->MODER|=0<<9*2;}	//Pb9 ����
//#define SCCB_SDA_OUT()   {GPIOB->MODER&=~(3<<(9*2));GPIOB->MODER|=1<<9*2;} 	//Pb9 ���
void SCCB_SDA_IN(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	
 	GPIO_InitStructure.Pin = SDA_Pin;				 // ????
 	GPIO_InitStructure.Mode = GPIO_MODE_INPUT; 
  GPIO_InitStructure.Pull = GPIO_PULLUP;	//??
	HAL_GPIO_Init(GPIOB, &GPIO_InitStructure);
	HAL_GPIO_WritePin(GPIOB,SDA_Pin,1);
}
void SCCB_SDA_OUT()
{
  GPIO_InitTypeDef  GPIO_InitStruct;
  GPIO_InitStruct.Pin =  SDA_Pin;//GPIO_InitStruct.Pin = SCL_Pin|SDA_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;//GPIO_MODE_OUTPUT_OD//GPIO_MODE_OUTPUT_OD
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
		HAL_GPIO_WritePin(GPIOB,SDA_Pin,1);
}
static void delay_us(u16 time)
{    
   u32 i=0;  
   while(time--)
   {
      i=100;  //????
      while(i>0)  i=i-1;    
   }

}
//��ʼ��SCCB�ӿ� 
void SCCB_Init(void)
{				
	SCCB_SDA_OUT();
 // GPIOB->MODER&=~(3<<(9*2));GPIOB->MODER|=1<<9*2;	
}			 

//SCCB��ʼ�ź�
//��ʱ��Ϊ�ߵ�ʱ��,�����ߵĸߵ���,ΪSCCB��ʼ�ź�
//�ڼ���״̬��,SDA��SCL��Ϊ�͵�ƽ
void SCCB_Start(void)
{
	SCCB_SDA_OUT();
		HAL_GPIO_WritePin(GPIOB, SDA_Pin, GPIO_PIN_SET);
		delay_us(5);
    //SCCB_SDA=1;     //�����߸ߵ�ƽ	
    HAL_GPIO_WritePin(GPIOB, SCL_Pin, GPIO_PIN_SET);	
    //SCCB_SCL=1;	    //��ʱ���߸ߵ�ʱ���������ɸ�����
    delay_us(5);  
	  HAL_GPIO_WritePin(GPIOB, SDA_Pin, GPIO_PIN_RESET);
    //SCCB_SDA=0;
    delay_us(5); 
	  HAL_GPIO_WritePin(GPIOB, SCL_Pin, GPIO_PIN_RESET);
	delay_us(5);
    //SCCB_SCL=0;	    //�����߻ָ��͵�ƽ��������������Ҫ	  
}

//SCCBֹͣ�ź�
//��ʱ��Ϊ�ߵ�ʱ��,�����ߵĵ͵���,ΪSCCBֹͣ�ź�
//����״����,SDA,SCL��Ϊ�ߵ�ƽ
void SCCB_Stop(void)
{
	SCCB_SDA_OUT();
    //SCCB_SDA=0;
	  HAL_GPIO_WritePin(GPIOB, SDA_Pin, GPIO_PIN_RESET);
    delay_us(5); 
    //SCCB_SCL=1;	
   	HAL_GPIO_WritePin(GPIOB, SCL_Pin, GPIO_PIN_SET);
    delay_us(5);  
    //SCCB_SDA=1;	
	  HAL_GPIO_WritePin(GPIOB, SDA_Pin, GPIO_PIN_SET);
    delay_us(5); 
}  
//����NA�ź�
void SCCB_No_Ack(void)
{
	SCCB_SDA_OUT(); 
//HAL_Delay(2);	
	//SCCB_SDA=1;	
	HAL_GPIO_WritePin(GPIOB, SDA_Pin, GPIO_PIN_SET);
	delay_us(5);
	//SCCB_SCL=1;	
	HAL_GPIO_WritePin(GPIOB, SCL_Pin, GPIO_PIN_SET);
	delay_us(5);
	//SCCB_SCL=0;	
	HAL_GPIO_WritePin(GPIOB, SCL_Pin, GPIO_PIN_RESET);
	delay_us(5);
	//SCCB_SDA=0;	
	HAL_GPIO_WritePin(GPIOB, SDA_Pin, GPIO_PIN_RESET);
	delay_us(5); 
}
//SCCB,д��һ���ֽ�
//����ֵ:0,�ɹ�;1,ʧ��. 
u8 SCCB_WR_Byte(u8 dat)
{
	u8 j,res;	 
	for(j=0;j<8;j++) //ѭ��8�η�������
	{
		if(dat&0x80)HAL_GPIO_WritePin(GPIOB, SDA_Pin, GPIO_PIN_SET);//SCCB_SDA=1;	
		else HAL_GPIO_WritePin(GPIOB, SDA_Pin, GPIO_PIN_RESET);//SCCB_SDA=0;
		dat<<=1;
		delay_us(5);  
		HAL_GPIO_WritePin(GPIOB, SCL_Pin, GPIO_PIN_SET);//SCCB_SCL=1;	
		delay_us(5); 
		HAL_GPIO_WritePin(GPIOB, SCL_Pin, GPIO_PIN_RESET);//SCCB_SCL=0;		   
	}			 
	SCCB_SDA_IN();		//����SDAΪ����  
	//GPIOB->MODER&=~(3<<(9*2));GPIOB->MODER|=0<<9*2;
	delay_us(5); 
	HAL_GPIO_WritePin(GPIOB, SCL_Pin, GPIO_PIN_SET);//SCCB_SCL=1;			//���յھ�λ,���ж��Ƿ��ͳɹ�
	delay_us(5); 
	if(HAL_GPIO_ReadPin(GPIOB,SDA_Pin))res=1;  //SDA=1����ʧ�ܣ�����1
	else res=0;         //SDA=0���ͳɹ�������0
	HAL_GPIO_WritePin(GPIOB, SCL_Pin, GPIO_PIN_RESET);//SCCB_SCL=0;		 
	SCCB_SDA_OUT();		//����SDAΪ��� 
  //GPIOB->MODER&=~(3<<(9*2));GPIOB->MODER|=1<<9*2;	
	return res;  
}	 
//SCCB ��ȡһ���ֽ�
//��SCL��������,��������
//����ֵ:����������
u8 SCCB_RD_Byte(void)
{
	u8 temp=0,j;    
	SCCB_SDA_IN();		//����SDAΪ����  
	delay_us(5);
	//GPIOB->MODER&=~(3<<(9*2));GPIOB->MODER|=0<<9*2;
	for(j=8;j>0;j--) 	//ѭ��8�ν�������
	{		     	  
		delay_us(5);
		HAL_GPIO_WritePin(GPIOB, SCL_Pin, GPIO_PIN_SET);//SCCB_SCL=1;
		temp=temp<<1;
		if(HAL_GPIO_ReadPin(GPIOB,SDA_Pin))temp++;   
		delay_us(5); 
		HAL_GPIO_WritePin(GPIOB, SCL_Pin, GPIO_PIN_RESET);//SCCB_SCL=0;
	}	
	SCCB_SDA_OUT();		//����SDAΪ���    
	//GPIOB->MODER&=~(3<<(9*2));GPIOB->MODER|=1<<9*2;
	return temp;
} 							    
//д�Ĵ���
//����ֵ:0,�ɹ�;1,ʧ��.
u8 SCCB_WR_Reg(u8 reg,u8 data)
{
	u8 res=0;
	SCCB_Start(); 					//����SCCB����
	if(SCCB_WR_Byte(SCCB_ID))res=1;	//д����ID	  
	delay_us(100);  
  	if(SCCB_WR_Byte(reg))res=1;		//д�Ĵ�����ַ	  
	delay_us(100);  
  	if(SCCB_WR_Byte(data))res=1; 	//д����	 
  	SCCB_Stop();	  
  	return	res;
}		  					    
//���Ĵ���
//����ֵ:�����ļĴ���ֵ
u8 SCCB_RD_Reg(u8 reg)
{
	u8 val=0;
	SCCB_Start(); 				//����SCCB����
	SCCB_WR_Byte(SCCB_ID);		//д����ID	  
	delay_us(100);  	 
  SCCB_WR_Byte(reg);			//д�Ĵ�����ַ	  
	delay_us(100);  	  
	SCCB_Stop();   
	delay_us(100);  		   
	//���üĴ�����ַ�󣬲��Ƕ�
	SCCB_Start();
	SCCB_WR_Byte(SCCB_ID|0X01);	//���Ͷ�����	  
	delay_us(100);  	
  	val=SCCB_RD_Byte();		 	//��ȡ����
  	SCCB_No_Ack();
  	SCCB_Stop();
  	return val;
}















