// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.1
// LVGL version: 9.1.0
// Project name: SquareLine_Project

#include "../ui.h"

void ui_Screen1_screen_init(void)
{
    ui_Screen1 = lv_obj_create(NULL);
    lv_obj_remove_flag(ui_Screen1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_image_src(ui_Screen1, &ui_img_backgroud4_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_opa(ui_Screen1, 180, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_tiled(ui_Screen1, true, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label1 = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_Label1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label1, 0);
    lv_obj_set_y(ui_Label1, 21);
    lv_obj_set_align(ui_Label1, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_Label1, "医疗先锋人脸识别系统");
    lv_obj_set_style_text_color(ui_Label1, lv_color_hex(0xCF116A), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui_Label1, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui_Label1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label1, &ui_font_Fontcn30, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_Label1, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Label1, lv_color_hex(0x08C7C2), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Label1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_Label1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui_Label1, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Label1, lv_color_hex(0x3F08F1), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Label1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Label1, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Label1, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Label1, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Label1, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Label1, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label3 = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_Label3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label3, -136);
    lv_obj_set_y(ui_Label3, -31);
    lv_obj_set_align(ui_Label3, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label3, "状态:");
    lv_obj_set_style_text_font(ui_Label3, &ui_font_Fontcn15, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label4 = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_Label4, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label4, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label4, -31);
    lv_obj_set_y(ui_Label4, -32);
    lv_obj_set_align(ui_Label4, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label4, "检测中");
    lv_obj_set_style_text_font(ui_Label4, &ui_font_Fontcnmsg, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_Label4, lv_color_hex(0xDD2A4A), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_Label4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_Label4, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_Label4, 2, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Switch3 = lv_switch_create(ui_Screen1);
    lv_obj_set_width(ui_Switch3, 173);
    lv_obj_set_height(ui_Switch3, 40);
    lv_obj_set_x(ui_Switch3, 143);
    lv_obj_set_y(ui_Switch3, -33);
    lv_obj_set_align(ui_Switch3, LV_ALIGN_CENTER);
    lv_obj_set_style_shadow_color(ui_Switch3, lv_color_hex(0x00EDFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_Switch3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_Switch3, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_Switch3, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(ui_Switch3, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(ui_Switch3, 2, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_Switch3, 10, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Switch3, lv_color_hex(0x67B1E3), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Switch3, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Switch3, lv_color_hex(0x33353A), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Switch3, 255, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_Label13 = lv_label_create(ui_Switch3);
    lv_obj_set_width(ui_Label13, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label13, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label13, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label13, "人脸识别模式");
    lv_obj_set_style_text_font(ui_Label13, &ui_font_Fontcn15, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Container1 = lv_obj_create(ui_Screen1);
    lv_obj_remove_style_all(ui_Container1);
    lv_obj_set_width(ui_Container1, 300);
    lv_obj_set_height(ui_Container1, 300);
    lv_obj_set_x(ui_Container1, 0);
    lv_obj_set_y(ui_Container1, 58);
    lv_obj_set_align(ui_Container1, LV_ALIGN_TOP_MID);
    lv_obj_remove_flag(ui_Container1, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Image1 = lv_image_create(ui_Container1);
    lv_obj_set_width(ui_Image1, LV_SIZE_CONTENT);   /// 256
    lv_obj_set_height(ui_Image1, LV_SIZE_CONTENT);    /// 256
    lv_obj_set_align(ui_Image1, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Image1, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_remove_flag(ui_Image1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_shadow_color(ui_Image1, lv_color_hex(0x2EC1D3), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_Image1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_Image1, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_Image1, 10, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Container2 = lv_obj_create(ui_Screen1);
    lv_obj_remove_style_all(ui_Container2);
    lv_obj_set_width(ui_Container2, 479);
    lv_obj_set_height(ui_Container2, 84);
    lv_obj_set_x(ui_Container2, 0);
    lv_obj_set_y(ui_Container2, 39);
    lv_obj_set_align(ui_Container2, LV_ALIGN_CENTER);
    lv_obj_remove_flag(ui_Container2, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Container2, lv_color_hex(0x83A0C6), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Container2, 200, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label6 = lv_label_create(ui_Container2);
    lv_obj_set_width(ui_Label6, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label6, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label6, -169);
    lv_obj_set_y(ui_Label6, 7);
    lv_obj_set_align(ui_Label6, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_Label6, "个人信息:");
    lv_obj_set_style_text_color(ui_Label6, lv_color_hex(0x424141), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label6, &ui_font_Fontcn20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label7 = lv_label_create(ui_Container2);
    lv_obj_set_width(ui_Label7, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label7, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label7, 0);
    lv_obj_set_y(ui_Label7, 32);
    lv_obj_set_align(ui_Label7, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_Label7,
                      "ID                     姓名                      性别                     年龄                     诊断");
    lv_obj_set_style_text_color(ui_Label7, lv_color_hex(0xCF3939), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label7, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label7, &ui_font_Fontcn15, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Container4 = lv_obj_create(ui_Container2);
    lv_obj_remove_style_all(ui_Container4);
    lv_obj_set_width(ui_Container4, 415);
    lv_obj_set_height(ui_Container4, 50);
    lv_obj_set_x(ui_Container4, 0);
    lv_obj_set_y(ui_Container4, 42);
    lv_obj_set_align(ui_Container4, LV_ALIGN_TOP_MID);
    lv_obj_remove_flag(ui_Container4, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Labelid = lv_label_create(ui_Container4);
    lv_obj_set_width(ui_Labelid, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Labelid, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Labelid, -186);
    lv_obj_set_y(ui_Labelid, 0);
    lv_obj_set_align(ui_Labelid, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Labelid, "0");

    ui_Labelage = lv_label_create(ui_Container4);
    lv_obj_set_width(ui_Labelage, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Labelage, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Labelage, 88);
    lv_obj_set_y(ui_Labelage, 0);
    lv_obj_set_align(ui_Labelage, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Labelage, "21");

    ui_Labelname = lv_label_create(ui_Container4);
    lv_obj_set_width(ui_Labelname, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Labelname, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Labelname, -99);
    lv_obj_set_y(ui_Labelname, 0);
    lv_obj_set_align(ui_Labelname, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Labelname, "康哲豪");
    lv_obj_set_style_text_font(ui_Labelname, &ui_font_Fontcnmsg, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Labelsex = lv_label_create(ui_Container4);
    lv_obj_set_width(ui_Labelsex, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Labelsex, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Labelsex, -4);
    lv_obj_set_y(ui_Labelsex, 0);
    lv_obj_set_align(ui_Labelsex, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Labelsex, "男");
    lv_obj_set_style_text_font(ui_Labelsex, &ui_font_Fontcnmsg, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Labeljudge = lv_label_create(ui_Container4);
    lv_obj_set_width(ui_Labeljudge, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Labeljudge, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Labeljudge, 180);
    lv_obj_set_y(ui_Labeljudge, 0);
    lv_obj_set_align(ui_Labeljudge, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Labeljudge, "支气管炎");
    lv_obj_set_style_text_font(ui_Labeljudge, &ui_font_Fontcnmsg, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TabView4 = lv_tabview_create(ui_Screen1);
    lv_tabview_set_tab_bar_size(ui_TabView4, 50);
    lv_obj_set_width(ui_TabView4, 449);
    lv_obj_set_height(ui_TabView4, 315);
    lv_obj_set_x(ui_TabView4, -1);
    lv_obj_set_y(ui_TabView4, 237);
    lv_obj_set_align(ui_TabView4, LV_ALIGN_CENTER);
    lv_obj_remove_flag(ui_TabView4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_set_style_text_color(lv_tabview_get_tab_bar(ui_TabView4), lv_color_hex(0x6E6D6D),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(lv_tabview_get_tab_bar(ui_TabView4), 255,  LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(lv_tabview_get_tab_bar(ui_TabView4), &ui_font_Fontcn20,  LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TabPage1 = lv_tabview_add_tab(ui_TabView4, "诊断意见");

    ui_TextArea2 = lv_textarea_create(ui_TabPage1);
    lv_obj_set_width(ui_TextArea2, 434);
    lv_obj_set_height(ui_TextArea2, 246);
    lv_obj_set_x(ui_TextArea2, -1);
    lv_obj_set_y(ui_TextArea2, -13);
    lv_obj_set_align(ui_TextArea2, LV_ALIGN_TOP_MID);
    lv_textarea_set_text(ui_TextArea2, "住院观察，清淡饮食");
    lv_textarea_set_placeholder_text(ui_TextArea2, "Placeholder...");
    lv_obj_set_style_text_font(ui_TextArea2, &ui_font_Fontcnmsg, LV_PART_MAIN | LV_STATE_DEFAULT);



    ui_TabPage2 = lv_tabview_add_tab(ui_TabView4, "监护记录");

    ui_Switch1 = lv_switch_create(ui_TabPage2);
    lv_obj_set_width(ui_Switch1, 88);
    lv_obj_set_height(ui_Switch1, 25);
    lv_obj_set_x(ui_Switch1, 171);
    lv_obj_set_y(ui_Switch1, -117);
    lv_obj_set_align(ui_Switch1, LV_ALIGN_CENTER);
    lv_obj_set_style_shadow_color(ui_Switch1, lv_color_hex(0x00EDFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_Switch1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_Switch1, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_Switch1, 2, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_Switch1, 10, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Switch1, lv_color_hex(0x67B1E3), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Switch1, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Switch1, lv_color_hex(0x33353A), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Switch1, 255, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_Label10 = lv_label_create(ui_Switch1);
    lv_obj_set_width(ui_Label10, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label10, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label10, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label10, "记录");
    lv_obj_set_style_text_font(ui_Label10, &ui_font_Fontcn15, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Container7update = lv_obj_create(ui_TabPage2);
    lv_obj_remove_style_all(ui_Container7update);
    lv_obj_set_width(ui_Container7update, 320);
    lv_obj_set_height(ui_Container7update, 202);
    lv_obj_set_x(ui_Container7update, 0);
    lv_obj_set_y(ui_Container7update, -12);
    lv_obj_set_align(ui_Container7update, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Container7update, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_remove_flag(ui_Container7update, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Container3 = lv_obj_create(ui_Container7update);
    lv_obj_remove_style_all(ui_Container3);
    lv_obj_set_width(ui_Container3, 90);
    lv_obj_set_height(ui_Container3, 103);
    lv_obj_set_x(ui_Container3, -113);
    lv_obj_set_y(ui_Container3, -20);
    lv_obj_set_align(ui_Container3, LV_ALIGN_CENTER);
    lv_obj_remove_flag(ui_Container3, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_TextArea1 = lv_textarea_create(ui_Container3);
    lv_obj_set_width(ui_TextArea1, 54);
    lv_obj_set_height(ui_TextArea1, 41);
    lv_obj_set_x(ui_TextArea1, -1);
    lv_obj_set_y(ui_TextArea1, -1);
    lv_obj_set_align(ui_TextArea1, LV_ALIGN_CENTER);
    lv_textarea_set_text(ui_TextArea1, "00.0");



    ui_Label5 = lv_label_create(ui_Container3);
    lv_obj_set_width(ui_Label5, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label5, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label5, 0);
    lv_obj_set_y(ui_Label5, -34);
    lv_obj_set_align(ui_Label5, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label5, "体温(*C)");
    lv_obj_set_style_text_font(ui_Label5, &ui_font_Fontcnmsg, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Container5 = lv_obj_create(ui_Container7update);
    lv_obj_remove_style_all(ui_Container5);
    lv_obj_set_width(ui_Container5, 90);
    lv_obj_set_height(ui_Container5, 103);
    lv_obj_set_x(ui_Container5, 0);
    lv_obj_set_y(ui_Container5, -20);
    lv_obj_set_align(ui_Container5, LV_ALIGN_CENTER);
    lv_obj_remove_flag(ui_Container5, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label8 = lv_label_create(ui_Container5);
    lv_obj_set_width(ui_Label8, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label8, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label8, 0);
    lv_obj_set_y(ui_Label8, -34);
    lv_obj_set_align(ui_Label8, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label8, "心率(bpm)");
    lv_obj_set_style_text_font(ui_Label8, &ui_font_Fontcnmsg, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TextArea3 = lv_textarea_create(ui_Container5);
    lv_obj_set_width(ui_TextArea3, 52);
    lv_obj_set_height(ui_TextArea3, 41);
    lv_obj_set_x(ui_TextArea3, -1);
    lv_obj_set_y(ui_TextArea3, -1);
    lv_obj_set_align(ui_TextArea3, LV_ALIGN_CENTER);
    lv_textarea_set_text(ui_TextArea3, "00");



    ui_Container6 = lv_obj_create(ui_Container7update);
    lv_obj_remove_style_all(ui_Container6);
    lv_obj_set_width(ui_Container6, 90);
    lv_obj_set_height(ui_Container6, 103);
    lv_obj_set_x(ui_Container6, 111);
    lv_obj_set_y(ui_Container6, -20);
    lv_obj_set_align(ui_Container6, LV_ALIGN_CENTER);
    lv_obj_remove_flag(ui_Container6, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label9 = lv_label_create(ui_Container6);
    lv_obj_set_width(ui_Label9, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label9, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label9, 0);
    lv_obj_set_y(ui_Label9, -34);
    lv_obj_set_align(ui_Label9, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label9, "血氧(%)");
    lv_obj_set_style_text_font(ui_Label9, &ui_font_Fontcnmsg, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TextArea4 = lv_textarea_create(ui_Container6);
    lv_obj_set_width(ui_TextArea4, 52);
    lv_obj_set_height(ui_TextArea4, 41);
    lv_obj_set_x(ui_TextArea4, -1);
    lv_obj_set_y(ui_TextArea4, -1);
    lv_obj_set_align(ui_TextArea4, LV_ALIGN_CENTER);
    lv_textarea_set_text(ui_TextArea4, "00");



    ui_Button3 = lv_button_create(ui_Container7update);
    lv_obj_set_width(ui_Button3, 100);
    lv_obj_set_height(ui_Button3, 50);
    lv_obj_set_x(ui_Button3, -2);
    lv_obj_set_y(ui_Button3, 50);
    lv_obj_set_align(ui_Button3, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button3, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_remove_flag(ui_Button3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label11 = lv_label_create(ui_Button3);
    lv_obj_set_width(ui_Label11, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label11, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label11, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label11, "确认");
    lv_obj_set_style_text_font(ui_Label11, &ui_font_Fontcn15, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TabPage3 = lv_tabview_add_tab(ui_TabView4, "用药记录");

    ui_Switch2 = lv_switch_create(ui_TabPage3);
    lv_obj_set_width(ui_Switch2, 88);
    lv_obj_set_height(ui_Switch2, 25);
    lv_obj_set_x(ui_Switch2, 171);
    lv_obj_set_y(ui_Switch2, -117);
    lv_obj_set_align(ui_Switch2, LV_ALIGN_CENTER);
    lv_obj_set_style_shadow_color(ui_Switch2, lv_color_hex(0x00EDFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_Switch2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_Switch2, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_Switch2, 2, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_Switch2, 10, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Switch2, lv_color_hex(0x67B1E3), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Switch2, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Switch2, lv_color_hex(0x33353A), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Switch2, 255, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_Label2 = lv_label_create(ui_Switch2);
    lv_obj_set_width(ui_Label2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label2, "记录");
    lv_obj_set_style_text_font(ui_Label2, &ui_font_Fontcn15, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Container7update1 = lv_obj_create(ui_TabPage3);
    lv_obj_remove_style_all(ui_Container7update1);
    lv_obj_set_width(ui_Container7update1, 323);
    lv_obj_set_height(ui_Container7update1, 202);
    lv_obj_set_x(ui_Container7update1, -1);
    lv_obj_set_y(ui_Container7update1, 11);
    lv_obj_set_align(ui_Container7update1, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Container7update1, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_remove_flag(ui_Container7update1, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Dropdown2 = lv_dropdown_create(ui_Container7update1);
    lv_dropdown_set_options(ui_Dropdown2, "阿莫西林\n布洛芬");
    lv_obj_set_width(ui_Dropdown2, 150);
    lv_obj_set_height(ui_Dropdown2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Dropdown2, -67);
    lv_obj_set_y(ui_Dropdown2, -73);
    lv_obj_set_align(ui_Dropdown2, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Dropdown2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_set_style_text_font(ui_Dropdown2, &ui_font_Fontcnmsg, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_text_font(ui_Dropdown2, &lv_font_montserrat_14, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_text_font(lv_dropdown_get_list(ui_Dropdown2), &ui_font_Fontcnmsg,  LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_text_font(lv_dropdown_get_list(ui_Dropdown2), &ui_font_Fontcnmsg,
                               LV_PART_SELECTED | LV_STATE_DEFAULT);

    ui_Button4 = lv_button_create(ui_Container7update1);
    lv_obj_set_width(ui_Button4, 100);
    lv_obj_set_height(ui_Button4, 36);
    lv_obj_set_x(ui_Button4, 98);
    lv_obj_set_y(ui_Button4, -73);
    lv_obj_set_align(ui_Button4, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button4, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_remove_flag(ui_Button4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_text_font(ui_Button4, &ui_font_Fontcn15, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label12 = lv_label_create(ui_Button4);
    lv_obj_set_width(ui_Label12, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label12, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label12, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label12, "添加");

    ui_Container7 = lv_obj_create(ui_Screen1);
    lv_obj_remove_style_all(ui_Container7);
    lv_obj_set_width(ui_Container7, 464);
    lv_obj_set_height(ui_Container7, 317);
    lv_obj_set_x(ui_Container7, 1);
    lv_obj_set_y(ui_Container7, 238);
    lv_obj_set_align(ui_Container7, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Container7, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_remove_flag(ui_Container7, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Container7, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Container7, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TextArea5 = lv_textarea_create(ui_Container7);
    lv_obj_set_width(ui_TextArea5, 405);
    lv_obj_set_height(ui_TextArea5, 64);
    lv_obj_set_x(ui_TextArea5, 2);
    lv_obj_set_y(ui_TextArea5, -88);
    lv_obj_set_align(ui_TextArea5, LV_ALIGN_CENTER);
    lv_textarea_set_text(ui_TextArea5,
                         "人脸录入模式，请输入要录入的人的id号，点击确认开始录入人脸信息");
    lv_obj_set_style_text_color(ui_TextArea5, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_TextArea5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_TextArea5, &ui_font_Fontcn15, LV_PART_MAIN | LV_STATE_DEFAULT);



    ui_Spinbox5 = lv_spinbox_create(ui_Container7);
    lv_obj_set_width(ui_Spinbox5, 113);
    lv_obj_set_height(ui_Spinbox5, 58);
    lv_obj_set_x(ui_Spinbox5, -20);
    lv_obj_set_y(ui_Spinbox5, 16);
    lv_obj_set_align(ui_Spinbox5, LV_ALIGN_CENTER);
    lv_spinbox_set_digit_format(ui_Spinbox5, 4, 4);
    lv_spinbox_set_range(ui_Spinbox5, 0, 9999);
    lv_spinbox_set_cursor_pos(ui_Spinbox5, 1 - 1);
    lv_obj_set_style_text_align(ui_Spinbox5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Spinbox5, &lv_font_montserrat_26, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label14 = lv_label_create(ui_Container7);
    lv_obj_set_width(ui_Label14, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label14, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label14, -21);
    lv_obj_set_y(ui_Label14, -33);
    lv_obj_set_align(ui_Label14, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label14, "ID");
    lv_obj_set_style_text_color(ui_Label14, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label14, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label14, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Button5 = lv_button_create(ui_Container7);
    lv_obj_set_width(ui_Button5, 56);
    lv_obj_set_height(ui_Button5, 56);
    lv_obj_set_x(ui_Button5, 80);
    lv_obj_set_y(ui_Button5, 16);
    lv_obj_set_align(ui_Button5, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button5, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_remove_flag(ui_Button5, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label16 = lv_label_create(ui_Button5);
    lv_obj_set_width(ui_Label16, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label16, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label16, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label16, "");

    ui_Button6 = lv_button_create(ui_Container7);
    lv_obj_set_width(ui_Button6, 56);
    lv_obj_set_height(ui_Button6, 56);
    lv_obj_set_x(ui_Button6, -122);
    lv_obj_set_y(ui_Button6, 16);
    lv_obj_set_align(ui_Button6, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button6, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_remove_flag(ui_Button6, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label15 = lv_label_create(ui_Button6);
    lv_obj_set_width(ui_Label15, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label15, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label15, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label15, "");

    ui_Button7 = lv_button_create(ui_Container7);
    lv_obj_set_width(ui_Button7, 122);
    lv_obj_set_height(ui_Button7, 50);
    lv_obj_set_x(ui_Button7, -21);
    lv_obj_set_y(ui_Button7, 94);
    lv_obj_set_align(ui_Button7, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button7, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_remove_flag(ui_Button7, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label17 = lv_label_create(ui_Button7);
    lv_obj_set_width(ui_Label17, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label17, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label17, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label17, "确认");
    lv_obj_set_style_text_font(ui_Label17, &ui_font_Fontcn15, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Image4 = lv_image_create(ui_Screen1);
    lv_image_set_src(ui_Image4, &ui_img_backgroud3_png);
    lv_obj_set_width(ui_Image4, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Image4, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Image4, 0);
    lv_obj_set_y(ui_Image4, -392);
    lv_obj_set_align(ui_Image4, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Image4, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_remove_flag(ui_Image4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Container8 = lv_obj_create(ui_Screen1);
    lv_obj_remove_style_all(ui_Container8);
    lv_obj_set_width(ui_Container8, 100);
    lv_obj_set_height(ui_Container8, 50);
    lv_obj_set_align(ui_Container8, LV_ALIGN_CENTER);
    lv_obj_remove_flag(ui_Container8, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Container9 = lv_obj_create(ui_Screen1);
    lv_obj_remove_style_all(ui_Container9);
    lv_obj_set_width(ui_Container9, 100);
    lv_obj_set_height(ui_Container9, 172);
    lv_obj_set_x(ui_Container9, -186);
    lv_obj_set_y(ui_Container9, -243);
    lv_obj_set_align(ui_Container9, LV_ALIGN_CENTER);
    lv_obj_remove_flag(ui_Container9, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_image_src(ui_Container9, &ui_img_backgroud1_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_opa(ui_Container9, 180, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_image_opa(ui_Container9, 180, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);

    ui_Container10 = lv_obj_create(ui_Screen1);
    lv_obj_remove_style_all(ui_Container10);
    lv_obj_set_width(ui_Container10, 100);
    lv_obj_set_height(ui_Container10, 184);
    lv_obj_set_x(ui_Container10, 188);
    lv_obj_set_y(ui_Container10, -246);
    lv_obj_set_align(ui_Container10, LV_ALIGN_CENTER);
    lv_obj_remove_flag(ui_Container10, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_image_src(ui_Container10, &ui_img_backgroud2_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_opa(ui_Container10, 180, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label18 = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_Label18, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label18, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label18, -30);
    lv_obj_set_y(ui_Label18, -5);
    lv_obj_set_align(ui_Label18, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label18, "置信度:");
    lv_obj_add_flag(ui_Label18, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_set_style_text_font(ui_Label18, &ui_font_Fontcnmsg, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Button1 = lv_button_create(ui_Screen1);
    lv_obj_set_width(ui_Button1, 71);
    lv_obj_set_height(ui_Button1, 33);
    lv_obj_set_x(ui_Button1, 177);
    lv_obj_set_y(ui_Button1, -152);
    lv_obj_set_align(ui_Button1, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_remove_flag(ui_Button1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label19 = lv_label_create(ui_Button1);
    lv_obj_set_width(ui_Label19, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label19, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label19, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label19, "暂停");
    lv_obj_set_style_text_font(ui_Label19, &ui_font_Fontcn15, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_Switch3, ui_event_Switch3, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Switch1, ui_event_Switch1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Switch2, ui_event_Switch2, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Button5, ui_event_Button5, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Button6, ui_event_Button6, LV_EVENT_ALL, NULL);

}
