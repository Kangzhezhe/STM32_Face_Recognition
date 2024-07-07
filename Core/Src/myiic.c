#include "myiic.h"
#include "delay.h"


//��ʼ��IIC
void IIC_Init(void)
{					     
	// GPIO_InitTypeDef GPIO_InitStructure;
	// //RCC->APB2ENR|=1<<4;//��ʹ������IO PORTCʱ�� 
	// RCC_APB2PeriphClockCmd(	RCC_APB2Periph_GPIOB, ENABLE );	
	   
	// GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7|GPIO_Pin_8;
	// GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP ;   //�������
	// GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	// GPIO_Init(GPIOB, &GPIO_InitStructure);
 
	HAL_GPIO_WritePin(MAX30102_SCL_GPIO_Port, MAX30102_SCL_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(MAX30102_SDA_GPIO_Port, MAX30102_SDA_Pin, GPIO_PIN_SET);

}
//����IIC��ʼ�ź�
void IIC_Start(void)
{
	SDA_OUT();     //sda�����
	HAL_GPIO_WritePin(MAX30102_SDA_GPIO_Port, MAX30102_SDA_Pin, GPIO_PIN_SET);	  	  
	HAL_GPIO_WritePin(MAX30102_SCL_GPIO_Port, MAX30102_SCL_Pin, GPIO_PIN_SET);
	delay_us(4);
 	HAL_GPIO_WritePin(MAX30102_SDA_GPIO_Port, MAX30102_SDA_Pin, GPIO_PIN_RESET);//START:when CLK is high,DATA change form high to low 
	delay_us(4);
	HAL_GPIO_WritePin(MAX30102_SCL_GPIO_Port, MAX30102_SCL_Pin, GPIO_PIN_RESET);//ǯסI2C���ߣ�׼�����ͻ�������� 
}	  
//����IICֹͣ�ź�
void IIC_Stop(void)
{
	SDA_OUT();//sda�����
	HAL_GPIO_WritePin(MAX30102_SCL_GPIO_Port, MAX30102_SCL_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(MAX30102_SDA_GPIO_Port, MAX30102_SDA_Pin, GPIO_PIN_RESET);//STOP:when CLK is high DATA change form low to high
 	delay_us(4);
	HAL_GPIO_WritePin(MAX30102_SCL_GPIO_Port, MAX30102_SCL_Pin, GPIO_PIN_SET); 
	HAL_GPIO_WritePin(MAX30102_SDA_GPIO_Port, MAX30102_SDA_Pin, GPIO_PIN_SET);//����I2C���߽����ź�
	delay_us(4);							   	
}
//�ȴ�Ӧ���źŵ���
//����ֵ��1������Ӧ��ʧ��
//        0������Ӧ��ɹ�
u8 IIC_Wait_Ack(void)
{
	u8 ucErrTime=0;
	SDA_IN();      //SDA����Ϊ����  
	HAL_GPIO_WritePin(MAX30102_SDA_GPIO_Port, MAX30102_SDA_Pin, GPIO_PIN_SET);delay_us(1);	   
	HAL_GPIO_WritePin(MAX30102_SCL_GPIO_Port, MAX30102_SCL_Pin, GPIO_PIN_SET);delay_us(1);	 
	while( HAL_GPIO_ReadPin(MAX30102_SDA_GPIO_Port, MAX30102_SDA_Pin))
	{
		ucErrTime++;
		if(ucErrTime>250)
		{
			IIC_Stop();
			return 1;
		}
	}
	HAL_GPIO_WritePin(MAX30102_SCL_GPIO_Port, MAX30102_SCL_Pin, GPIO_PIN_RESET);//ʱ�����0 	   
	return 0;  
} 
//����ACKӦ��
void IIC_Ack(void)
{
	HAL_GPIO_WritePin(MAX30102_SCL_GPIO_Port, MAX30102_SCL_Pin, GPIO_PIN_RESET);
	SDA_OUT();
	HAL_GPIO_WritePin(MAX30102_SDA_GPIO_Port, MAX30102_SDA_Pin, GPIO_PIN_RESET);
	delay_us(2);
	HAL_GPIO_WritePin(MAX30102_SCL_GPIO_Port, MAX30102_SCL_Pin, GPIO_PIN_SET);
	delay_us(2);
	HAL_GPIO_WritePin(MAX30102_SCL_GPIO_Port, MAX30102_SCL_Pin, GPIO_PIN_RESET);
}
//������ACKӦ��		    
void IIC_NAck(void)
{
	HAL_GPIO_WritePin(MAX30102_SCL_GPIO_Port, MAX30102_SCL_Pin, GPIO_PIN_RESET);
	SDA_OUT();
	HAL_GPIO_WritePin(MAX30102_SDA_GPIO_Port, MAX30102_SDA_Pin, GPIO_PIN_SET);
	delay_us(2);
	HAL_GPIO_WritePin(MAX30102_SCL_GPIO_Port, MAX30102_SCL_Pin, GPIO_PIN_SET);
	delay_us(2);
	HAL_GPIO_WritePin(MAX30102_SCL_GPIO_Port, MAX30102_SCL_Pin, GPIO_PIN_RESET);
}					 				     
//IIC����һ���ֽ�
//���شӻ�����Ӧ��
//1����Ӧ��
//0����Ӧ��			  
void IIC_Send_Byte(u8 txd)
{                        
    u8 t;   
	SDA_OUT(); 	    
    HAL_GPIO_WritePin(MAX30102_SCL_GPIO_Port, MAX30102_SCL_Pin, GPIO_PIN_RESET);//����ʱ�ӿ�ʼ���ݴ���
    for(t=0;t<8;t++)
    {              
        HAL_GPIO_WritePin(MAX30102_SDA_GPIO_Port, MAX30102_SDA_Pin, (GPIO_PinState)((txd&0x80)>>7));
        txd<<=1; 	  
		delay_us(2);   //��TEA5767��������ʱ���Ǳ����
		HAL_GPIO_WritePin(MAX30102_SCL_GPIO_Port, MAX30102_SCL_Pin, GPIO_PIN_SET);
		delay_us(2); 
		HAL_GPIO_WritePin(MAX30102_SCL_GPIO_Port, MAX30102_SCL_Pin, GPIO_PIN_RESET);	
		delay_us(2);
    }	 
} 	    
//��1���ֽڣ�ack=1ʱ������ACK��ack=0������nACK   
u8 IIC_Read_Byte(unsigned char ack)
{
	unsigned char i,receive=0;
	SDA_IN();//SDA����Ϊ����
    for(i=0;i<8;i++ )
	{
        HAL_GPIO_WritePin(MAX30102_SCL_GPIO_Port, MAX30102_SCL_Pin, GPIO_PIN_RESET); 
        delay_us(2);
		HAL_GPIO_WritePin(MAX30102_SCL_GPIO_Port, MAX30102_SCL_Pin, GPIO_PIN_SET);
        receive<<=1;
        if( HAL_GPIO_ReadPin(MAX30102_SDA_GPIO_Port, MAX30102_SDA_Pin))receive++;   
		delay_us(1); 
    }					 
    if (!ack)
        IIC_NAck();//����nACK
    else
        IIC_Ack(); //����ACK   
    return receive;
}


void IIC_WriteBytes(u8 WriteAddr,u8* data,u8 dataLength)
{		
	u8 i;	
    IIC_Start();  

	IIC_Send_Byte(WriteAddr);	    //����д����
	IIC_Wait_Ack();
	
	for(i=0;i<dataLength;i++)
	{
		IIC_Send_Byte(data[i]);
		IIC_Wait_Ack();
	}				    	   
    IIC_Stop();//����һ��ֹͣ���� 
	delay_ms(10);	 
}

void IIC_ReadBytes(u8 deviceAddr, u8 writeAddr,u8* data,u8 dataLength)
{		
	u8 i;	
    IIC_Start();  

	IIC_Send_Byte(deviceAddr);	    //����д����
	IIC_Wait_Ack();
	IIC_Send_Byte(writeAddr);
	IIC_Wait_Ack();
	IIC_Send_Byte(deviceAddr|0X01);//�������ģʽ			   
	IIC_Wait_Ack();
	
	for(i=0;i<dataLength-1;i++)
	{
		data[i] = IIC_Read_Byte(1);
	}		
	data[dataLength-1] = IIC_Read_Byte(0);	
    IIC_Stop();//����һ��ֹͣ���� 
	delay_ms(10);	 
}

void IIC_Read_One_Byte(u8 daddr,u8 addr,u8* data)
{				  	  	    																 
    IIC_Start();  
	
	IIC_Send_Byte(daddr);	   //����д����
	IIC_Wait_Ack();
	IIC_Send_Byte(addr);//���͵�ַ
	IIC_Wait_Ack();		 
	IIC_Start();  	 	   
	IIC_Send_Byte(daddr|0X01);//�������ģʽ			   
	IIC_Wait_Ack();	 
    *data = IIC_Read_Byte(0);		   
    IIC_Stop();//����һ��ֹͣ����	    
}

void IIC_Write_One_Byte(u8 daddr,u8 addr,u8 data)
{				   	  	    																 
    IIC_Start();  
	
	IIC_Send_Byte(daddr);	    //����д����
	IIC_Wait_Ack();
	IIC_Send_Byte(addr);//���͵�ַ
	IIC_Wait_Ack();	   	 										  		   
	IIC_Send_Byte(data);     //�����ֽ�							   
	IIC_Wait_Ack();  		    	   
    IIC_Stop();//����һ��ֹͣ���� 
	delay_ms(10);	 
}



























