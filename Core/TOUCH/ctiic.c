#include "ctiic.h"
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
#include "delay.h"


//控制I2C速度的延时
void CT_Delay(void)
{
    delay_us(2);
}
//电容触摸芯片IIC接口初始化
void CT_IIC_Init(void)
{
//    GPIO_InitTypeDef GPIO_Initure;

//    __HAL_RCC_GPIOB_CLK_ENABLE();   		//使能GPIOB时钟
//    __HAL_RCC_GPIOF_CLK_ENABLE();   		//使能GPIOF时钟

//    //PB0,PF11
//    GPIO_Initure.Pin = GPIO_PIN_0;			//PB0设置为推挽输出
//    GPIO_Initure.Mode = GPIO_MODE_OUTPUT_OD; //开漏输出
//    GPIO_Initure.Pull = GPIO_PULLUP;        //上拉
//    GPIO_Initure.Speed = GPIO_SPEED_HIGH;   //高速
//    HAL_GPIO_Init(GPIOB, &GPIO_Initure);

//    GPIO_Initure.Pin = GPIO_PIN_11;			//PF11设置推挽输出
//    HAL_GPIO_Init(GPIOF, &GPIO_Initure);

    HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_1, GPIO_PIN_SET);
}
//产生IIC起始信号
void CT_IIC_Start(void)
{
    HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_1, GPIO_PIN_SET);
    CT_Delay();
    HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_RESET); //START:when CLK is high,DATA change form high to low
    CT_Delay();
    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_1, GPIO_PIN_RESET); //钳住I2C总线，准备发送或接收数据
    CT_Delay();
}
//产生IIC停止信号
void CT_IIC_Stop(void)
{
    HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_RESET); //STOP:when CLK is high DATA change form low to high
    CT_Delay();
    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_1, GPIO_PIN_SET);
    CT_Delay();
    HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_SET); //发送I2C总线结束信号
    CT_Delay();
}
//等待应答信号到来
//返回值：1，接收应答失败
//        0，接收应答成功
u8 CT_IIC_Wait_Ack(void)
{
    u8 ucErrTime = 0;
    u8 rack = 0;

    HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_SET);
    CT_Delay();
    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_1, GPIO_PIN_SET);
    CT_Delay();
    while (HAL_GPIO_ReadPin(GPIOF, GPIO_PIN_9))
    {
        ucErrTime++;

        if (ucErrTime > 250)
        {
            CT_IIC_Stop();
            rack = 1;
            break;
        }

        CT_Delay();
    }

    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_1, GPIO_PIN_RESET); //时钟输出0
    CT_Delay();
    return rack;
}
//产生ACK应答
void CT_IIC_Ack(void)
{
    HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_RESET);
    CT_Delay();
    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_1, GPIO_PIN_SET);
    CT_Delay();
    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_1, GPIO_PIN_RESET);
    CT_Delay();
    HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_SET);
    CT_Delay();
}
//不产生ACK应答
void CT_IIC_NAck(void)
{
    HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_SET);
    CT_Delay();
    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_1, GPIO_PIN_SET);
    CT_Delay();
    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_1, GPIO_PIN_RESET);
    CT_Delay();
}
//IIC发送一个字节
//返回从机有无应答
//1，有应答
//0，无应答
void CT_IIC_Send_Byte(u8 txd)
{
    u8 t;

    for (t = 0; t < 8; t++)
    {
        HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, (GPIO_PinState)((txd & 0x80) >> 7));
        CT_Delay();
        HAL_GPIO_WritePin(GPIOG, GPIO_PIN_1, GPIO_PIN_SET);
        CT_Delay();
        HAL_GPIO_WritePin(GPIOG, GPIO_PIN_1, GPIO_PIN_RESET);
        txd <<= 1;
    }

    HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_SET);
}
//读1个字节，ack=1时，发送ACK，ack=0，发送nACK
u8 CT_IIC_Read_Byte(unsigned char ack)
{
    u8 i, receive = 0;

    for (i = 0; i < 8; i++ )
    {
        receive <<= 1;

        HAL_GPIO_WritePin(GPIOG, GPIO_PIN_1, GPIO_PIN_SET);
        CT_Delay();

        if (HAL_GPIO_ReadPin(GPIOF, GPIO_PIN_9))receive++;

        HAL_GPIO_WritePin(GPIOG, GPIO_PIN_1, GPIO_PIN_RESET);
        CT_Delay();
    }

    if (!ack)CT_IIC_NAck();//发送nACK
    else CT_IIC_Ack(); //发送ACK

    return receive;
}





























