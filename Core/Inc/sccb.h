#ifndef __SCCB_H
#define __SCCB_H
#include "main.h"
#include "stm32h753xx.h" 
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


//IO方向设置
//#define SCCB_SDA_IN()    {GPIOB->MODER&=~(3<<(9*2));GPIOB->MODER|=0<<9*2;}	//Pb9 输入
//#define SCCB_SDA_OUT()   {GPIOB->MODER&=~(3<<(9*2));GPIOB->MODER|=1<<9*2;} 	//Pb9 输出


//IO操作函数	 
#define SCCB_SCL    		PBout(8)	 	//SCL
#define SCCB_SDA    		PBout(9) 		//SDA	 

//#define SCCB_READ_SDA    	PBin(9)  		//输入SDA    
#define SCCB_ID   			0X78  			//OV2640的ID

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













