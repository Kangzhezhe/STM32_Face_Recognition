#ifndef __MAX30102_H
#define __MAX30102_H
#include "sys.h"
#include "main.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ���������ɣ��������������κ���;
//Mini STM32������
//IIC ��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2010/6/10 
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ����ԭ�� 2009-2019
//All rights reserved
////////////////////////////////////////////////////////////////////////////////// 	  

   	   		   
//IO��������
//#define SDA_IN()  {GPIOB->CRH&=0XFFFFFFF0;GPIOB->CRH|=4;}
//#define SDA_OUT() {GPIOB->CRH&=0XFFFFFFF0;GPIOB->CRH|=7;}
#define SDA_IN()  {MAX30102_SDA_GPIO_Port -> MODER &= 0xffffff3f;}
#define SDA_OUT() {MAX30102_SDA_GPIO_Port -> MODER &= 0xffffff3f; MAX30102_SDA_GPIO_Port -> MODER |= (uint32_t)(1 << 6);}

//IO��������	 
// #define IIC_SCL    PCout(0) //SCL
// #define IIC_SDA    PAout(3) //SDA	 
// #define READ_SDA   PAin(3)  //����SDA 

//IIC���в�������
void IIC_Init(void);                //��ʼ��IIC��IO��				 
void IIC_Start(void);				//����IIC��ʼ�ź�
void IIC_Stop(void);	  			//����IICֹͣ�ź�
void IIC_Send_Byte(u8 txd);			//IIC����һ���ֽ�
u8 IIC_Read_Byte(unsigned char ack);//IIC��ȡһ���ֽ�
u8 IIC_Wait_Ack(void); 				//IIC�ȴ�ACK�ź�
void IIC_Ack(void);					//IIC����ACK�ź�
void IIC_NAck(void);				//IIC������ACK�ź�

void IIC_Write_One_Byte(u8 daddr,u8 addr,u8 data);
void IIC_Read_One_Byte(u8 daddr,u8 addr,u8* data);

void IIC_WriteBytes(u8 WriteAddr,u8* data,u8 dataLength);
void IIC_ReadBytes(u8 deviceAddr, u8 writeAddr,u8* data,u8 dataLength);
#endif
















