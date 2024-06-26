/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "crc.h"
#include "dcmi.h"
#include "dma.h"
#include "eth.h"
#include "usb_otg.h"
#include "gpio.h"
#include "fmc.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "lcd.h"
#include "ov5640.h"
#include "network.h"
#include "network_data.h"
#include "network_1.h"
#include "network_1_data.h"
#include "utils.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
AI_ALIGNED(32) ai_u8 buf_common[AI_NETWORK_1_DATA_ACTIVATIONS_SIZE];

//AI_ALIGNED(32) ai_u8 activations[AI_NETWORK_DATA_ACTIVATIONS_SIZE];
//AI_ALIGNED(32) ai_u8 activations1[AI_NETWORK_1_DATA_ACTIVATIONS_SIZE];
ai_u8 *activations1 = buf_common;
ai_u8 *activations = buf_common;

/* Data payload*/
static int8_t*in_data=(int8_t*)buf_common;
AI_ALIGNED(32) static float out_data[AI_NETWORK_OUT_1_SIZE];
AI_ALIGNED(32) static int8_t out_data1[AI_NETWORK_1_OUT_1_SIZE];


ai_buffer * ai_input1;
ai_buffer * ai_output1;
ai_handle network1;

ai_buffer * ai_input;
ai_buffer * ai_output;
ai_handle network;
static void AI_Init(void)
{
  ai_error err;
  /* Create a local array with the addresses of the activations buffers */
  const ai_handle act_addr[] = { activations };
  /* Create an instance of the model */
  err = ai_network_create_and_init(&network, act_addr, NULL);
  if (err.type != AI_ERROR_NONE) {
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,1);
  }
  ai_input = ai_network_inputs_get(network, NULL);
  ai_output = ai_network_outputs_get(network, NULL);
	
	
  /* Create an instance of the model */
  err = ai_network_create_and_init(&network1, act_addr, NULL);
  if (err.type != AI_ERROR_NONE) {
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,1);
  }
  ai_input1 = ai_network_inputs_get(network1, NULL);
  ai_output1 = ai_network_outputs_get(network1, NULL);
}
static void AI_Run(const void *pIn, float *pOut)
{
  ai_i32 batch;
  ai_error err;
  /* Update IO handlers with the data payload */
  ai_input[0].data = AI_HANDLE_PTR(pIn);
  ai_output[0].data = AI_HANDLE_PTR(pOut);
  batch = ai_network_run(network, ai_input, ai_output);
  if (batch != 1) {
    err = ai_network_get_error(network);
  }
}

static void AI_Run1(const void *pIn, int8_t *pOut)
{
  ai_i32 batch;
  ai_error err;
  /* Update IO handlers with the data payload */
  ai_input1[0].data = AI_HANDLE_PTR(pIn);
  ai_output1[0].data = AI_HANDLE_PTR(pOut);
  batch = ai_network_run(network1, ai_input, ai_output);
  if (batch != 1) {
    err = ai_network_get_error(network1);
  }
}

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MPU_Config(void);
/* USER CODE BEGIN PFP */
void post_process();


int x1, y1, x2, y2;


uint8_t anchors[5][2] = { {7,15},{20,47},{43,106},{85,168},{185,188}};
//uint16_t img_data[256*256]__attribute__((section(".sram_data2")));//__attribute__((at(0x30020000)));//__attribute__((section(".sram_data2")));
uint16_t isok=0;
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void prepare_yolo_data()
{
	for(int i = 0; i < 256; i++)
	{
		for(int j = 0; j < 256; j++)
		{
			u16 color=LCD_ReadPoint(j,i);
			//img_data[j+i*256] = color;
			in_data[(j+i*256)*3] = (int8_t)((color&0xF800)>>9) - 128;
			in_data[(j+i*256)*3+1] = (int8_t)((color&0x07E0)>>3) - 128;
			in_data[(j+i*256)*3+2] = (int8_t)((color&0x001F)<<3) - 128;
		}
	}
}

static int8_t* temp=(int8_t *)buf_common + AI_NETWORK_1_IN_1_SIZE;
void prepare_facenet_data(u8 x1, u8 y1, u8 x2, u8 y2)
{
	u8 h = y2-y1+1;
	u8 w = x2-x1+1;
	for(int i = 0; i < h; i++)
	{
		for(int j = 0; j < w; j++)
		{
			u16 color=LCD_ReadPoint(j+x1,i+y1);
			//img_data[j+i*256] = color;
			temp[(i*w + j)*3] = (int8_t)((color&0xF800)>>9) - 128;
			temp[(i*w + j)*3+1] = (int8_t)((color&0x07E0)>>3) - 128;
			temp[(i*w + j)*3+2] = (int8_t)((color&0x001F)<<3) - 128;
		}
	}
	cv_resize_s8(temp,h,w,in_data,112,96);
}

void HAL_DCMI_FrameEventCallback(DCMI_HandleTypeDef *hdcmi)
{
	  HAL_DCMI_Stop(hdcmi);
    prepare_yolo_data();
//		HAL_DCMI_Stop(hdcmi);
//		LCD_Fillimg(0,0,55,55,img_data); //0 0 55 55
		isok=1;
//	LCD_SetCursor(0,0);
//	LCD_WriteRAM_Prepare();	
//////	//__HAL_DCMI_ENABLE(&hdcmi);	
//	__HAL_DCMI_ENABLE_IT(hdcmi, DCMI_IT_FRAME);
//	DCMI->CR|=DCMI_CR_CAPTURE;          //DCMI????	
//	HAL_DCMI_Start_DMA(hdcmi, DCMI_MODE_CONTINUOUS, (uint32_t)&(LCD->LCD_RAM), 1);
}
float sigmod(float x)
{
	float y = 1/(1+expf(x));
	return y;
}

void post_process()
{char logStr[100];
	int grid_x, grid_y;
	float x, y, w ,h;
	for(int i = 0; i < 256; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			float conf = out_data[i*30+j*6+4];
			//sprintf(logStr,"%8.6f",conf);
			//LCD_ShowString(10,400,100,16,16,logStr);
			
			if(conf > 1)
			{
				grid_x = i % 16;
				grid_y = (i - grid_x)/16;
				// conf is larger than threshold
//				x = ((float)out_data[i*30+j*6]+32)*0.0625f;
//				y = ((float)out_data[i*30+j*6+1]+32)*0.0625f;
//				w = ((float)out_data[i*30+j*6+2]+32)*0.0625f;
//				h = ((float)out_data[i*30+j*6+3]+32)*0.0625f;
				x = (float)out_data[i*30+j*6];
				y = (float)out_data[i*30+j*6+1];
				w = (float)out_data[i*30+j*6+2];
				h = (float)out_data[i*30+j*6+3];
				x = (sigmod(x)+grid_y) * 16;
				y = (sigmod(y)+grid_x) * 16;
				w = expf(w) * anchors[j][1];
				h = expf(h) * anchors[j][0];
				y2 = (x - w/2);
				y1 = (x + w/2);
				x1 = y - h/2;
				x2 = y + h/2;
				if(x1 < 0) x1 = 0;
				if(y1 < 0) y1 = 0;
				if(x2 > 255) x2 = 255;
				if(y2 > 255) y2 = 255;
				
				if(x1>0&&y1>0&&x2<256&&y2<256)
				{
					LCD_DrawRectangle(x1,y1,x2,y2);
					LCD_ShowString(10,300,100,16,16,"isface"); 
					//LCD_Fill(0,0,256,256,WHITE);
	      	LCD_SetCursor(0,0);
	        LCD_WriteRAM_Prepare();	
					HAL_DCMI_Start_DMA(&hdcmi, DCMI_MODE_CONTINUOUS, (uint32_t)&(LCD->LCD_RAM), 1);
					
					prepare_facenet_data(x1,x2,y1,y2);
					AI_Run1(in_data,out_data1);
					return;
				}
				
				else{
				LCD_ShowString(10,300,200,16,16,"noface"); 
	     	LCD_SetCursor(0,0);
	      LCD_WriteRAM_Prepare();
				HAL_DCMI_Start_DMA(&hdcmi, DCMI_MODE_CONTINUOUS, (uint32_t)&(LCD->LCD_RAM), 1);
					return;
				}
			}
		}
	}
	          LCD_ShowString(10,300,200,16,16,"noface"); 
		      	LCD_SetCursor(0,0);
	        LCD_WriteRAM_Prepare();	 
	HAL_DCMI_Start_DMA(&hdcmi, DCMI_MODE_CONTINUOUS, (uint32_t)&(LCD->LCD_RAM), 1);
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MPU Configuration--------------------------------------------------------*/
  MPU_Config();

  /* Enable the CPU Cache */

  /* Enable I-Cache---------------------------------------------------------*/
  SCB_EnableICache();

  /* Enable D-Cache---------------------------------------------------------*/
  SCB_EnableDCache();

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_CRC_Init();
  MX_DCMI_Init();
  MX_ETH_Init();
  MX_FMC_Init();
  MX_USB_OTG_FS_PCD_Init();
  /* USER CODE BEGIN 2 */
AI_Init();
 LCD_Init();
 HAL_Delay(50);
	while(OV5640_Init())//初始化OV2640
	{
		LCD_ShowString(30,130,240,16,16,"OV5640 ERR");
	}
	LCD_ShowString(30,130,200,16,16,"OV5640 OK"); 
	OV5640_RGB565_Mode();	//RGB565模式 
	OV5640_Focus_Init();
	OV5640_Light_Mode(0);	//自动模式
	OV5640_Color_Saturation(3);//色彩饱和度0
	OV5640_Brightness(4);	//亮度0
	OV5640_Contrast(3);		//对比度0
	OV5640_Sharpness(33);	//自动锐度
	OV5640_Focus_Constant();//启动持续对焦
  LCD_Set_Window(0,0,256,400);
	OV5640_OutSize_Set(16,4,256,256);
		DCMI_Start();
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
		if(isok)
	{
		AI_Run(in_data,out_data);
	  post_process();
		isok=0;
		HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_14);
	}
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Supply configuration update enable
  */
  HAL_PWREx_ConfigSupply(PWR_LDO_SUPPLY);

  /** Configure the main internal regulator output voltage
  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  while(!__HAL_PWR_GET_FLAG(PWR_FLAG_VOSRDY)) {}

  __HAL_RCC_SYSCFG_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE0);

  while(!__HAL_PWR_GET_FLAG(PWR_FLAG_VOSRDY)) {}

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_BYPASS;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 480;
  RCC_OscInitStruct.PLL.PLLP = 2;
  RCC_OscInitStruct.PLL.PLLQ = 20;
  RCC_OscInitStruct.PLL.PLLR = 2;
  RCC_OscInitStruct.PLL.PLLRGE = RCC_PLL1VCIRANGE_1;
  RCC_OscInitStruct.PLL.PLLVCOSEL = RCC_PLL1VCOWIDE;
  RCC_OscInitStruct.PLL.PLLFRACN = 0;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2
                              |RCC_CLOCKTYPE_D3PCLK1|RCC_CLOCKTYPE_D1PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.SYSCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB3CLKDivider = RCC_APB3_DIV2;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_APB1_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_APB2_DIV2;
  RCC_ClkInitStruct.APB4CLKDivider = RCC_APB4_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

 /* MPU Configuration */

void MPU_Config(void)
{
  MPU_Region_InitTypeDef MPU_InitStruct = {0};

  /* Disables the MPU */
  HAL_MPU_Disable();

  /** Initializes and configures the Region and the memory to be protected
  */
  MPU_InitStruct.Enable = MPU_REGION_ENABLE;
  MPU_InitStruct.Number = MPU_REGION_NUMBER0;
  MPU_InitStruct.BaseAddress = 0x6C000000;
  MPU_InitStruct.Size = MPU_REGION_SIZE_64MB;
  MPU_InitStruct.SubRegionDisable = 0x0;
  MPU_InitStruct.TypeExtField = MPU_TEX_LEVEL0;
  MPU_InitStruct.AccessPermission = MPU_REGION_FULL_ACCESS;
  MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_ENABLE;
  MPU_InitStruct.IsShareable = MPU_ACCESS_NOT_SHAREABLE;
  MPU_InitStruct.IsCacheable = MPU_ACCESS_NOT_CACHEABLE;
  MPU_InitStruct.IsBufferable = MPU_ACCESS_NOT_BUFFERABLE;

  HAL_MPU_ConfigRegion(&MPU_InitStruct);
  /* Enables the MPU */
  HAL_MPU_Enable(MPU_PRIVILEGED_DEFAULT);

}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
