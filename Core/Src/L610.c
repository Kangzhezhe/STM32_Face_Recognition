#include "L610.h"
#include "string.h"
#include "usart.h"
#include "stdio.h"


char *strx,*extstrx,*Readystrx;
char RxBuffer[10240];
int	Rxcouter;

uint8_t Res;

void Clear_Buffer(void)
{
    for(int i=0;i<Rxcouter;i++)
    RxBuffer[i]=0;
    Rxcouter=0;
}

void L610_test(void){
    
	Clear_Buffer();
	while(strx==NULL){
		printf("ATI\r\n");
		HAL_Delay(1000);
		strx=strstr((const char*)RxBuffer,(const char*)"Fibocom");
		Clear_Buffer();
	}
//	if(strx==NULL)
//	{
//	Clear_Buffer();
//	// printf("Fall\r\n");
//	// HAL_Delay(1000);
//	}
//	else
//	{
//	Clear_Buffer();
//	 //printf("Success\r\n");
//	// HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_13);
//	// HAL_Delay(1000);
//	}
    printf("AT+MIPCALL=1\r\n");
	HAL_Delay(1000);
	strx=strstr((const char*)RxBuffer,(const char*)"+MIPCALL:");
	HAL_Delay(1000);
	printf("AT+HMCON=0,60,\"0e7d1fdca6.st1.iotda-device.cn-east-3.myhuaweicloud.com\",\"1883\",\"6685084786799a26c45e16f9_L610\",\"Dky200361\",0\r\n");
	HAL_Delay(1000);
//	printf("AT+HMPUB=1,\"$oc/devices/6685084786799a26c45e16f9_L610/sys/properties/report\",59,\"{\\\"services\\\":[{\\\"service_id\\\":\\\"1\\\",\\\"properties\\\":{\\\"faceid\\\":%d}}]}\"\r\n",1);
//	HAL_Delay(1000);
//	printf("AT+HMPUB=1,\"$oc/devices/6685084786799a26c45e16f9_L610/sys/properties/report\",62,\"{\\\"services\\\":[{\\\"service_id\\\":\\\"1\\\",\\\"properties\\\":{\\\"name\\\":1233}}]}\"\r\n");
	printf("AT+HMSUB=0,\"/test/M2M/hh/#\"\r\n");
	HAL_Delay(1000);
	//printf("AT+HMPUB=1,\"/test/M2M/aa\",39,\"faceid:2,tiwen:53.6,xueyang:79,xinlv:23\"\r\n");
	//printf("AT+HMPUB=1,\"/test/M2M/aa\",8,\"faceid:1\"\r\n");
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) 
{ 
 UNUSED(huart); 
 
 if(huart->Instance ==USART1){ 
 RxBuffer[Rxcouter++] = Res; 
 HAL_UART_Receive_IT(&huart1, (uint8_t *)&Res, 1); 
 } 
}