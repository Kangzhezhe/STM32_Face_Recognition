#include "gt911.h"
#include "stdio.h"
//#include "IIC.h"
//_m_tp_dev tp_dev;		
typedef struct
{
	u8 (*init)(void);			//��ʼ��������������
	u8 (*scan)(u8);				//ɨ�败����.0,��Ļɨ��;1,��������;	 
	void (*adjust)(void);		//������У׼ 
	u16 x[CT_MAX_TOUCH]; 		//��ǰ����
	u16 y[CT_MAX_TOUCH];		//�����������5������,����������x[0],y[0]����:�˴�ɨ��ʱ,����������,��
								//x[4],y[4]�洢��һ�ΰ���ʱ������. 
	u8  sta;					//�ʵ�״̬ 
								//b7:����1/�ɿ�0; 
	                            //b6:0,û�а�������;1,�а�������. 
								//b5:����
								//b4~b0:���ݴ��������µĵ���(0,��ʾδ����,1��ʾ����)
/////////////////////������У׼����(����������ҪУ׼)//////////////////////								
	float xfac;					
	float yfac;
	short xoff;
	short yoff;	   
//�����Ĳ���,��������������������ȫ�ߵ�ʱ��Ҫ�õ�.
//b0:0,����(�ʺ�����ΪX����,����ΪY�����TP)
//   1,����(�ʺ�����ΪY����,����ΪX�����TP) 
//b1~6:����.
//b7:0,������
//   1,������ 
	u8 touchtype;
}_m_tp_dev;

extern _m_tp_dev tp_dev;

//extern _m_tp_dev tp_dev;
#define LCD_W SSD_HOR_RESOLUTION
#define LCD_H SSD_VER_RESOLUTION
/*�������������ݼĴ�����ʼ��ַ*/
const uint16_t GT911_TPX_TBL[5]={GT_TP1_REG,GT_TP2_REG,GT_TP3_REG,GT_TP4_REG,GT_TP5_REG};

//GT911���ò�����--������ҫԪ��2.8��IPS��Ļ����ͬ�ߴ���Ļ���ò�����������
const uint8_t GT911_CFG_TBL[]=
{ 
0x61,0xE0,0x01,0x20,0x03,0x05,0x04,0x10,0x01,0xC8,0x28,
0x0F,0x50,0x32,0x03,0x05,0x00,0x00,0x00,0x00,0x11,
0x11,0x05,0x18,0x1A,0x1E,0x14,0x88,0x29,0x0A,0x52,
0x50,0x40,0x04,0x00,0x00,0x00,0x1A,0x32,0x1C,0x46,
0x09,0x00,0x0F,0x00,0x2A,0xFF,0x7F,0x19,0x50,0x32,
0x3C,0x64,0x94,0xD5,0x02,0x07,0x00,0x00,0x04,0x9F,
0x3F,0x00,0x90,0x46,0x00,0x84,0x4D,0x00,0x79,0x55,
0x00,0x6D,0x5F,0x00,0x6D,0x00,0x00,0x00,0x00,0xF0,
0x4A,0x3A,0xFF,0xFF,0x27,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x14,0x12,0x10,0x0E,0x0C,0x0A,0x08,0x06,0x04,
0x02,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0x22,0x21,0x20,0x1F,0x1E,0x1D,0x1C,0x18,0x16,
0x12,0x10,0x0F,0x08,0x06,0x04,0x02,0x00,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,
};  



/*
* �������ƣ� GT911_Send_Cfg
* ���������� ����GT911���ò���
* ��������� mode:0,���������浽flash
*                1:�������浽flash
*   ����ֵ�� 0,�ɹ�;1,ʧ��.
*/
void GT911_Send_Cfg(uint8_t mode)
{
	uint8_t buf[2];
	uint8_t i=0;
	buf[0]=0;
	buf[1]=mode;	//�Ƿ�д�뵽GT911 FLASH?  ���Ƿ���籣��
	for(i=0;i<sizeof(GT911_CFG_TBL);i++)buf[0]+=GT911_CFG_TBL[i];//����У���
    buf[0]=(~buf[0])+1;
	GT911_WR_Reg(GT_CFGS_REG,(uint8_t*)GT911_CFG_TBL,sizeof(GT911_CFG_TBL));//���ͼĴ�������
	GT911_WR_Reg(GT_CHECK_REG,buf,2);//д��У���,�����ø��±��
} 


/*
* �������ƣ� GT911_WR_Reg
* ���������� ��GT911д��һ������
* ��������� reg:��ʼ�Ĵ�����ַ
*           buf:���ݻ�������
*           len:д���ݳ���	
*   ����ֵ�� 0,�ɹ�;1,ʧ��.
*/
uint8_t GT911_WR_Reg(uint16_t reg,uint8_t *buf,uint8_t len)
{
	uint8_t i;
	uint8_t ret=0;	
	
	CT_IIC_Start();	
 	CT_IIC_Send_Byte(GT_CMD_WR);   	//����д���� 	 
	CT_IIC_Wait_Ack();
	CT_IIC_Send_Byte(reg>>8);   	//���͸�8λ��ַ
	CT_IIC_Wait_Ack(); 	 										  		   
	CT_IIC_Send_Byte(reg&0XFF);   	//���͵�8λ��ַ
	CT_IIC_Wait_Ack();  
	for(i=0;i<len;i++)
	{	   
    CT_IIC_Send_Byte(buf[i]);  	//������
		ret=CT_IIC_Wait_Ack();
		if(ret)break;  
	}
    CT_IIC_Stop();					//����һ��ֹͣ����	    
	return ret; 
}
 
/*
* �������ƣ� GT911_RD_Reg
* ���������� ��GT911����һ������
* ��������� reg:��ʼ�Ĵ�����ַ
*           buf:���ݻ�������
*           len:�����ݳ���	
*   ����ֵ�� ��
*/
void GT911_RD_Reg(uint16_t reg,uint8_t *buf,uint8_t len)
{
	uint8_t i; 
 	CT_IIC_Start();	
 	CT_IIC_Send_Byte(GT_CMD_WR);   //����д���� 	 
	CT_IIC_Wait_Ack();
 	CT_IIC_Send_Byte(reg>>8);   	//���͸�8λ��ַ
	CT_IIC_Wait_Ack(); 	 										  		   
 	CT_IIC_Send_Byte(reg&0XFF);   	//���͵�8λ��ַ
	CT_IIC_Wait_Ack();  
 	CT_IIC_Start();  	 	   
	CT_IIC_Send_Byte(GT_CMD_RD);   //���Ͷ�����		   
	CT_IIC_Wait_Ack();	   
	for(i=0;i<len;i++)
	{	   
    	buf[i]=CT_IIC_Read_Byte(i==(len-1)?0:1); //������	  
	} 
    CT_IIC_Stop();//����һ��ֹͣ����    
} 

/*
* �������ƣ� GT911_Init
* ���������� ��ʼ��GT911������
* ��������� ��
*   ����ֵ�� 0,��ʼ���ɹ�;1,��ʼ��ʧ��
*/
 
uint8_t GT911_Init(void)
{
	
//	uint8_t zancun[190]; /*����ʹ��*/
//	uint8_t i;
//	uint8_t z;
	
	uint8_t temp[5]; 
//	GPIO_InitTypeDef  GPIO_InitStructure;	
//	
//  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);//ʹ��GPIOB,Cʱ��

//  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 ;//PB1����Ϊ��������
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;//����ģʽ
//  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//�������
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
//  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//����
//  GPIO_Init(GPIOB, &GPIO_InitStructure);//��ʼ��
//		
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;//PC13����Ϊ�������
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//���ģʽ
//	GPIO_Init(GPIOB, &GPIO_InitStructure);//��ʼ��	

	
	
	CT_IIC_Init();      	//��ʼ����������I2C����  
  //GT_RST=0;//��λ
  HAL_GPIO_WritePin(GPIOG, GPIO_PIN_0, GPIO_PIN_RESET);
	HAL_Delay(1);
	//GT_RST=1;//�ͷŸ�λ	
    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_0, GPIO_PIN_SET);
	HAL_Delay(5); 
	

	
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
//  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
//	GPIO_Init(GPIOB, &GPIO_InitStructure);//��ʼ��	
	
	HAL_Delay(10);  
	GT911_RD_Reg(GT_PID_REG,temp,4);//��ȡ��ƷID
	temp[4]=0;
	printf("CTP ID:%s\r\n",temp);	//��ӡID
	if(strcmp((char*)temp,"911")==0)//ID==9147
	{
		temp[0]=0X02;			
		GT911_WR_Reg(GT_CTRL_REG,temp,1);//����λGT911
		GT911_RD_Reg(GT_CFGS_REG,temp,1);//��ȡGT_CFGS_REG�Ĵ���
		
		
		/*��������ȡGT911����0x8047-0x80FE�ļĴ�������*/
/*
		GT911_RD_Reg(GT_CFGS_REG,(uint8_t *)zancun,186);		 //��ȡ�����üĴ���ֵ
		for(i=0;i<186;i++)
		{
		    if(i<185){z+=zancun[i];}
			  if(i==185){printf("У��ֵ1��%x\r\n",z);}
				printf("%x,",zancun[i]);                   //��ӡ�����üĴ���ֵ
		}
*/
		
		if(temp[0]<0X62)//Ĭ�ϰ汾�Ƚϵ�,��Ҫ����flash����
		{
			printf("Default Ver:%x\r\n",temp[0]);
			//GT911_Send_Cfg(1);//���²���������
		}
		HAL_Delay(10);
		temp[0]=0X00;	 
		GT911_WR_Reg(GT_CTRL_REG,temp,1);//������λ   
		return 0;
	} 
	return 0;
}

/*
* �������ƣ� GT911_Scan
* ���������� ɨ�败����(���ò�ѯ��ʽ)
* ��������� mode:0,����ɨ��.
* ���������� ��
*   ����ֵ�� ��ǰ����״̬.0,�����޴���;1,�����д���
*/
#define SCAN_INTER 1
uint8_t GT911_Scan(uint8_t mode)
{
	uint8_t buf[4]; /*����������Ϣ�洢������*/
	uint8_t i=0;
	uint8_t res=0;  /*���ش���״̬*/
	uint8_t temp;   
	uint8_t tempsta;  /*���浱ǰ����״̬*/
 	static uint8_t t=0;//���Ʋ�ѯ���,�Ӷ�����CPUռ����   
	t++;
	
	if((t%SCAN_INTER)==0||t<SCAN_INTER)//����ʱ,ÿ����10��CTP_Scan�����ż��1��,�Ӷ���ʡCPUʹ����
	{
		GT911_RD_Reg(GT_GSTID_REG,&mode,1);	//��ȡ�������״̬  
		temp=0;
		GT911_WR_Reg(GT_GSTID_REG,&temp,1);//���־ 			
		if((mode&0XF)&&((mode&0XF)<6)) 
		{
			temp=0XFF<<(mode&0XF);		//����ĸ���ת��Ϊ1��λ��,ƥ��tp_dev.sta���� 
			tempsta=tp_dev.sta;			//���浱ǰ��tp_dev.staֵ
			tp_dev.sta=(~temp)|TP_PRES_DOWN|TP_CATH_PRES; 
			tp_dev.x[4]=tp_dev.x[0];	//���津��0������
			tp_dev.y[4]=tp_dev.y[0];
			for(i=0;i<1;i++)
			{
				if(tp_dev.sta&(1<<i))	//������Ч?
				{
					GT911_RD_Reg(GT911_TPX_TBL[i],buf,4);	//��ȡXY����ֵ  
					//tp_dev.y[i]=240-(((uint16_t)buf[1]<<8)+buf[0]);
//					tp_dev.y[i]=480 - (((uint16_t)buf[1]<<8)+buf[0]);
//					tp_dev.x[i]=((uint16_t)buf[3]<<8)+buf[2];
//					
					tp_dev.y[i]=(((uint16_t)buf[1]<<8)+buf[0]);
					tp_dev.x[i]=800-(((uint16_t)buf[3]<<8)+buf[2]);
					// printf("x[%d]:%d,y[%d]:%d\r\n",i,tp_dev.x[i],i,tp_dev.y[i]);
				}			
			 } 
			res=1;
			if(tp_dev.x[0]>LCD_W||tp_dev.y[0]>LCD_H)//�Ƿ�����(���곬����)
			{ 
				if((mode&0XF)>1)		//��������������,�򸴵ڶ�����������ݵ���һ������.
				{
					tp_dev.x[0]=tp_dev.x[1];
					tp_dev.y[0]=tp_dev.y[1];
					t=0;				//����һ��,��������������10��,�Ӷ����������
				}
				else					//�Ƿ�����,����Դ˴�����(��ԭԭ����)  
				{
					tp_dev.x[0]=tp_dev.x[4];
					tp_dev.y[0]=tp_dev.y[4];
					mode=0X80;		
					tp_dev.sta=tempsta;	//�ָ�tp_dev.sta
				}
			 }
			 else t=0;					//����һ��,��������������10��,�Ӷ����������
		}
	}
	if((mode&0X8F)==0X80)//�޴����㰴��
	{ 
		if(tp_dev.sta&TP_PRES_DOWN)	//֮ǰ�Ǳ����µ�
		{
			tp_dev.sta&=~(1<<7);	//��ǰ����ɿ�
		}
		tp_dev.x[0]=0xffff;
		tp_dev.y[0]=0xffff;
		tp_dev.sta&=0XE0;	//�������Ч���	
	} 	
	if(t>240)t=SCAN_INTER;//���´�10��ʼ����
	return res;
}




 //5�����ص����ɫ(���ݴ�������)												 
const uint16_t POINT_COLOR_TBL[5]={RED,GREEN,BLUE,BROWN,GRED};  

//���������Գ���
void ctp_test(void)
{
	uint8_t i=0;	    
 	uint16_t lastpos[5][2];		//�洢ÿ������������һ��λ����Ϣ
	while(1)
	{
		GT911_Scan(0);
		for(i=0;i<5;i++)    /*�������������*/
		{
			if((tp_dev.sta)&(1<<i))
			{
				if(tp_dev.x[i]<LCD_W&&tp_dev.y[i]<LCD_H)
				{
					if(lastpos[i][0]==0XFFFF)
					{
						lastpos[i][0] = tp_dev.x[i];
						lastpos[i][1] = tp_dev.y[i];
					}
					LCD_DrawLine(lastpos[i][0],lastpos[i][1],tp_dev.x[i],tp_dev.y[i]);//����
					lastpos[i][0]=tp_dev.x[i];
					lastpos[i][1]=tp_dev.y[i];
					if(tp_dev.x[i]>(LCD_W-24)&&tp_dev.y[i]<20)
					{
						LCD_Fill(0,0,LCD_W,LCD_H,WHITE);//��������ɫ���������ͼ
					}
				}
			}else lastpos[i][0]=0XFFFF;
		}
		
		HAL_Delay(5);
	}	
}
