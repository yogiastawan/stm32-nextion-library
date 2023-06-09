/**
 * Copyright (c) 2023 I Gede Yogi Astawan
 *
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include "gx_nextion_ds_button.h"

GxNextionDSButton gx_nextion_ds_button_bind(u8 pid, u8 cid, const char *name)
{
    GxNextionDSButton o = {
        .base_obj = bind_gx_nextion_object_base(GX_NEXTION_DUAL_STATE_BUTTON, pid, cid, name),
        .on_click = NULL,
        .on_release = NULL,
        .__data_click = NULL,
        .__data_release = NULL};
    return o;
}

void gx_nextion_ds_button_set_onclick(GxNextionDSButton *btn, GxNextionCallback clbk, void *data)
{
    gx_nextion_set_objt_onclick(btn, GX_NEXTION_DUAL_STATE_BUTTON, clbk, data);
}

void gx_nextion_ds_button_set_onrelease(GxNextionDSButton *btn, GxNextionCallback clbk, void *data)
{
    gx_nextion_set_objt_onrelease(btn, GX_NEXTION_DUAL_STATE_BUTTON, clbk, data);
}

GxBool gx_nextion_ds_button_set_value(GxNextionDSButton *btn, GxBool active)
{
    return gx_nextion_set_objt_value(btn, GX_NEXTION_DUAL_STATE_BUTTON, (i32)active);
}

GxBool gx_nextion_ds_button_get_value(GxNextionDSButton *btn, GxBool *value)
{
    i32 tmp = 0;
    GxBool a = gx_nextion_get_objt_value(btn, GX_NEXTION_DUAL_STATE_BUTTON, &tmp);
    *value = (GxBool)tmp;
    return a;
}

GxBool gx_nextion_ds_button_set_font(GxNextionDSButton *btn, u32 font_id)
{
    return gx_nextion_set_objt_font(btn, GX_NEXTION_DUAL_STATE_BUTTON, font_id);
}

GxBool gx_nextion_ds_button_set_backgroud_color(GxNextionDSButton *btn, u16 clr)
{
    return gx_nextion_set_objt_background_color(btn, GX_NEXTION_DUAL_STATE_BUTTON, clr);
}

GxBool gx_nextion_ds_button_set_backgroud_image(GxNextionDSButton *btn, u32 img)
{
    return gx_nextion_set_objt_background_img(btn, GX_NEXTION_DUAL_STATE_BUTTON, img);
}

GxBool gx_nextion_ds_button_set_backgroud_image_crop(GxNextionDSButton *btn, u32 img)
{
    return gx_nextion_set_objt_background_crop(btn, GX_NEXTION_DUAL_STATE_BUTTON, img);
}

GxBool gx_nextion_ds_button_set_active_backgroud_color(GxNextionDSButton *btn, u16 clr)
{
    GxNextion *device = gx_nextion_current_device();
    return_val_if(!device, GX_FALSE);
    return_val_if(btn->base_obj.obj_type != GX_NEXTION_DUAL_STATE_BUTTON, GX_FALSE);
    char v[6] = {0};
    __utoa(clr, v, 10);
    u16 len_cmd = strlen(btn->base_obj.name) + 5 + 7; //".bco2="+'\0'=7
    char *cmd = malloc(sizeof(char) * len_cmd);
    strcat(cmd, btn->base_obj.name);
    strcat(cmd, ".bco2=");
    strcat(cmd, v);
    gx_nextion_send_cmd(device, cmd);
    free(cmd);
    return gx_cmd_finished(device);
}

GxBool gx_nextion_ds_button_set_active_backgroud_image(GxNextionDSButton *btn, u32 img)
{
    GxNextion *device = gx_nextion_current_device();
    return_val_if(!device, GX_FALSE);
    return_val_if(btn->base_obj.obj_type != GX_NEXTION_DUAL_STATE_BUTTON, GX_FALSE);
    char v[11] = {0};
    __utoa(img, v, 10);
    u16 len_cmd = strlen(btn->base_obj.name) + 10 + 7; //".pic2="+'\0'=7
    char *cmd = malloc(sizeof(char) * len_cmd);
    strcat(cmd, btn->base_obj.name);
    strcat(cmd, ".pic2=");
    strcat(cmd, v);
    gx_nextion_send_cmd(device, cmd);
    free(cmd);
    return gx_cmd_finished(device);
}

GxBool gx_nextion_ds_button_set_active_backgroud_image_crop(GxNextionDSButton *btn, u32 img)
{
    GxNextion *device = gx_nextion_current_device();
    return_val_if(!device, GX_FALSE);
    return_val_if(btn->base_obj.obj_type != GX_NEXTION_DUAL_STATE_BUTTON, GX_FALSE);
    char v[11] = {0};
    __utoa(img, v, 10);
    u16 len_cmd = strlen(btn->base_obj.name) + 10 + 8; //".picc2="+'\0'=8
    char *cmd = malloc(sizeof(char) * len_cmd);
    strcat(cmd, btn->base_obj.name);
    strcat(cmd, ".picc2=");
    strcat(cmd, v);
    gx_nextion_send_cmd(device, cmd);
    free(cmd);
    return gx_cmd_finished(device);
}

GxBool gx_nextion_ds_button_set_text_color(GxNextionDSButton *btn, u16 clr)
{
    return gx_nextion_set_objt_foreground_color(btn, GX_NEXTION_DUAL_STATE_BUTTON, clr);
}

GxBool gx_nextion_ds_button_set_active_text_color(GxNextionDSButton *btn, u16 clr)
{
    GxNextion *device = gx_nextion_current_device();
    return_val_if(!device, GX_FALSE);
    return_val_if(btn->base_obj.obj_type != GX_NEXTION_DUAL_STATE_BUTTON, GX_FALSE);
    char v[6] = {0};
    __utoa(clr, v, 10);
    u16 len_cmd = strlen(btn->base_obj.name) + 5 + 7; //".pco2="+'\0'=7
    char *cmd = malloc(sizeof(char) * len_cmd);
    strcat(cmd, btn->base_obj.name);
    strcat(cmd, ".pco2=");
    strcat(cmd, v);
    gx_nextion_send_cmd(device, cmd);
    free(cmd);
    return gx_cmd_finished(device);
}

GxBool gx_nextion_ds_button_set_text_h_alignment(GxNextionDSButton *btn, u8 h_alignment)
{
    return gx_nextion_set_objt_text_hor_alignment(btn, GX_NEXTION_DUAL_STATE_BUTTON, h_alignment);
}

GxBool gx_nextion_ds_button_set_text_v_alignment(GxNextionDSButton *btn, u8 v_alignment)
{
    return gx_nextion_set_objt_text_ver_alignment(btn, GX_NEXTION_DUAL_STATE_BUTTON, v_alignment);
}

GxBool gx_nextion_ds_button_set_text(GxNextionDSButton *btn, const char *txt)
{
    return gx_nextion_set_objt_text(btn, GX_NEXTION_DUAL_STATE_BUTTON, txt);
}

GxBool gx_nextion_ds_button_set_text_wrap(GxNextionDSButton *btn, GxBool wrap)
{
    return gx_nextion_set_objt_text_wrap(btn, GX_NEXTION_DUAL_STATE_BUTTON, wrap);
}
