// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.1
// LVGL version: 9.1.0
// Project name: SquareLine_Project

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////


// SCREEN: ui_Screen1
void ui_Screen1_screen_init(void);
lv_obj_t * ui_Screen1;
lv_obj_t * ui_Label1;
lv_obj_t * ui_Label3;
lv_obj_t * ui_Label4;
void ui_event_Switch3(lv_event_t * e);
lv_obj_t * ui_Switch3;
lv_obj_t * ui_Label13;
lv_obj_t * ui_Container1;
lv_obj_t * ui_Image1;
lv_obj_t * ui_Container2;
lv_obj_t * ui_Label6;
lv_obj_t * ui_Label7;
lv_obj_t * ui_Container4;
lv_obj_t * ui_Labelid;
lv_obj_t * ui_Labelage;
lv_obj_t * ui_Labelname;
lv_obj_t * ui_Labelsex;
lv_obj_t * ui_Labeljudge;
lv_obj_t * ui_TabView4;
lv_obj_t * ui_TabPage1;
lv_obj_t * ui_TextArea2;
lv_obj_t * ui_TabPage2;
void ui_event_Switch1(lv_event_t * e);
lv_obj_t * ui_Switch1;
lv_obj_t * ui_Label10;
lv_obj_t * ui_Container7update;
lv_obj_t * ui_Container3;
lv_obj_t * ui_TextArea1;
lv_obj_t * ui_Label5;
lv_obj_t * ui_Container5;
lv_obj_t * ui_Label8;
lv_obj_t * ui_TextArea3;
lv_obj_t * ui_Container6;
lv_obj_t * ui_Label9;
lv_obj_t * ui_TextArea4;
lv_obj_t * ui_Button3;
lv_obj_t * ui_Label11;
lv_obj_t * ui_TabPage3;
void ui_event_Switch2(lv_event_t * e);
lv_obj_t * ui_Switch2;
lv_obj_t * ui_Label2;
lv_obj_t * ui_Container7update1;
lv_obj_t * ui_Dropdown2;
lv_obj_t * ui_Button4;
lv_obj_t * ui_Label12;
lv_obj_t * ui_Container7;
lv_obj_t * ui_TextArea5;
lv_obj_t * ui_Spinbox5;
lv_obj_t * ui_Label14;
void ui_event_Button5(lv_event_t * e);
lv_obj_t * ui_Button5;
lv_obj_t * ui_Label16;
void ui_event_Button6(lv_event_t * e);
lv_obj_t * ui_Button6;
lv_obj_t * ui_Label15;
lv_obj_t * ui_Button7;
lv_obj_t * ui_Label17;
lv_obj_t * ui_Image4;
lv_obj_t * ui_Container8;
lv_obj_t * ui_Container9;
lv_obj_t * ui_Container10;
lv_obj_t * ui____initial_actions0;
const lv_image_dsc_t * ui_imgset_backgroud[4] = {&ui_img_backgroud1_png, &ui_img_backgroud2_png, &ui_img_backgroud3_png, &ui_img_backgroud4_png};

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////
void ui_event_Switch3(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_checked_set_text_value(ui_Label13, target, "人脸录入模式", "人脸识别模式");
    }
    if(event_code == LV_EVENT_CLICKED) {
        _ui_flag_modify(ui_TabView4, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_TOGGLE);
        _ui_flag_modify(ui_Container7, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_TOGGLE);
    }
}
void ui_event_Switch1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_checked_set_text_value(ui_Label10, target, "更新", "记录");
        _ui_flag_modify(ui_Container7update, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_TOGGLE);
    }
}
void ui_event_Switch2(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_checked_set_text_value(ui_Label2, target, "更新", "记录");
        _ui_flag_modify(ui_Container7update1, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_TOGGLE);
    }
}
void ui_event_Button5(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_spinbox_step(ui_Spinbox5, 1);
    }
}
void ui_event_Button6(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_spinbox_step(ui_Spinbox5, -1);
    }
}

///////////////////// SCREENS ////////////////////

void ui_init(void)
{
    lv_disp_t * dispp = lv_display_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_Screen1_screen_init();
    ui____initial_actions0 = lv_obj_create(NULL);
    lv_disp_load_scr(ui_Screen1);
}
