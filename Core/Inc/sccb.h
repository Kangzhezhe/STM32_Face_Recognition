#ifndef __SCCB_H
#define __SCCB_H
#include "main.h"
#include "stm32h753xx.h" 
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK STM32F407������
//OVϵ������ͷ SCCB ��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//��������:2014/5/14
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2014-2024
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 


//IO��������
//#define SCCB_SDA_IN()    {GPIOB->MODER&=~(3<<(9*2));GPIOB->MODER|=0<<9*2;}	//Pb9 ����
//#define SCCB_SDA_OUT()   {GPIOB->MODER&=~(3<<(9*2));GPIOB->MODER|=1<<9*2;} 	//Pb9 ���


//IO��������	 
#define SCCB_SCL    		PBout(8)	 	//SCL
#define SCCB_SDA    		PBout(9) 		//SDA	 

//#define SCCB_READ_SDA    	PBin(9)  		//����SDA    
#define SCCB_ID   			0X78  			//OV2640��ID

///////////////////////////////////////////
//void delay_us(u16 time);
void SCCB_SDA_OUT();
void SCCB_SDA_IN(void);
void SCCB_Init(void);
void SCCB_Start(void);
void SCCB_Stop(void);
void SCCB_No_Ack(void);
u8 SCCB_WR_Byte(u8 dat);
u8 SCCB_RD_Byte(void); 
#endif













