#ifndef __MYCT_IIC_H
#define __MYCT_IIC_H
#include "main.h"	    
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK STM32F407开发板
//电容触摸屏-IIC 驱动代码	   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//创建日期:2014/5/7
//版本：V1.1
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2014-2024
//All rights reserved									  
//********************************************************************************
//修改说明
//V1.1 20140721
//1,修改CT_IIC_Read_Byte函数,读数据更快.
//2,修改CT_IIC_Wait_Ack函数,以支持MDK的-O2优化.
////////////////////////////////////////////////////////////////////////////////// 	

//IO方向设置
// #define CT_SDA_IN()  {GPIOB->MODER&=~(3<<(2*1));GPIOB->MODER|=0<<2*1;}	//PF11输入模式
// #define CT_SDA_OUT() {GPIOB->MODER&=~(3<<(2*1));GPIOB->MODER|=1<<2*1;} 	//PF11输出模式
//IO操作函数	 
// #define CT_IIC_SCL    PGout(1) 	//SCL
// #define CT_IIC_SDA    PFout(9) //SDA	 
// #define CT_READ_SDA   PFin(9)  //输入SDA 
 


//IIC所有操作函数
void CT_IIC_Init(void);                	//初始化IIC的IO口				 
void CT_IIC_Start(void);				//发送IIC开始信号
void CT_IIC_Stop(void);	  				//发送IIC停止信号
void CT_IIC_Send_Byte(u8 txd);			//IIC发送一个字节
u8 CT_IIC_Read_Byte(unsigned char ack);	//IIC读取一个字节
u8 CT_IIC_Wait_Ack(void); 				//IIC等待ACK信号
void CT_IIC_Ack(void);					//IIC发送ACK信号
void CT_IIC_NAck(void);					//IIC不发送ACK信号

#endif







