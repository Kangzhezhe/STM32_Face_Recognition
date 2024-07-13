#include "ui.h"
#include "string.h"
#include "FreeRTOS.h"
#include "cmsis_os.h"
extern osThreadId myTask_aiHandle;
lv_obj_t* table;
lv_obj_t* table1;
extern osThreadId myTask_measureHandle;

void ui_event_Switch1_update(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_flag_modify(table, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_TOGGLE);
        if (lv_obj_has_flag(table, LV_OBJ_FLAG_HIDDEN))
        {
            osThreadResume(myTask_measureHandle);
            lv_label_set_text(ui_Label11, "确认");
        }else{
            osThreadSuspend(myTask_measureHandle);
        }
    }
}

void ui_event_Switch2_update(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_flag_modify(table1, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_TOGGLE);
    }
}

void ui_event_Button1(lv_event_t * e){
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        if (strcmp(lv_label_get_text(ui_Label19), "暂停") == 0) {
            _ui_flag_modify(ui_Label18, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
            vTaskSuspend(myTask_aiHandle);
            lv_label_set_text(ui_Label19, "继续");
        }else {
            _ui_flag_modify(ui_Label18, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
            vTaskResume(myTask_aiHandle);
            lv_label_set_text(ui_Label19, "暂停");
        }
    }
}
typedef struct 
{
    int32_t id;
    uint8_t* feature;
    char name[16];
    char sex[4];
    int32_t age;
    char judge[64];
    uint8_t* record;
}Persion;
extern Persion cur_persion;
void set_state(uint8_t temp);
static char logStr1[30];

void ui_event_Button7(lv_event_t * e){
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        cur_persion.id = lv_spinbox_get_value(ui_Spinbox5);
        lv_label_set_text(ui_Label17, "OK");
        snprintf(logStr1,30,"%d",cur_persion.id);
        lv_label_set_text(ui_Labelid, logStr1);
        vTaskResume(myTask_aiHandle);
        lv_label_set_text(ui_Label19, "暂停");
    }
}

#include "main.h"
extern uint8_t cur_dis_hr;
extern uint8_t cur_dis_spo2;
extern float cur_temp;
void update_info(void);
void ui_event_Button3(lv_event_t * e){
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        lv_label_set_text(ui_Label11, "OK");
        osThreadSuspend(myTask_measureHandle);
        char std[100];
        snprintf(std,100,"faceid:%d,tiwen:%2.1f,xueyang:%02d,xinlv:%03d",cur_persion.id+1,cur_temp,cur_dis_spo2,cur_dis_hr);
        int length = strlen(std);

        printf("AT+HMPUB=1,\"/test/M2M/aa\",%d,\"%s\"\r\n",length,std);

        // printf("AT+HMPUB=1,\"/test/M2M/aa\",40,\"faceid:%d,tiwen:%2.1f,xueyang:%02d,xinlv:%03d\"\r\n",cur_persion.id+1,cur_temp,cur_dis_spo2,cur_dis_hr);
        // printf("AT+HMPUB=1,\"/test/M2M/aa\",40,\"faceid:1,tiwen:37.1,xueyang:12,xinlv:123\"\r\n");
        HAL_Delay(1000);
        update_info();
    }
}

void ui_event_Switch3_update(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        if(lv_obj_has_flag(ui_TabView4, LV_OBJ_FLAG_HIDDEN)){
            lv_label_set_text(ui_Label17, "确认");
            vTaskSuspend(myTask_aiHandle);
            lv_label_set_text(ui_Label19, "继续");
            set_state(1);
        }else{
            vTaskResume(myTask_aiHandle);
            lv_label_set_text(ui_Label19, "暂停");
            set_state(0);
        }
    }
}


void ui_event_Button4(lv_event_t * e){
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        char name[1024];
        lv_dropdown_get_selected_str(ui_Dropdown2,name,1024);
        char std[1024];
        snprintf(std,1024,"faceid:%d,yao:%s",cur_persion.id+1,name);
        int length = strlen(std);
        printf("AT+HMPUB=1,\"/test/M2M/aa\",%d,\"%s\"\r\n",length,std);
    }
}

void my_ui_init(void){
    lv_label_set_text(ui_Label16, LV_SYMBOL_PLUS);
    lv_label_set_text(ui_Label15, LV_SYMBOL_MINUS);


    table = lv_table_create(ui_TabPage2);
    lv_table_set_col_cnt(table, 4);
    lv_obj_set_width(table, 444);
    lv_obj_set_height(table, 212);
    lv_obj_set_x(table, -1);
    lv_obj_set_y(table, 13);
    lv_obj_set_align(table, LV_ALIGN_TOP_MID);
    
    lv_obj_set_style_text_font(table, &ui_font_Fontcnmsg, LV_PART_MAIN | LV_STATE_DEFAULT);

    /*Fill the first column*/
    lv_table_set_cell_value(table, 0, 0, "时间");
    lv_table_set_cell_value(table, 0, 1, "体温(*C)");
    lv_table_set_cell_value(table, 0, 2, "心率(bpm)");
    lv_table_set_cell_value(table, 0, 3, "血氧(%)");
    lv_table_set_cell_value_fmt(table, 1, 0, "%d月%d日 %02d:%02d", 7,4,23,59);
    lv_table_set_cell_value_fmt(table, 1, 1, "%d.%d", 36,8);
    lv_table_set_cell_value_fmt(table, 1, 2, "%d", 75);
    lv_table_set_cell_value_fmt(table, 1, 3, "%d", 75);


     table1 = lv_table_create(ui_TabPage3);
    lv_table_set_col_cnt(table1, 2);
    lv_obj_set_width(table1, 444);
    lv_obj_set_height(table1, 212);
    lv_obj_set_x(table1, -1);
    lv_obj_set_y(table1, 13);
    lv_obj_set_align(table1, LV_ALIGN_TOP_MID);
    lv_obj_set_style_text_font(table1, &ui_font_Fontcnmsg, LV_PART_MAIN | LV_STATE_DEFAULT);

    /*Fill the first column*/
    lv_table_set_cell_value(table1, 0, 0, "时间");
    lv_table_set_cell_value(table1, 0, 1, "药品");
    lv_table_set_cell_value_fmt(table1, 1, 0, "%d月%d日 %02d:%02d", 7,4,23,59);
    lv_table_set_cell_value(table1, 1, 1, "阿莫西林");


    lv_obj_add_event_cb(ui_Switch1, ui_event_Switch1_update, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Switch2, ui_event_Switch2_update, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Button1, ui_event_Button1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Button7, ui_event_Button7, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Switch3, ui_event_Switch3_update, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Button3, ui_event_Button3, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Button4, ui_event_Button4, LV_EVENT_ALL, NULL);
}