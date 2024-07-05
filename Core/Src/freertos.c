/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
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
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "lv_port_disp.h"
#include "lvgl.h"
#include "lv_port_indev.h"
#include "dcmi.h"
#include "ui.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
uint8_t ucHeap[ configTOTAL_HEAP_SIZE ]__attribute__((section(".RAM_D2")));
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
osThreadId defaultTaskHandle;
osThreadId start_taskHandle;
osThreadId myTask_lvglHandle;
osThreadId myTask_aiHandle;
osSemaphoreId Sem_lvglHandle;
osSemaphoreId Sem_imgbufHandle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void const * argument);
void StartTask(void const * argument);
void StartTask_lvgl(void const * argument);
void StartTask_ai(void const * argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* GetIdleTaskMemory prototype (linked to static allocation support) */
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize );

/* Hook prototypes */
void vApplicationTickHook(void);

/* USER CODE BEGIN 3 */
__weak void vApplicationTickHook( void )
{
   /* This function will be called by each tick interrupt if
   configUSE_TICK_HOOK is set to 1 in FreeRTOSConfig.h. User code can be
   added here, but the tick hook is called from an interrupt context, so
   code must not attempt to block, and only the interrupt safe FreeRTOS API
   functions can be used (those that end in FromISR()). */
   lv_tick_inc(1);
}
/* USER CODE END 3 */

/* USER CODE BEGIN GET_IDLE_TASK_MEMORY */
static StaticTask_t xIdleTaskTCBBuffer;
static StackType_t xIdleStack[configMINIMAL_STACK_SIZE];

void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize )
{
  *ppxIdleTaskTCBBuffer = &xIdleTaskTCBBuffer;
  *ppxIdleTaskStackBuffer = &xIdleStack[0];
  *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
  /* place for user code */
}
/* USER CODE END GET_IDLE_TASK_MEMORY */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* Create the semaphores(s) */
  /* definition and creation of Sem_lvgl */
  osSemaphoreDef(Sem_lvgl);
  Sem_lvglHandle = osSemaphoreCreate(osSemaphore(Sem_lvgl), 1);

  /* definition and creation of Sem_imgbuf */
  osSemaphoreDef(Sem_imgbuf);
  Sem_imgbufHandle = osSemaphoreCreate(osSemaphore(Sem_imgbuf), 1);

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of defaultTask */
  osThreadDef(defaultTask, StartDefaultTask, osPriorityNormal, 0, 128);
  defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL);

  /* definition and creation of start_task */
  osThreadDef(start_task, StartTask, osPriorityIdle, 0, 512);
  start_taskHandle = osThreadCreate(osThread(start_task), NULL);

  /* definition and creation of myTask_lvgl */
  osThreadDef(myTask_lvgl, StartTask_lvgl, osPriorityIdle, 0, 768);
  myTask_lvglHandle = osThreadCreate(osThread(myTask_lvgl), NULL);

  /* definition and creation of myTask_ai */
  osThreadDef(myTask_ai, StartTask_ai, osPriorityIdle, 0, 1024);
  myTask_aiHandle = osThreadCreate(osThread(myTask_ai), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  osThreadSuspend(myTask_lvglHandle);
  osThreadSuspend(myTask_aiHandle);
  /* USER CODE END RTOS_THREADS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void const * argument)
{
  /* USER CODE BEGIN StartDefaultTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
   // process_ai();
    
  }
  /* USER CODE END StartDefaultTask */
}

/* USER CODE BEGIN Header_StartTask */
/**
* @brief Function implementing the start_task thread.
* @param argument: Not used
* @retval None
*/
extern void lv_example_get_started_1(void);
extern void lv_cam_canvas(void);
void my_ui_init(void);
/* USER CODE END Header_StartTask */
void StartTask(void const * argument)
{
  /* USER CODE BEGIN StartTask */
   if(pdTRUE == xSemaphoreTake(Sem_lvglHandle,portMAX_DELAY))    
    {
        //lvgl
        lv_init();
        lv_port_disp_init();
        lv_port_indev_init();
        // lv_example_get_started_1();
        ui_init();
        lv_cam_canvas();
        my_ui_init();
        xSemaphoreGive(Sem_lvglHandle);
    }
		osThreadResume(myTask_lvglHandle);
		
    //vTaskDelay(1000);
    DCMI_Start();
  
    osThreadResume(myTask_aiHandle);
  vTaskDelete(start_taskHandle);
  /* USER CODE END StartTask */
}

/* USER CODE BEGIN Header_StartTask_lvgl */
/**
* @brief Function implementing the myTask_lvgl thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask_lvgl */
void StartTask_lvgl(void const * argument)
{
  /* USER CODE BEGIN StartTask_lvgl */
  /* Infinite loop */
 for(;;)
  {
    osDelay(1);
    if(pdTRUE == xSemaphoreTake(Sem_lvglHandle,portMAX_DELAY))    
    {
            lv_timer_handler();        
            xSemaphoreGive(Sem_lvglHandle);
    }
  } 
  /* USER CODE END StartTask_lvgl */
}

/* USER CODE BEGIN Header_StartTask_ai */
/**
* @brief Function implementing the myTask_ai thread.
* @param argument: Not used
* @retval None
*/
 void process_ai(void);
#include "dcmi.h"
/* USER CODE END Header_StartTask_ai */
void StartTask_ai(void const * argument)
{
  /* USER CODE BEGIN StartTask_ai */

  /* Infinite loop */
  for(;;)
  {
    HAL_DCMI_Suspend(&hdcmi);
 	HAL_DCMI_Stop(&hdcmi);
    process_ai();
    DCMI_Start();
    osDelay(1);
  }
  /* USER CODE END StartTask_ai */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */
