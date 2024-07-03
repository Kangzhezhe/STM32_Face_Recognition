#include "gt911.h"
#include "stdio.h"
//#include "IIC.h"
//_m_tp_dev tp_dev;		
typedef struct
{
	u8 (*init)(void);			//初始化触摸屏控制器
	u8 (*scan)(u8);				//扫描触摸屏.0,屏幕扫描;1,物理坐标;	 
	void (*adjust)(void);		//触摸屏校准 
	u16 x[CT_MAX_TOUCH]; 		//当前坐标
	u16 y[CT_MAX_TOUCH];		//电容屏有最多5组坐标,电阻屏则用x[0],y[0]代表:此次扫描时,触屏的坐标,用
								//x[4],y[4]存储第一次按下时的坐标. 
	u8  sta;					//笔的状态 
								//b7:按下1/松开0; 
	                            //b6:0,没有按键按下;1,有按键按下. 
								//b5:保留
								//b4~b0:电容触摸屏按下的点数(0,表示未按下,1表示按下)
/////////////////////触摸屏校准参数(电容屏不需要校准)//////////////////////								
	float xfac;					
	float yfac;
	short xoff;
	short yoff;	   
//新增的参数,当触摸屏的左右上下完全颠倒时需要用到.
//b0:0,竖屏(适合左右为X坐标,上下为Y坐标的TP)
//   1,横屏(适合左右为Y坐标,上下为X坐标的TP) 
//b1~6:保留.
//b7:0,电阻屏
//   1,电容屏 
	u8 touchtype;
}_m_tp_dev;

extern _m_tp_dev tp_dev;

//extern _m_tp_dev tp_dev;
#define LCD_W SSD_HOR_RESOLUTION
#define LCD_H SSD_VER_RESOLUTION
/*五个触摸点的数据寄存器起始地址*/
const uint16_t GT911_TPX_TBL[5]={GT_TP1_REG,GT_TP2_REG,GT_TP3_REG,GT_TP4_REG,GT_TP5_REG};

//GT911配置参数表--适用于耀元鸿2.8寸IPS屏幕。不同尺寸屏幕配置参数会有区别
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
* 函数名称： GT911_Send_Cfg
* 功能描述： 更新GT911配置参数
* 传入参数： mode:0,参数不保存到flash
*                1:参数保存到flash
*   返回值： 0,成功;1,失败.
*/
void GT911_Send_Cfg(uint8_t mode)
{
	uint8_t buf[2];
	uint8_t i=0;
	buf[0]=0;
	buf[1]=mode;	//是否写入到GT911 FLASH?  即是否掉电保存
	for(i=0;i<sizeof(GT911_CFG_TBL);i++)buf[0]+=GT911_CFG_TBL[i];//计算校验和
    buf[0]=(~buf[0])+1;
	GT911_WR_Reg(GT_CFGS_REG,(uint8_t*)GT911_CFG_TBL,sizeof(GT911_CFG_TBL));//发送寄存器配置
	GT911_WR_Reg(GT_CHECK_REG,buf,2);//写入校验和,和配置更新标记
} 


/*
* 函数名称： GT911_WR_Reg
* 功能描述： 向GT911写入一次数据
* 传入参数： reg:起始寄存器地址
*           buf:数据缓缓存区
*           len:写数据长度	
*   返回值： 0,成功;1,失败.
*/
uint8_t GT911_WR_Reg(uint16_t reg,uint8_t *buf,uint8_t len)
{
	uint8_t i;
	uint8_t ret=0;	
	
	CT_IIC_Start();	
 	CT_IIC_Send_Byte(GT_CMD_WR);   	//发送写命令 	 
	CT_IIC_Wait_Ack();
	CT_IIC_Send_Byte(reg>>8);   	//发送高8位地址
	CT_IIC_Wait_Ack(); 	 										  		   
	CT_IIC_Send_Byte(reg&0XFF);   	//发送低8位地址
	CT_IIC_Wait_Ack();  
	for(i=0;i<len;i++)
	{	   
    CT_IIC_Send_Byte(buf[i]);  	//发数据
		ret=CT_IIC_Wait_Ack();
		if(ret)break;  
	}
    CT_IIC_Stop();					//产生一个停止条件	    
	return ret; 
}
 
/*
* 函数名称： GT911_RD_Reg
* 功能描述： 从GT911读出一次数据
* 传入参数： reg:起始寄存器地址
*           buf:数据缓缓存区
*           len:读数据长度	
*   返回值： 无
*/
void GT911_RD_Reg(uint16_t reg,uint8_t *buf,uint8_t len)
{
	uint8_t i; 
 	CT_IIC_Start();	
 	CT_IIC_Send_Byte(GT_CMD_WR);   //发送写命令 	 
	CT_IIC_Wait_Ack();
 	CT_IIC_Send_Byte(reg>>8);   	//发送高8位地址
	CT_IIC_Wait_Ack(); 	 										  		   
 	CT_IIC_Send_Byte(reg&0XFF);   	//发送低8位地址
	CT_IIC_Wait_Ack();  
 	CT_IIC_Start();  	 	   
	CT_IIC_Send_Byte(GT_CMD_RD);   //发送读命令		   
	CT_IIC_Wait_Ack();	   
	for(i=0;i<len;i++)
	{	   
    	buf[i]=CT_IIC_Read_Byte(i==(len-1)?0:1); //发数据	  
	} 
    CT_IIC_Stop();//产生一个停止条件    
} 

/*
* 函数名称： GT911_Init
* 功能描述： 初始化GT911触摸屏
* 传入参数： 无
*   返回值： 0,初始化成功;1,初始化失败
*/
 
uint8_t GT911_Init(void)
{
	
//	uint8_t zancun[190]; /*测试使用*/
//	uint8_t i;
//	uint8_t z;
	
	uint8_t temp[5]; 
//	GPIO_InitTypeDef  GPIO_InitStructure;	
//	
//  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);//使能GPIOB,C时钟

//  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 ;//PB1设置为上拉输入
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;//输入模式
//  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
//  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
//  GPIO_Init(GPIOB, &GPIO_InitStructure);//初始化
//		
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;//PC13设置为推挽输出
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//输出模式
//	GPIO_Init(GPIOB, &GPIO_InitStructure);//初始化	

	
	
	CT_IIC_Init();      	//初始化电容屏的I2C总线  
  //GT_RST=0;//复位
  HAL_GPIO_WritePin(GPIOG, GPIO_PIN_0, GPIO_PIN_RESET);
	HAL_Delay(1);
	//GT_RST=1;//释放复位	
    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_0, GPIO_PIN_SET);
	HAL_Delay(5); 
	

	
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
//  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
//	GPIO_Init(GPIOB, &GPIO_InitStructure);//初始化	
	
	HAL_Delay(10);  
	GT911_RD_Reg(GT_PID_REG,temp,4);//读取产品ID
	temp[4]=0;
	printf("CTP ID:%s\r\n",temp);	//打印ID
	if(strcmp((char*)temp,"911")==0)//ID==9147
	{
		temp[0]=0X02;			
		GT911_WR_Reg(GT_CTRL_REG,temp,1);//软复位GT911
		GT911_RD_Reg(GT_CFGS_REG,temp,1);//读取GT_CFGS_REG寄存器
		
		
		/*可用来读取GT911本地0x8047-0x80FE的寄存器参数*/
/*
		GT911_RD_Reg(GT_CFGS_REG,(uint8_t *)zancun,186);		 //读取出配置寄存器值
		for(i=0;i<186;i++)
		{
		    if(i<185){z+=zancun[i];}
			  if(i==185){printf("校验值1：%x\r\n",z);}
				printf("%x,",zancun[i]);                   //打印出配置寄存器值
		}
*/
		
		if(temp[0]<0X62)//默认版本比较低,需要更新flash配置
		{
			printf("Default Ver:%x\r\n",temp[0]);
			//GT911_Send_Cfg(1);//更新并保存配置
		}
		HAL_Delay(10);
		temp[0]=0X00;	 
		GT911_WR_Reg(GT_CTRL_REG,temp,1);//结束复位   
		return 0;
	} 
	return 0;
}

/*
* 函数名称： GT911_Scan
* 功能描述： 扫描触摸屏(采用查询方式)
* 传入参数： mode:0,正常扫描.
* 传出参数： 无
*   返回值： 当前触屏状态.0,触屏无触摸;1,触屏有触摸
*/
#define SCAN_INTER 1
uint8_t GT911_Scan(uint8_t mode)
{
	uint8_t buf[4]; /*触屏坐标信息存储缓冲区*/
	uint8_t i=0;
	uint8_t res=0;  /*返回触摸状态*/
	uint8_t temp;   
	uint8_t tempsta;  /*保存当前触摸状态*/
 	static uint8_t t=0;//控制查询间隔,从而降低CPU占用率   
	t++;
	
	if((t%SCAN_INTER)==0||t<SCAN_INTER)//空闲时,每进入10次CTP_Scan函数才检测1次,从而节省CPU使用率
	{
		GT911_RD_Reg(GT_GSTID_REG,&mode,1);	//读取触摸点的状态  
		temp=0;
		GT911_WR_Reg(GT_GSTID_REG,&temp,1);//清标志 			
		if((mode&0XF)&&((mode&0XF)<6)) 
		{
			temp=0XFF<<(mode&0XF);		//将点的个数转换为1的位数,匹配tp_dev.sta定义 
			tempsta=tp_dev.sta;			//保存当前的tp_dev.sta值
			tp_dev.sta=(~temp)|TP_PRES_DOWN|TP_CATH_PRES; 
			tp_dev.x[4]=tp_dev.x[0];	//保存触点0的数据
			tp_dev.y[4]=tp_dev.y[0];
			for(i=0;i<1;i++)
			{
				if(tp_dev.sta&(1<<i))	//触摸有效?
				{
					GT911_RD_Reg(GT911_TPX_TBL[i],buf,4);	//读取XY坐标值  
					//tp_dev.y[i]=240-(((uint16_t)buf[1]<<8)+buf[0]);
					tp_dev.y[i]=480 - (((uint16_t)buf[1]<<8)+buf[0]);
					tp_dev.x[i]=((uint16_t)buf[3]<<8)+buf[2];
					printf("x[%d]:%d,y[%d]:%d\r\n",i,tp_dev.x[i],i,tp_dev.y[i]);
				}			
			 } 
			res=1;
			if(tp_dev.x[0]>LCD_W||tp_dev.y[0]>LCD_H)//非法数据(坐标超出了)
			{ 
				if((mode&0XF)>1)		//有其他点有数据,则复第二个触点的数据到第一个触点.
				{
					tp_dev.x[0]=tp_dev.x[1];
					tp_dev.y[0]=tp_dev.y[1];
					t=0;				//触发一次,则会最少连续监测10次,从而提高命中率
				}
				else					//非法数据,则忽略此次数据(还原原来的)  
				{
					tp_dev.x[0]=tp_dev.x[4];
					tp_dev.y[0]=tp_dev.y[4];
					mode=0X80;		
					tp_dev.sta=tempsta;	//恢复tp_dev.sta
				}
			 }
			 else t=0;					//触发一次,则会最少连续监测10次,从而提高命中率
		}
	}
	if((mode&0X8F)==0X80)//无触摸点按下
	{ 
		if(tp_dev.sta&TP_PRES_DOWN)	//之前是被按下的
		{
			tp_dev.sta&=~(1<<7);	//标记按键松开
		}
		tp_dev.x[0]=0xffff;
		tp_dev.y[0]=0xffff;
		tp_dev.sta&=0XE0;	//清除点有效标记	
	} 	
	if(t>240)t=SCAN_INTER;//重新从10开始计数
	return res;
}




 //5个触控点的颜色(电容触摸屏用)												 
const uint16_t POINT_COLOR_TBL[5]={RED,GREEN,BLUE,BROWN,GRED};  

//触摸屏测试程序
void ctp_test(void)
{
	uint8_t i=0;	    
 	uint16_t lastpos[5][2];		//存储每个触摸点的最后一次位置信息
	while(1)
	{
		GT911_Scan(0);
		for(i=0;i<5;i++)    /*遍历五个触摸点*/
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
					LCD_DrawLine(lastpos[i][0],lastpos[i][1],tp_dev.x[i],tp_dev.y[i]);//画线
					lastpos[i][0]=tp_dev.x[i];
					lastpos[i][1]=tp_dev.y[i];
					if(tp_dev.x[i]>(LCD_W-24)&&tp_dev.y[i]<20)
					{
						LCD_Fill(0,0,LCD_W,LCD_H,WHITE);//整屏填充白色，清除画的图
					}
				}
			}else lastpos[i][0]=0XFFFF;
		}
		
		HAL_Delay(5);
	}	
}
