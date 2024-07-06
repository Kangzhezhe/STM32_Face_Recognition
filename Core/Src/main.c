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
#include "cmsis_os.h"
#include "crc.h"
#include "dcmi.h"
#include "dma.h"
#include "eth.h"
#include "spi.h"
#include "usart.h"
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
#include "stdio.h"
#include "delay.h"
#include "touch.h"
#include "lv_port_disp.h"
#include "lvgl.h"
#include "lv_port_indev.h"
#include "ui.h"
#include "L610.h"
#include "flash.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
AI_ALIGNED(32) ai_u8 buf_common[AI_NETWORK_1_DATA_ACTIVATIONS_SIZE]__attribute__((section(".RW_IRAM2")));

const ai_handle activations[] = { buf_common };
const ai_handle activations1[] = { buf_common };
/* Data payload*/

static float*in_data=(float*)buf_common;
static int8_t*in_data1=(int8_t*)buf_common;
/* Data payload for the output tensor */
AI_ALIGNED(32)
static float out_data[AI_NETWORK_OUT_1_SIZE]__attribute__((section(".RW_IRAM2")));

AI_ALIGNED(32) 
static int8_t out_data1[AI_NETWORK_1_OUT_1_SIZE]__attribute__((section(".RW_IRAM2")));


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
  
  /* Create an instance of the model */
  err = ai_network_create_and_init(&network, activations, NULL);
  if (err.type != AI_ERROR_NONE) {
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,1);
  }
  ai_input = ai_network_inputs_get(network, NULL);
  ai_output = ai_network_outputs_get(network, NULL);
	
	
  /* Create an instance of the model */
  err = ai_network_1_create_and_init(&network1, activations1, NULL);
  if (err.type != AI_ERROR_NONE) {
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,1);
  }
  ai_input1 = ai_network_1_inputs_get(network1, NULL);
  ai_output1 = ai_network_1_outputs_get(network1, NULL);
	
//	int a,b,c;
//	ai_network_report report;
//	ai_network_report report1;
//	    if (ai_network_get_report(network, &report) != true) {
//				return;
//    }
//			if (ai_network_get_report(network1, &report1) != true) {
//				return;
//    }
//ai_input = &report.inputs[0];
//    ai_output = &report.outputs[0];
//		ai_input1 = &report1.inputs[0];
//    ai_output1 = &report1.outputs[0];
//	 a = AI_BUFFER_SHAPE_ELEM(ai_input1, AI_SHAPE_HEIGHT);
// b = AI_BUFFER_SHAPE_ELEM(ai_input1, AI_SHAPE_WIDTH);
//   c = AI_BUFFER_SHAPE_ELEM(ai_input1, AI_SHAPE_CHANNEL);
//	
//	 a = AI_BUFFER_SHAPE_ELEM(ai_output1, AI_SHAPE_HEIGHT);
// b = AI_BUFFER_SHAPE_ELEM(ai_output1, AI_SHAPE_WIDTH);
//  c = AI_BUFFER_SHAPE_ELEM(ai_output1, AI_SHAPE_CHANNEL);
//	
//	a = AI_BUFFER_SHAPE_ELEM(ai_input, AI_SHAPE_HEIGHT);
// b = AI_BUFFER_SHAPE_ELEM(ai_input, AI_SHAPE_WIDTH);
//  c = AI_BUFFER_SHAPE_ELEM(ai_input, AI_SHAPE_CHANNEL);
//	
//	a = AI_BUFFER_SHAPE_ELEM(ai_output, AI_SHAPE_HEIGHT);
// b = AI_BUFFER_SHAPE_ELEM(ai_output, AI_SHAPE_WIDTH);
//  c = AI_BUFFER_SHAPE_ELEM(ai_output, AI_SHAPE_CHANNEL);
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
 batch = ai_network_run(network1, ai_input1, ai_output1);
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
void MX_FREERTOS_Init(void);
/* USER CODE BEGIN PFP */
void post_process();


// �������������������������?????
int x1, y1, x2, y2;
// yoloface��anchor�ߴ�
uint8_t anchors[3][2] = {{9, 14}, {12, 17}, {22, 21}};


uint16_t img_data[256*256]__attribute__((section(".RAM_D2")));//__attribute__((at(0x30020000)));//__attribute__((section(".sram_data2")));
uint16_t isok=0;

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void prepare_yolo_data()
{
    int8_t* temp = (int8_t*)buf_common + AI_NETWORK_IN_1_SIZE*4;
    int8_t* temp1 = (int8_t*)buf_common + AI_NETWORK_IN_1_SIZE*4+(256*256*3);
	for(int i = 0; i < 256; i++)
	{
		for(int j = 0; j < 256; j++)
		{
			// u16 color=LCD_ReadPoint(j,i);
			u16 color=img_data[i*256+j];
			//img_data[j+i*256] = color;
			temp[(j+i*256)*3] = (int8_t)((color&0xF800)>>8) - 128;
			temp[(j+i*256)*3+1] = (int8_t)((color&0x07E0)>>3) - 128;
			temp[(j+i*256)*3+2] = (int8_t)((color&0x001F)<<3) - 128;
		}
	}
    cv_resize_s8(temp, 256, 256, temp1, 56, 56);
    for (int i = 0; i < AI_NETWORK_IN_1_SIZE; i++)
    {
        in_data[i] = 0.00392157 * ((float)temp1[i] + 128) ;
    }
}


// use   :112 x 96 x 3   H:W:C

// input :3 x 112 x 96   C:H:W

// permute
static int8_t* temp=(int8_t *)buf_common + AI_NETWORK_1_IN_1_SIZE;
void prepare_facenet_data(u8 x1, u8 y1, u8 x2, u8 y2)
{
	u8 h = y2-y1+1; //236
	u8 w = x2-x1+1;	//167
	for(int i = 0; i < h; i++)
	{
		for(int j = 0; j < w; j++)
		{
			// u16 color=LCD_ReadPoint(j+x1,i+y1);
			u16 color=img_data[(j+x1)+(i+y1)*256];
			// img_data[j+i*256] = color;
			temp[(i*w + j)*3] = (int8_t)((color&0xF800)>>8) - 128;
			temp[(i*w + j)*3+1] = (int8_t)((color&0x07E0)>>3) - 128;
			temp[(i*w + j)*3+2] = (int8_t)((color&0x001F)<<3) - 128;
		}
	}
	cv_resize_s8(temp,h,w,in_data1,112,96);
}
#define N 4
const int8_t database[N*128];
double cosine_similarity(int8_t* vec1, int8_t* vec2, int size) {
    double dot_product = 0.0;
    double magnitude1 = 0.0;
    double magnitude2 = 0.0;

    for (int i = 0; i < size; i++) {
        dot_product += vec1[i] * vec2[i];
        magnitude1 += vec1[i] * vec1[i];
        magnitude2 += vec2[i] * vec2[i];
    }

    magnitude1 = sqrt(magnitude1);
    magnitude2 = sqrt(magnitude2);

    if (magnitude1 == 0.0 || magnitude2 == 0.0) {
        return 0.0;
    }

    return dot_product / (magnitude1 * magnitude2);
}
double score[N];
int post_process_facenet(){
	for(int i = 0;i<128;i++){
		out_data1[i] += 10;
	}
    for (int i = 0; i < N; i++)
    {
        score[i] = cosine_similarity(out_data1, database + i * 128, 128);
    }
    int max_index = 0;
    for (int i = 1; i < N; i++)
    {
        if (score[i] > score[max_index])
        {
            max_index = i;
        }
    }
    return max_index;
}

u8 ram_ready = 0;
static lv_obj_t * canvas_cam;
extern osSemaphoreId Sem_lvglHandle;
extern osSemaphoreId Sem_imgbufHandle;
extern osSemaphoreId Sem_stateHandle;
void HAL_DCMI_VsyncEventCallback(DCMI_HandleTypeDef *hdcmi)
{
    
//     HAL_DCMI_Suspend(hdcmi);
// 	  HAL_DCMI_Stop(hdcmi);
//     prepare_yolo_data();
// //		HAL_DCMI_Stop(hdcmi);
// //		LCD_Fillimg(0,0,55,55,img_data); //0 0 55 55
// 		// isok=1;
// //	LCD_SetCursor(0,0);
// //	LCD_WriteRAM_Prepare();	
// //////	//__HAL_DCMI_ENABLE(&hdcmi);	
	
//     ram_ready = 0;
//     LCD_Set_Window(0,0,256,256);
//     // LCD_SetCursor(0,0);
//     LCD_WriteRAM_Prepare();
// //      for (int i = 0; i < 256; i++)
// //      {
// //          for (int j = 0; j < 256; j++)
// //          {
// //              LCD->LCD_RAM=img_data[j+i*256];  
// //          }
// //      }
//    // DCMI_Start();
		 
// 	HAL_DMA_Start_IT(&hdma_memtomem_dma2_stream6, (uint32_t) img_data, (uint32_t) &LCD->LCD_RAM,
// 												 65535);
// 	LCD_WriteRAM_Prepare();
	BaseType_t xHigherPriorityTaskWoken = pdFALSE;	
    // xSemaphoreGiveFromISR(Sem_imgbufHandle ,&xHigherPriorityTaskWoken);
    // portYIELD_FROM_ISR(xHigherPriorityTaskWoken); 

    xHigherPriorityTaskWoken = pdFALSE;
    if(pdTRUE == xSemaphoreTakeFromISR(Sem_lvglHandle,&xHigherPriorityTaskWoken))    
    {
            lv_obj_invalidate(canvas_cam);        
            xSemaphoreGiveFromISR(Sem_lvglHandle ,&xHigherPriorityTaskWoken);
            portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
    }

    // xSemaphoreTakeFromISR(Sem_imgbufHandle,&xHigherPriorityTaskWoken);
}



void TransferComplete(DMA_HandleTypeDef *_hdma)
{
	// LCD_WriteRAM_Prepare();
	// 	LCD_DrawRectangle(10,10,100,100);
    HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_14);
    // DCMI_Start();

    // LCD_Set_Window(0,0,480,800);
    // LCD_SetCursor(0,0);

    // ram_ready = 1;
    
    isok=1;
    
}
float sigmod(float x)
{
	float y = 1/(1+expf(x));
	return y;
}


void lvgl_set_txt(lv_obj_t * label, char * txt){
    if(pdTRUE == xSemaphoreTake(Sem_lvglHandle,portMAX_DELAY))    
    {
        lv_label_set_text(label, txt);
        xSemaphoreGive(Sem_lvglHandle);
    } 
}

u8 get_state();
void set_state(u8 temp);

#define W_SCALE (255/55)
#define H_SCALE (255/55)
uint8_t cnt_detected = 0;
extern u8 ai_state;
extern osThreadId myTask_aiHandle;
char logStr[1024]__attribute__((section(".RW_IRAM1")));
void post_process()
{
	int grid_x, grid_y;
	float x, y, w ,h;
    if(get_state() == 1){
        cnt_detected = 0;
        set_state(2);
    }
	for(int i = 0; i < 49; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			float conf = out_data[i*18+j*6+4];
            // sigmod((conf+15)*0.14218327403068542) < 0.7 ==> conf > -9
            snprintf(logStr,13,"conf = %3.2f",conf);
            // LCD_ShowString(10,350,200,16,16,(u8*)logStr);
			if(conf > 2)
			{
                lvgl_set_txt(ui_Label4, "识别到人脸");
                
                // sprintf(logStr,"%3d",cnt_detected);
                // LCD_ShowString(40,300,100,16,16,logStr); 
                cnt_detected++;
                if(cnt_detected == 5){
                    // LCD_ShowString(100,300,100,16,16,"detected"); 
                    prepare_facenet_data(50,10,216,245);
                    AI_Run1(in_data1,out_data1);
                    int max_index = post_process_facenet();
                    // snprintf(logStr,30,"score[%d] = %4.2f",max_index,score[max_index]);
                    if(pdTRUE == xSemaphoreTake(Sem_lvglHandle,portMAX_DELAY))    
                    {
                        u8 temp_state;
                        if(pdTRUE == xSemaphoreTake(Sem_stateHandle,portMAX_DELAY))    
                        {
                            temp_state = ai_state;
                            xSemaphoreGive(Sem_stateHandle);
                        } 
                        snprintf(logStr,30,"%d",temp_state);
                        lv_label_set_text(ui_Labelid, logStr);
                        if (temp_state == 0)
                        {
                            snprintf(logStr,30,"确认身份!");
                            lv_label_set_text(ui_Label4, logStr);
                            snprintf(logStr,30,"置信度:%4.2f",score[max_index]);
                            lv_label_set_text(ui_Label18, logStr);
                            _ui_flag_modify(ui_Label18, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
                            // snprintf(logStr,30,"%d",max_index);
                            // lv_label_set_text(ui_Labelid, logStr);

                            // TODO 从云端获取数�?
                            // void get data 
                            cnt_detected=0;
                            lv_label_set_text(ui_Label19, "继续");
                            xSemaphoreGive(Sem_lvglHandle);
                        }
                        else if(temp_state==2){
                            snprintf(logStr,30,"录入人脸!");
                            lv_label_set_text(ui_Label4, logStr);
                            cnt_detected=0;
                            lv_label_set_text(ui_Label19, "继续");
                            lv_label_set_text(ui_Label17, "确认");
                            xSemaphoreGive(Sem_lvglHandle);
                            //TODO 录入人脸
                        }
                    } 
                    vTaskSuspend(myTask_aiHandle);
                }
                return;

			}
		}
	}
    if(cnt_detected > 0){
        cnt_detected--;
    }
    lvgl_set_txt(ui_Label4, "检测中...");
    // LCD_ShowString(10,300,200,16,16,"noface"); 
		      	// DCMI_Start();
}

struct __FILE
{
        int handle;
};
FILE __stdout;
int fputc(int ch, FILE *f)
{
    HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, 0xFFFF);//����ʵ�������������?????
    return (ch);
}

//lvgl test
static lv_obj_t * label;

static void slider_event_cb(lv_event_t * e)
{
    lv_obj_t * slider = lv_event_get_target(e);

    /*Refresh the text*/
    lv_label_set_text_fmt(label, "%"LV_PRId32, lv_slider_get_value(slider));
    lv_obj_align_to(label, slider, LV_ALIGN_OUT_TOP_MID, 0, -15);    /*Align top of the slider*/
}

/**
 * Create a slider and write its value on a label.
 */
void lv_example_get_started_1(void)
{
    /*Create a slider in the center of the display*/
    lv_obj_t * slider = lv_slider_create(lv_screen_active());
    lv_obj_set_width(slider, 200);                          /*Set the width*/
    lv_obj_center(slider);                                  /*Align to the center of the parent (screen)*/
    lv_obj_add_event_cb(slider, slider_event_cb, LV_EVENT_VALUE_CHANGED, NULL);     /*Assign an event function*/

    /*Create a label above the slider*/
    label = lv_label_create(lv_screen_active());
    lv_label_set_text(label, "0");
    lv_obj_align_to(label, slider, LV_ALIGN_OUT_TOP_MID, 0, -15);    /*Align top of the slider*/
}

extern lv_obj_t * ui_Container1;
void lv_cam_canvas(void){
    // ��������
    canvas_cam = lv_canvas_create(ui_Container1);
    lv_canvas_set_buffer(canvas_cam, img_data, 256, 256, LV_COLOR_FORMAT_RGB565);
    lv_canvas_fill_bg(canvas_cam, lv_color_hex(0x000000), 255);
    lv_obj_set_align(canvas_cam, LV_ALIGN_CENTER);
    // lv_obj_set_pos(canvas_cam, 0, 0);

    lv_obj_set_size(canvas_cam, 256, 256);
    lv_obj_set_scrollbar_mode(canvas_cam, LV_SCROLLBAR_MODE_OFF);

    lv_obj_set_style_shadow_color(canvas_cam, lv_color_hex(0x2EC1D3), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(canvas_cam, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(canvas_cam, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(canvas_cam, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
}

void process_ai(void){
    prepare_yolo_data();
    AI_Run(in_data,out_data);
	post_process();
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
  MX_USART1_UART_Init();
  MX_SPI1_Init();
  /* USER CODE BEGIN 2 */
  delay_init();
	 HAL_DMA_RegisterCallback(&hdma_memtomem_dma2_stream6,HAL_DMA_XFER_CPLT_CB_ID,TransferComplete);
	AI_Init();
    // HAL_UART_Receive_IT(&huart1,&Res,1);
 LCD_Init();
 HAL_Delay(50);
	while(OV5640_Init())//��ʼ��OV2640
	{
		LCD_ShowString(30,130,240,16,16,"OV5640 ERR");
	}
	LCD_ShowString(30,130,200,16,16,"OV5640 OK"); 
	OV5640_RGB565_Mode();	//RGB565ģʽ 
	OV5640_Focus_Init();
	OV5640_Light_Mode(0);	//�Զ�ģʽ
	OV5640_Color_Saturation(3);//ɫ�ʱ��Ͷ�0
	OV5640_Brightness(4);	//����0
	OV5640_Contrast(3);		//�Աȶ�0
	OV5640_Sharpness(33);	//�Զ����?????????
	OV5640_Focus_Constant();//���������Խ�
//   LCD_Set_Window(0,0,256,400);
	OV5640_OutSize_Set(16,4,256,256);

		// DCMI_Start();
    // L610_test();
    TP_Init();
	LCD_Clear(WHITE);//����
	// InternalFlash_Test();
    
  
	
  /* USER CODE END 2 */

  /* Call init function for freertos objects (in cmsis_os2.c) */
  MX_FREERTOS_Init();

  /* Start scheduler */
  osKernelStart();

  /* We should never get here as control is now taken by the scheduler */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    // if(isok){
    //     LCD_DrawRectangle(50,10,216,245);
    //     AI_Run(in_data,out_data);
    //     post_process();
    //     DCMI_Start();
    //     isok = 0;
    // }
    // printf("hello\r\n");
    //tp_dev.scan(0);
		lv_timer_handler();
    HAL_Delay(1);
		lv_tick_inc(5);
	// 	if(isok)
	// {
	// 	AI_Run(in_data,out_data);
	//   post_process();
	// 	isok=0;
	// 	HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_14);
	// }
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

const int8_t database[N*128]={
-22,-6,-44,-21,-8,6,-7,-8,66,20,-20,-13,12,20,4,-20,44,-9,-12,-35,14,-9,-12,-11,-32,-23,-15,-10,6,9,4,-13,22,3,43,41,-67,3,15,-12,1,33,-4,-8,-3,-10,9,-37,-1,-5,-16,3,2,-63,4,0,10,35,-14,10,-2,-48,-48,-26,37,47,3,-26,38,11,6,3,7,44,-16,2,21,23,8,-25,-29,-36,3,2,-29,-5,19,-8,-5,-11,-23,19,-32,18,21,39,13,-32,43,-41,-4,1,-14,12,18,17,-10,8,37,-7,-25,20,41,-32,16,-8,16,-28,35,26,29,8,-25,43,2,-13,-9,-13,
-5,24,15,47,11,-3,-18,12,37,-32,6,20,3,-20,-5,37,-22,-17,31,19,56,-4,33,30,-4,27,-23,-6,14,22,27,-63,53,-20,9,8,18,-36,4,9,-10,-8,26,-28,9,-6,15,42,-20,9,7,-12,17,15,8,-38,-7,28,-24,-23,22,9,-10,-20,5,30,9,-24,-12,-2,-12,-38,1,-24,-35,3,38,-33,2,38,9,9,35,-2,4,4,13,13,21,-11,41,30,26,21,8,28,20,-50,-6,-4,-5,-6,-25,19,4,-3,-4,11,5,-31,-6,31,20,-9,-1,19,-16,-33,-19,-20,-27,5,27,-19,21,29,7,-3,
59,30,-6,0,-1,6,2,-11,-17,-32,-22,-8,10,-5,-4,-41,-24,45,35,-3,0,1,12,-49,-14,7,-9,-19,-6,30,47,8,-3,-19,21,17,28,-7,16,5,-10,-27,24,18,-9,-10,2,1,15,24,16,-2,4,-20,8,-16,28,-35,9,47,10,14,1,15,33,-8,30,15,0,22,-3,49,-17,-28,-3,18,31,-17,-32,24,5,-8,8,-2,1,-22,10,-3,25,48,14,2,0,17,15,2,44,21,-25,-12,11,12,-9,-34,32,-11,-10,0,-27,-6,16,-1,0,1,0,14,-1,31,24,-1,-23,1,-14,6,46,54,-51,-3,
18,-5,10,14,-7,-32,1,-1,14,-41,-2,73,-9,27,12,-19,-1,-18,-10,2,-25,0,27,-47,-5,-3,-9,-18,-59,48,-6,-23,32,-12,2,15,-1,-15,-2,22,11,-10,9,-30,9,-10,-19,-17,0,9,-14,-8,-21,5,-10,13,10,-17,35,5,12,-27,-23,-7,16,-15,3,19,10,-16,-22,18,14,23,-4,30,37,-44,-36,2,18,-3,43,14,6,-35,20,-1,6,23,0,19,-20,-19,-6,-5,24,-8,1,0,14,7,-56,-6,75,21,-19,3,6,11,3,7,1,11,-5,37,3,-9,26,39,-9,23,0,5,18,3,14,-5

};

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
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM6 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM6) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
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
