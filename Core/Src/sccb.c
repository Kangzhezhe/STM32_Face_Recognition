#include "main.h"
#include "sccb.h"
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK STM32F407开发板
//OV系列摄像头 SCCB 驱动代码	   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//创建日期:2014/5/14
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2014-2024
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 
//#define SCCB_SDA_IN()    {GPIOB->MODER&=~(3<<(9*2));GPIOB->MODER|=0<<9*2;}	//Pb9 输入
//#define SCCB_SDA_OUT()   {GPIOB->MODER&=~(3<<(9*2));GPIOB->MODER|=1<<9*2;} 	//Pb9 输出
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
//初始化SCCB接口 
void SCCB_Init(void)
{				
	SCCB_SDA_OUT();
 // GPIOB->MODER&=~(3<<(9*2));GPIOB->MODER|=1<<9*2;	
}			 

//SCCB起始信号
//当时钟为高的时候,数据线的高到低,为SCCB起始信号
//在激活状态下,SDA和SCL均为低电平
void SCCB_Start(void)
{
	SCCB_SDA_OUT();
		HAL_GPIO_WritePin(GPIOB, SDA_Pin, GPIO_PIN_SET);
		delay_us(5);
    //SCCB_SDA=1;     //数据线高电平	
    HAL_GPIO_WritePin(GPIOB, SCL_Pin, GPIO_PIN_SET);	
    //SCCB_SCL=1;	    //在时钟线高的时候数据线由高至低
    delay_us(5);  
	  HAL_GPIO_WritePin(GPIOB, SDA_Pin, GPIO_PIN_RESET);
    //SCCB_SDA=0;
    delay_us(5); 
	  HAL_GPIO_WritePin(GPIOB, SCL_Pin, GPIO_PIN_RESET);
	delay_us(5);
    //SCCB_SCL=0;	    //数据线恢复低电平，单操作函数必要	  
}

//SCCB停止信号
//当时钟为高的时候,数据线的低到高,为SCCB停止信号
//空闲状况下,SDA,SCL均为高电平
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
//产生NA信号
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
//SCCB,写入一个字节
//返回值:0,成功;1,失败. 
u8 SCCB_WR_Byte(u8 dat)
{
	u8 j,res;	 
	for(j=0;j<8;j++) //循环8次发送数据
	{
		if(dat&0x80)HAL_GPIO_WritePin(GPIOB, SDA_Pin, GPIO_PIN_SET);//SCCB_SDA=1;	
		else HAL_GPIO_WritePin(GPIOB, SDA_Pin, GPIO_PIN_RESET);//SCCB_SDA=0;
		dat<<=1;
		delay_us(5);  
		HAL_GPIO_WritePin(GPIOB, SCL_Pin, GPIO_PIN_SET);//SCCB_SCL=1;	
		delay_us(5); 
		HAL_GPIO_WritePin(GPIOB, SCL_Pin, GPIO_PIN_RESET);//SCCB_SCL=0;		   
	}			 
	SCCB_SDA_IN();		//设置SDA为输入  
	//GPIOB->MODER&=~(3<<(9*2));GPIOB->MODER|=0<<9*2;
	delay_us(5); 
	HAL_GPIO_WritePin(GPIOB, SCL_Pin, GPIO_PIN_SET);//SCCB_SCL=1;			//接收第九位,以判断是否发送成功
	delay_us(5); 
	if(HAL_GPIO_ReadPin(GPIOB,SDA_Pin))res=1;  //SDA=1发送失败，返回1
	else res=0;         //SDA=0发送成功，返回0
	HAL_GPIO_WritePin(GPIOB, SCL_Pin, GPIO_PIN_RESET);//SCCB_SCL=0;		 
	SCCB_SDA_OUT();		//设置SDA为输出 
  //GPIOB->MODER&=~(3<<(9*2));GPIOB->MODER|=1<<9*2;	
	return res;  
}	 
//SCCB 读取一个字节
//在SCL的上升沿,数据锁存
//返回值:读到的数据
u8 SCCB_RD_Byte(void)
{
	u8 temp=0,j;    
	SCCB_SDA_IN();		//设置SDA为输入  
	delay_us(5);
	//GPIOB->MODER&=~(3<<(9*2));GPIOB->MODER|=0<<9*2;
	for(j=8;j>0;j--) 	//循环8次接收数据
	{		     	  
		delay_us(5);
		HAL_GPIO_WritePin(GPIOB, SCL_Pin, GPIO_PIN_SET);//SCCB_SCL=1;
		temp=temp<<1;
		if(HAL_GPIO_ReadPin(GPIOB,SDA_Pin))temp++;   
		delay_us(5); 
		HAL_GPIO_WritePin(GPIOB, SCL_Pin, GPIO_PIN_RESET);//SCCB_SCL=0;
	}	
	SCCB_SDA_OUT();		//设置SDA为输出    
	//GPIOB->MODER&=~(3<<(9*2));GPIOB->MODER|=1<<9*2;
	return temp;
} 							    
//写寄存器
//返回值:0,成功;1,失败.
u8 SCCB_WR_Reg(u8 reg,u8 data)
{
	u8 res=0;
	SCCB_Start(); 					//启动SCCB传输
	if(SCCB_WR_Byte(SCCB_ID))res=1;	//写器件ID	  
	delay_us(100);  
  	if(SCCB_WR_Byte(reg))res=1;		//写寄存器地址	  
	delay_us(100);  
  	if(SCCB_WR_Byte(data))res=1; 	//写数据	 
  	SCCB_Stop();	  
  	return	res;
}		  					    
//读寄存器
//返回值:读到的寄存器值
u8 SCCB_RD_Reg(u8 reg)
{
	u8 val=0;
	SCCB_Start(); 				//启动SCCB传输
	SCCB_WR_Byte(SCCB_ID);		//写器件ID	  
	delay_us(100);  	 
  SCCB_WR_Byte(reg);			//写寄存器地址	  
	delay_us(100);  	  
	SCCB_Stop();   
	delay_us(100);  		   
	//设置寄存器地址后，才是读
	SCCB_Start();
	SCCB_WR_Byte(SCCB_ID|0X01);	//发送读命令	  
	delay_us(100);  	
  	val=SCCB_RD_Byte();		 	//读取数据
  	SCCB_No_Ack();
  	SCCB_Stop();
  	return val;
}















