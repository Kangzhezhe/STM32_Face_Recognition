#include "ui.h"
lv_obj_t* table;
lv_obj_t* table1;
void ui_event_Switch1_update(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_flag_modify(table, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_TOGGLE);
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

void my_ui_init(void){
    lv_label_set_text(ui_Label16, LV_SYMBOL_PLUS);
    lv_label_set_text(ui_Label15, LV_SYMBOL_MINUS);


    table = lv_table_create(ui_TabPage2);
    lv_table_set_col_cnt(table, 4);
    lv_obj_set_width(table, 344);
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
    lv_obj_set_width(table1, 344);
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
}