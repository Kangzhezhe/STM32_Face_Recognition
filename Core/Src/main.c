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
#include "stdlib.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
// 公共缓冲区
AI_ALIGNED(32) ai_u8 buf_common[AI_NETWORK_1_DATA_ACTIVATIONS_SIZE]__attribute__((section(".RW_IRAM2")));

// 激活层
const ai_handle activations[] = { buf_common };
const ai_handle activations1[] = { buf_common };

// 输入缓冲区
static float*in_data=(float*)buf_common;
static int8_t*in_data1=(int8_t*)buf_common;

// 输出缓冲区
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


// �������������������������???????
int x1, y1, x2, y2;
// yoloface��anchor�ߴ�
uint8_t anchors[3][2] = {{9, 14}, {12, 17}, {22, 21}};


uint16_t img_data[256*256]__attribute__((section(".RAM_D2")));//__attribute__((at(0x30020000)));//__attribute__((section(".sram_data2")));
uint16_t isok=0;

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
u8 get_state();
void set_state(u8 temp);

typedef struct 
{
    int32_t id;
    u8* feature;
    char name[16];
    char sex[16];
    char age[16];
    char judge[16];
    char yijian[1024];
    char yao[1024];
}Persion;

Persion cur_persion;

#define MAX_FEATURE_SIZE 128*512
#define FEATURE_PER_PERSION 4
#define MAX_ID 128
#define W_SCALE (255/55)
#define H_SCALE (255/55)
uint8_t cnt_detected = 0;
extern u8 ai_state;
extern osThreadId myTask_aiHandle;
char logStr[1024]__attribute__((section(".RW_IRAM1")));
static int i_feature = 0;
u8 features_buf[MAX_FEATURE_SIZE]__attribute__((section(".RAM_D3")));
u8* get_feature_ptr(int id){
    return  (u8*)features_buf + id*FEATURE_PER_PERSION*128;
}

int32_t* get_cnt_ptr(){
    return (int32_t*)((u8*)features_buf + MAX_FEATURE_SIZE-4);
}

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
extern int hist[256];
static uint8_t* temp=(uint8_t *)buf_common + AI_NETWORK_1_IN_1_SIZE;
static u8* img=(u8 *)buf_common + AI_NETWORK_1_IN_1_SIZE + 236*167*3;
static float* hsv_img=(float*)((u8 *)buf_common + AI_NETWORK_1_IN_1_SIZE + 236*167*3 + 112*96*3);
void prepare_facenet_data(u8 x1, u8 y1, u8 x2, u8 y2)
{
    //s8 in_data1[112,96,3], u8 temp[h,w,3],u8 img[112,96,3], float hsv_img[112,96,3]
	u8 h = y2-y1+1; //236
	u8 w = x2-x1+1;	//167
	
	for(int i = 0; i < h; i++)
	{
		for(int j = 0; j < w; j++)
		{
			// u16 color=LCD_ReadPoint(j+x1,i+y1);
			u16 color=img_data[(j+x1)+(i+y1)*256];
			// img_data[j+i*256] = color;
			temp[(i*w + j)*3] = (u8)((color&0xF800)>>8);
			temp[(i*w + j)*3+1] = (u8)((color&0x07E0)>>3) ;
			temp[(i*w + j)*3+2] = (u8)((color&0x001F)<<3) ;
//			temp[(i*w + j)*3] = (color >> 11) & 0x1F;
//      temp[(i*w + j)*3+1] = (color >> 5) & 0x3F;
//      temp[(i*w + j)*3+2] = color & 0x1F;
		}
	}
    cv_resize_u8(temp,h,w,img,112,96);
    for (int i = 0; i < 256; i++)
    {
        hist[i] = 0;
    }
    // cv_enhanceImageUsingHSV(img,112,96,hsv_img,img);
    cv_lightEnhanceImageUsingHSV(img,112,96,hsv_img,img);
    cv_U82S8(img,in_data1,112,96);
	// cv_resize_s8(temp,h,w,in_data1,112,96);
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

double score[MAX_ID];
int max_num = 25;
typedef struct {
    int index;
    double score;
} IndexScore;

int compareIndexScore(const void *a, const void *b) {
    IndexScore *ia = (IndexScore *)a;
    IndexScore *ib = (IndexScore *)b;
    return (ib->score - ia->score > 0) - (ib->score - ia->score < 0);
}
// int post_process_facenet(int *second_max_index){
// 	for(int i = 0;i<128;i++){
// 		out_data1[i] += 10;
// 	}
//     for (int i = 0; i < max_num; i++)
//     {
//         // score[i] = cosine_similarity(out_data1, database + i * 128, 128);
//         score[i]=0;
//         u8* featrues = get_feature_ptr(i);
//         for (int j = 0; j < FEATURE_PER_PERSION; j++)
//         {
//             score[i] += cosine_similarity(out_data1, featrues + j * 128, 128);
//         }
//         score[i]/=FEATURE_PER_PERSION;
//     }

//     int max_index = 0;
//     for (int i = 1; i < max_num; i++)
//     {
//         if (score[i] > score[max_index])
//         {
//             *second_max_index = max_index;
//             max_index = i;
//         } else if (*second_max_index == -1 || score[i] > score[*second_max_index]) {
//             *second_max_index = i;
//         }
//     }
//     return max_index;
// }

// 冒泡排序函数
void bubble_sort(IndexScore * scores, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (scores[j].score < scores[j + 1].score) {
                // 交换 scores
                IndexScore temp_score = scores[j];
                scores[j] = scores[j + 1];
                scores[j + 1] = temp_score;
            }
        }
    }
}

#define K 5
static IndexScore *indexScores = (IndexScore*) buf_common ;
int topKIndices[K];
int voteCount[MAX_ID] = {0};
int post_process_facenet(int *second_max_index) {
    for (int i = 0; i < 128; i++) {
        out_data1[i] += 10;
    }

    for (int i = 0; i < max_num; i++) {
        score[i] = 0;
        u8 *features = get_feature_ptr(i);
        for (int j = 0; j < FEATURE_PER_PERSION; j++) {
            indexScores[i*FEATURE_PER_PERSION+j].score = cosine_similarity(out_data1, features + j * 128, 128);
            indexScores[i*FEATURE_PER_PERSION+j].index = i;
            score[i] +=  indexScores[i*FEATURE_PER_PERSION+j].score ;
        }
        score[i] /= FEATURE_PER_PERSION;
    }

    // for (int i = 0; i < max_num; i++) {
    //     indexScores[i].index = i;
    //     indexScores[i].score = score[i];
    // }

    // qsort(indexScores, max_num, sizeof(IndexScore), compareIndexScore);
    // bubble_sort(indexScores,max_num);
    for (int i = 0; i < max_num *FEATURE_PER_PERSION- 1; i++) {
        for (int j = 0; j < max_num *FEATURE_PER_PERSION- i - 1; j++) {
            if (indexScores[j].score < indexScores[j + 1].score) {
                IndexScore temp_score = indexScores[j];
                indexScores[j] = indexScores[j + 1];
                indexScores[j + 1] = temp_score;
            }
        }
    }

    for (int i = 0; i < K; i++) {
        topKIndices[i] = indexScores[i].index;
    }

    for (int i = 0; i < MAX_ID; i++)
    {
        voteCount[i] = 0;
    }
    

    for (int i = 0; i < K; i++) {
        voteCount[topKIndices[i]]++;
    }

    int max_votes_index = 0;
    for (int i = 1; i < max_num; i++) {
        if (voteCount[i] > voteCount[max_votes_index]) {
            max_votes_index = i;
        }
    }

    *second_max_index = -1;
    for (int i = 0; i < max_num; i++) {
        if (i != max_votes_index && (*second_max_index == -1 || voteCount[i] > voteCount[*second_max_index])) {
            *second_max_index = i;
        }
    }
    snprintf(logStr,30,"%d",voteCount[*second_max_index]);
    lv_label_set_text(ui_Labeljudge,logStr );
    snprintf(logStr,30,"%d",voteCount[max_votes_index]);
    lv_label_set_text(ui_Labelage,logStr );
    return max_votes_index;
}

u8 ram_ready = 0;
static lv_obj_t * canvas_cam;
extern osSemaphoreId Sem_lvglHandle;
extern osSemaphoreId Sem_imgbufHandle;
extern osSemaphoreId Sem_stateHandle;
extern osThreadId myTask_measureHandle;
void HAL_DCMI_FrameEventCallback(DCMI_HandleTypeDef *hdcmi)
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

void parseAndGetValue(char *buffer, char *keyword, char *result) {
    char *q = strstr(buffer, keyword);
    if (q != NULL) {
        char *start = strchr(q, ':') + 1;
        char *end = strchr(start, ',');
        if (end == NULL) {
            end = strchr(start, '\"');
            if (end == NULL) {
                end = strchr(start, '\0');
            }
        }
        int length = end - start;
        strncpy(result, start, length);
        result[length] = '\0';
    } else {
        result[0] = '\0'; // Set result to empty string if keyword not found
    }
}

extern char RxBuffer[10240];
extern int	Rxcouter;
void Clear_Buffer(void);
extern lv_obj_t* table;
extern lv_obj_t* table1;
void update_info(void){
    // TODO 从云端获取数�???
    snprintf(logStr,30,"正在连接云端");
    lv_label_set_text(ui_Label4, logStr);
    xSemaphoreGive(Sem_lvglHandle);

    Clear_Buffer();
    // printf("AT+HMPUB=1,\"$oc/devices/6685084786799a26c45e16f9_L610/sys/properties/report\",59,\"{\\\"services\\\":[{\\\"service_id\\\":\\\"%d\\\",\\\"properties\\\":{\\\"faceid\\\":%d}}]}\"\r\n",cur_persion.id+1,cur_persion.id+1);
    HAL_Delay(1000);
    Clear_Buffer();
    char std[1024];
    snprintf(std,1024,"faceid:%d",cur_persion.id+1);
    int length = strlen(std);
    printf("AT+HMPUB=1,\"/test/M2M/aa\",%d,\"%s\"\r\n",length,std);
    // printf("AT+HMPUB=1,\"/test/M2M/aa\",8,\"faceid:%d\"\r\n",cur_persion.id+1);
    HAL_Delay(1000);
    strx = strstr((char*)&RxBuffer[0], "test/M2M/hh");
    
    while (strx==NULL)
    {
        Clear_Buffer();
        // printf("AT+HMPUB=1,\"/test/M2M/aa\",8,\"faceid:%d\"\r\n",cur_persion.id+1);
        snprintf(std,1024,"faceid:%d",cur_persion.id+1);
        int length = strlen(std);
        printf("AT+HMPUB=1,\"/test/M2M/aa\",%d,\"%s\"\r\n",length,std);
        HAL_Delay(1000);
        strx = strstr((char*)&RxBuffer[0], "test/M2M/hh");
    }
    xSemaphoreTake(Sem_lvglHandle,portMAX_DELAY);
    
    char *record = strtok(RxBuffer, ";");
    parseAndGetValue(record,"xingming",cur_persion.name);
    parseAndGetValue(record,"xingbie",cur_persion.sex);
    parseAndGetValue(record,"nianling",cur_persion.age);
    parseAndGetValue(record,"zhengduan",cur_persion.judge);
    parseAndGetValue(record,"yijian",cur_persion.yijian);
    parseAndGetValue(record,"yao",cur_persion.yao);

    lv_table_set_row_cnt(table, 1);
    lv_table_set_row_cnt(table1, 1);
    int row = 1;
    record = strtok(NULL, ";");
    while (record != NULL&&record[0] != '\"') {
        char tiwen[10], xueyang[10], xinlv[10], time[20];
        
        parseAndGetValue(record, "tiwen", tiwen);
        parseAndGetValue(record, "xueyang", xueyang);
        parseAndGetValue(record, "xinlv", xinlv);
        parseAndGetValue(record, "time", time);

        if (tiwen[0] == '\0' || xueyang[0] == '\0' || xinlv[0] == '\0') {
            break;
        }
        
        // 填充表格数据
        int month, day, hour, minute;
        sscanf(time, "%d %d %d %d", &month, &day, &hour, &minute);
        
        lv_table_set_cell_value_fmt(table, row, 0, "%d月%d日 %02d:%02d", month, day, hour, minute);
        lv_table_set_cell_value_fmt(table, row, 1, "%s", tiwen);
        lv_table_set_cell_value_fmt(table, row, 2, "%s", xinlv);
        lv_table_set_cell_value_fmt(table, row, 3, "%s", xueyang);
        
        row++;
        record = strtok(NULL, ";");
    }

    row = 1;
    //record = strtok(NULL, ";");
    while (record != NULL&&record[0] != '\"') {
        char yao[20], time[20];
        
        parseAndGetValue(record, "yao", yao);
        parseAndGetValue(record, "time", time);

        if (yao[0] == '\0') {
            break;
        }
        // 填充表格数据
        int month, day, hour, minute;
        sscanf(time, "%d %d %d %d", &month, &day, &hour, &minute);
        
        lv_table_set_cell_value_fmt(table1, row, 0, "%d月%d日 %02d:%02d", month, day, hour, minute);
        lv_table_set_cell_value_fmt(table1, row, 1, "%s", yao);
        
        row++;
        record = strtok(NULL, ";");
    }

    snprintf(logStr,30,"连接成功");
    lv_label_set_text(ui_Label4, logStr);
    lv_label_set_text(ui_Labelname, cur_persion.name);
    lv_label_set_text(ui_Labelsex, cur_persion.sex);
    lv_label_set_text(ui_Labelage, cur_persion.age);
    lv_label_set_text(ui_Labeljudge, cur_persion.judge);
    lv_textarea_set_text(ui_TextArea2, cur_persion.yijian);

    logStr[0] = '\0';
    record = strtok(cur_persion.yao, " ");
    while (record != NULL&&record[0] != '\"') {
        // char yao[20],freq[20];

        // sscanf(record, "%d %d", &yao, &freq);
				
        strncat(logStr,record,strlen(record));
        strncat(logStr,"\n",1);
        record = strtok(NULL, " ");
    }
		
		char *last_newline = strrchr(logStr, '\n');
		if (last_newline != NULL) {
				*last_newline = '\0';
		}
		
    lv_dropdown_set_options(ui_Dropdown2, logStr);
}

void get_data_from_remote() {
    Clear_Buffer();
    Flash_Read(FLASH_USER_START_ADDR, (uint32_t*)features_buf, MAX_FEATURE_SIZE / 4);
    HAL_Delay(1000);
    
    int packets_parsed = 0;
    char *strx;
    char max_num_str[10];
    char num_id_str[10];
    int num_id;
    int max_num=65536;
    while (packets_parsed < max_num) {
        snprintf(logStr,1024,"record,pkg_id:%d",packets_parsed);  
        printf("AT+HMPUB=1,\"/test/M2M/aa\",%d,\"%s\"\r\n",strlen(logStr),logStr);
				Clear_Buffer();
        HAL_Delay(1000);
        strx = strstr((char*)&RxBuffer[0], "test/M2M/hh");
        while (strx == NULL) {
            snprintf(logStr,1024,"record,pkg_id:%d",packets_parsed);  
            printf("AT+HMPUB=1,\"/test/M2M/aa\",%d,\"%s\"\r\n",strlen(logStr),logStr);
            Clear_Buffer();
            HAL_Delay(1000);
            strx = strstr((char*)&RxBuffer[0], "test/M2M/hh");
        }
        
        char *record = strtok(RxBuffer, ";");
        parseAndGetValue(record, "num_id", num_id_str);
        parseAndGetValue(record, "max_num", max_num_str);
				if(max_num_str[0]==NULL||num_id_str[0]==NULL) continue;
        num_id = atoi(num_id_str);
        max_num = atoi(max_num_str);
        char *ptr = (char*)get_feature_ptr(num_id);
        
        // Skip to "data"
        record = strstr(record, "data");
        record = record + 5; // Skip "data:"
        record = strtok(record, ",");
        
        int i = 0;
        while (record!=NULL&&i<128*4) {
            char data = atoi(record);
            ptr[i] = data;
            record = strtok(NULL, ",");
            i++;
        }
				
        if(packets_parsed==num_id)
					packets_parsed++;
        
        Clear_Buffer();
        HAL_Delay(100);
    }
    memcpy(buf_common,features_buf,MAX_FEATURE_SIZE);
    Flash_Erase_and_Write(FLASH_USER_START_ADDR,(uint32_t*)buf_common,MAX_FEATURE_SIZE/4);
    //test flash
    uint32_t MemoryProgramStatus = 0;
    MemoryProgramStatus = 0;
    u8*address=buf_common+MAX_FEATURE_SIZE;
    Flash_Read(FLASH_USER_START_ADDR,(uint32_t*)address,MAX_FEATURE_SIZE/4);
    for (int i = 0; i < MAX_FEATURE_SIZE; i++)
    {
        if (features_buf[i] != address[i])
        {
            MemoryProgramStatus++;
        }
    }
    if(MemoryProgramStatus==0)
        lv_label_set_text(ui_Label18, "录入成功!");
    else 
        lv_label_set_text(ui_Label18, "录入失败!");
    _ui_flag_modify(ui_Label18, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
}

void post_process()
{
	int grid_x, grid_y;
    static int last_person = -1;
    static int last_person_cnt = 0;
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
			if(conf > 2.0)
			{
                lvgl_set_txt(ui_Label4, "识别到人脸");
                cnt_detected++;
                if(cnt_detected == 3){
                    prepare_facenet_data(50,10,216,245);
                    AI_Run1(in_data1,out_data1);
                    if(pdTRUE == xSemaphoreTake(Sem_lvglHandle,portMAX_DELAY))    
                    {
                        u8 temp_state;
                        if(pdTRUE == xSemaphoreTake(Sem_stateHandle,portMAX_DELAY))    
                        {
                            temp_state = ai_state;
                            xSemaphoreGive(Sem_stateHandle);
                        } 
                        if (temp_state == 0)
                        {
                            Flash_Read(FLASH_USER_START_ADDR,(uint32_t*)features_buf,MAX_FEATURE_SIZE/4);
                            int second_max_index = -1;
                            int max_index = post_process_facenet(&second_max_index);
                            snprintf(logStr,30,"确认身份!");
                            lv_label_set_text(ui_Label4, logStr);
                            snprintf(logStr,30,"%4.2f",score[second_max_index]);
                            lv_label_set_text(ui_Labelname,logStr );
                            snprintf(logStr,30,"%d",max_index);
                            lv_label_set_text(ui_Labelid, logStr);
                            snprintf(logStr,30,"%d",last_person_cnt);
                            lv_label_set_text(ui_Labelsex, logStr);
                            if ((score[max_index]<0.35||(score[max_index]-score[second_max_index])<0.18))
                            {
                                snprintf(logStr,30,"置信度:%4.2f,再试一次",score[max_index]);
                                lv_label_set_text(ui_Label18, logStr);
                                 _ui_flag_modify(ui_Label18, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
                                xSemaphoreGive(Sem_lvglHandle);
                                cnt_detected=0;
                                if(last_person != max_index){
                                    last_person = max_index;
                                    last_person_cnt=0;
                                }else if(((score[max_index]-score[second_max_index])>0.03)){
                                    last_person_cnt++;
                                }
                                if((last_person_cnt<3))
                                    return;
                            }               
                            last_person_cnt = 0;             
                            last_person = -1;


                            cur_persion.id = max_index;
                            snprintf(logStr,30,"置信度:%4.2f",score[max_index]);
                            lv_label_set_text(ui_Label18, logStr);
                            _ui_flag_modify(ui_Label18, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
                            
                            update_info();
                            
                            // void get data 
                            cnt_detected=0;
                            lv_label_set_text(ui_Label19, "继续");
                            xSemaphoreGive(Sem_lvglHandle);
                            vTaskSuspend(myTask_aiHandle);
                        }
                        else if(temp_state==2){
                            _ui_flag_modify(ui_Label18, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
                            snprintf(logStr,30,"录入人脸");
                            lv_label_set_text(ui_Label4, logStr);
                            cnt_detected=0;
                            lv_label_set_text(ui_Label19, "继续");
                            lv_label_set_text(ui_Label17, "确认");
                            // xSemaphoreGive(Sem_lvglHandle);
                            // 录入人脸
                           if (cur_persion.id > MAX_ID-1) {
                               lv_label_set_text(ui_Label18,"ID太大");
                               xSemaphoreGive(Sem_lvglHandle);
                           }
                           else{
                                if(i_feature==0){
                                    Flash_Read(FLASH_USER_START_ADDR,(uint32_t*)features_buf,MAX_FEATURE_SIZE/4);
                                    cur_persion.feature =get_feature_ptr(cur_persion.id);
                                    int32_t* cnt = get_cnt_ptr();
                                    memcpy(cur_persion.feature+i_feature*128,out_data1,128);
                                    i_feature++;
                                    snprintf(logStr,30,"调整角度再来一次:%d/4",i_feature);
                                    xSemaphoreGive(Sem_lvglHandle);
                                }else if(i_feature<FEATURE_PER_PERSION-1){
                                    memcpy(cur_persion.feature+i_feature*128,out_data1,128);
                                    i_feature++;
                                    snprintf(logStr,30,"调整角度再来一次:%d/4",i_feature);
                                    lv_label_set_text(ui_Label18, logStr);
                                    xSemaphoreGive(Sem_lvglHandle);
                                }else {
                                    memcpy(cur_persion.feature+i_feature*128,out_data1,128);
                                    i_feature=0;
                                    memcpy(buf_common,features_buf,MAX_FEATURE_SIZE);
                                    Flash_Erase_and_Write(FLASH_USER_START_ADDR,(uint32_t*)buf_common,MAX_FEATURE_SIZE/4);
                                    //test flash
                                    uint32_t MemoryProgramStatus = 0;
                                    MemoryProgramStatus = 0;
                                    u8*address=buf_common+MAX_FEATURE_SIZE;
                                    Flash_Read(FLASH_USER_START_ADDR,(uint32_t*)address,MAX_FEATURE_SIZE/4);
                                    for (int i = 0; i < MAX_FEATURE_SIZE; i++)
                                    {
                                        if (features_buf[i] != address[i])
                                        {
                                            MemoryProgramStatus++;
                                        }
                                    }
                                    if(MemoryProgramStatus==0)
                                        lv_label_set_text(ui_Label18, "录入成功!");
                                    else 
                                        lv_label_set_text(ui_Label18, "录入失败!");
                                    xSemaphoreGive(Sem_lvglHandle);
                                    vTaskSuspend(myTask_aiHandle);
                                }
                            }
                        }
                    } 
                    
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
    HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, 0xFFFF);//����ʵ�������������???????
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

#include "max30102.h"
#include "GY906.h"
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
   HAL_UART_Receive_IT(&huart1,&Res,1);
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
	OV5640_Sharpness(33);	//�Զ����???????????
	OV5640_Focus_Constant();//���������Խ�
//   LCD_Set_Window(0,0,256,400);
	OV5640_OutSize_Set(16,4,256,256);

		// DCMI_Start();
    // L610_test();
    TP_Init();
	LCD_Clear(WHITE);//����
	// InternalFlash_Test();
    
  max30102_init();
  SMBus_Init();
  L610_test();
	//max30102_test();
//	while(1){
//		 float temp = SMBus_ReadTemp();
//     printf("temp = %f\r\n",temp);
//	}
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
