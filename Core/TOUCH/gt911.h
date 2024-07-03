#ifndef __GT911_H
#define __GT911_H	
#include "sys.h"	

#include "ctiic.h"
//#include "Serial.h"
//#include "DWT_Delay.h" 
#include "main.h"
#include "string.h" 

#include "lcd.h"
#define TP_PRES_DOWN 0x80  //����������	  
#define TP_CATH_PRES 0x40  //�а��������� 
#define CT_MAX_TOUCH  5    //������֧�ֵĵ���,�̶�Ϊ5��

////������������
//typedef struct
//{
//	uint16_t x[CT_MAX_TOUCH]; 		//��ǰ����
//	uint16_t y[CT_MAX_TOUCH];		//�����������5������,����������x[0],y[0]����:�˴�ɨ��ʱ,����������,��
//								//x[4],y[4]�洢��һ�ΰ���ʱ������. 
//	uint8_t  sta;					//�ʵ�״̬ 
//								//b7:����1/�ɿ�0; 
//	                            //b6:0,û�а�������;1,�а�������. 
//								//b5:����
//								//b4~b0:���ݴ��������µĵ���(0,��ʾδ����,1��ʾ����)
//}_m_tp_dev;

//extern _m_tp_dev tp_dev;	 	//������������touch.c���涨��
//IO��������	 
// #define GT_RST    		PGout(0)	//GT911��λ����
// #define GT_INT    		PFin(8)		//GT911�ж�����	
   	
//I2C��д����	
#define GT_CMD_WR 		0X28     	//д����
#define GT_CMD_RD 		0X29		//������
  
//GT911 ���ּĴ������� 
#define GT_CTRL_REG 	0X8040   	//GT911���ƼĴ���
#define GT_CFGS_REG 	0X8047   	//GT911������ʼ��ַ�Ĵ���
#define GT_CHECK_REG 	0X80FF   	//GT911У��ͼĴ���
#define GT_PID_REG 		0X8140   	//GT911��ƷID�Ĵ���

#define GT_GSTID_REG 	0X814E   	//GT911��ǰ��⵽�Ĵ������
#define GT_TP1_REG 		0X8150  	//��һ�����������ݵ�ַ
#define GT_TP2_REG 		0X8158		//�ڶ������������ݵ�ַ
#define GT_TP3_REG 		0X8160		//���������������ݵ�ַ
#define GT_TP4_REG 		0X8168		//���ĸ����������ݵ�ַ
#define GT_TP5_REG 		0X8170		//��������������ݵ�ַ  
 
void GT911_Send_Cfg(uint8_t mode);                           /*����GT911���ò���*/
uint8_t GT911_WR_Reg(uint16_t reg,uint8_t *buf,uint8_t len); /*��GT911д��һ������*/
void GT911_RD_Reg(uint16_t reg,uint8_t *buf,uint8_t len);    /*��GT911����һ������*/
uint8_t GT911_Init(void);                                    /*��ʼ��GT911������*/
uint8_t GT911_Scan(uint8_t mode);                            /*ɨ�败����(���ò�ѯ��ʽ)*/
void ctp_test(void);
#endif

