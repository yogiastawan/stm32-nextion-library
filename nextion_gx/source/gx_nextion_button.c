/**
 * Copyright (c) 2023 I Gede Yogi Astawan
 *
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include "gx_nextion_button.h"

GxNextionButton gx_nextion_button_bind(u8 pid, u8 cid, const char *name)
{
    GxNextionButton o = {
        .base_obj = bind_gx_nextion_object_base(GX_NEXTION_BUTTON, pid, cid, name),
        .on_click = NULL,
        .on_release = NULL,
    };
    return o;
}

void gx_nextion_button_onclick(GxNextionButton *obj, GxNextionCallback clbk, void *data)
{
    gx_nextion_set_objt_onclick(obj, GX_NEXTION_BUTTON, clbk, data);
}

void gx_nextion_button_onrelease(GxNextionButton *obj, GxNextionCallback clbk, void *data)
{
    gx_nextion_set_objt_onrelease(obj, GX_NEXTION_BUTTON, clbk, data);
}

GxBool gx_nextion_button_set_label(GxNextionButton *obj, const char *label)
{
    return gx_nextion_set_objt_text(obj, GX_NEXTION_BUTTON, label);
}

u16 gx_nextion_button_get_label(GxNextionButton *obj, char *buffer, u16 len)
{
    return gx_nextion_get_objt_text(obj, GX_NEXTION_BUTTON, buffer, len);
}

GxBool gx_nextion_button_set_font(GxNextionButton *obj, u32 font_id)
{
    return gx_nextion_set_objt_font(obj, GX_NEXTION_BUTTON, font_id);
}

GxBool gx_nextion_button_set_background_color(GxNextionButton *btn, u16 clr)
{
    return gx_nextion_set_objt_background_color(btn, GX_NEXTION_BUTTON, clr);
}

GxBool gx_nextion_button_set_onclick_background_color(GxNextionButton *btn, u16 clr)
{
    GxNextion *device = gx_nextion_current_device();
    return_val_if(!device, GX_FALSE);
    return_val_if(btn->base_obj.obj_type != GX_NEXTION_BUTTON, GX_FALSE);
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

GxBool gx_nextion_button_set_label_color(GxNextionButton *btn, u16 clr)
{
    return gx_nextion_set_objt_foreground_color(btn, GX_NEXTION_BUTTON, clr);
}

GxBool gx_nextion_button_set_onclick_label_color(GxNextionButton *btn, u16 clr)
{
    GxNextion *device = gx_nextion_current_device();
    return_val_if(!device, GX_FALSE);
    return_val_if(btn->base_obj.obj_type != GX_NEXTION_BUTTON, GX_FALSE);
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

GxBool gx_nextion_button_set_background_image(GxNextionButton *btn, u32 img_id)
{
    return gx_nextion_set_objt_background_img(btn, GX_NEXTION_BUTTON, img_id);
}

GxBool gx_nextion_button_set_onclick_background_image(GxNextionButton *btn, u32 img_id)
{
    GxNextion *device = gx_nextion_current_device();
    return_val_if(!device, GX_FALSE);
    return_val_if(btn->base_obj.obj_type != GX_NEXTION_BUTTON, GX_FALSE);
    // set onclick img
    char v[11] = {0};
    __utoa(img_id, v, 10);
    u16 len_cmd = strlen(btn->base_obj.name) + 10 + 7; //".pic2="+'\0'=7
    char *cmd = malloc(sizeof(char) * len_cmd);
    strcat(cmd, btn->base_obj.name);
    strcat(cmd, ".pic2=");
    strcat(cmd, v);
    gx_nextion_send_cmd(device, cmd);
    free(cmd);
    return gx_cmd_finished(device);
}

GxBool gx_nextion_button_set_background_image_crop(GxNextionButton *btn, u32 img_id)
{
    return gx_nextion_set_objt_background_crop(btn, GX_NEXTION_BUTTON, img_id);
}

GxBool gx_nextion_button_set_onclick_background_image_crop(GxNextionButton *btn, u32 img_id)
{
    GxNextion *device = gx_nextion_current_device();
    return_val_if(!device, GX_FALSE);
    return_val_if(btn->base_obj.obj_type != GX_NEXTION_BUTTON, GX_FALSE);
    // set onclick img
    char v[11] = {0};
    __utoa(img_id, v, 10);
    u16 len_cmd = strlen(btn->base_obj.name) + 10 + 8; //".picc2="+'\0'=8
    char *cmd = malloc(sizeof(char) * len_cmd);
    strcat(cmd, btn->base_obj.name);
    strcat(cmd, ".picc2=");
    strcat(cmd, v);
    gx_nextion_send_cmd(device, cmd);
    free(cmd);
    return gx_cmd_finished(device);
}

GxBool gx_nextion_button_set_label_h_alignment(GxNextionButton *btn, u8 h_alignment)
{
    return gx_nextion_set_objt_text_hor_alignment(btn, GX_NEXTION_BUTTON, h_alignment);
}

GxBool gx_nextion_button_set_label_v_alignment(GxNextionButton *btn, u8 v_alignment)
{
    return gx_nextion_set_objt_text_ver_alignment(btn, GX_NEXTION_BUTTON, v_alignment);
}

GxBool gx_nextion_button_set_label_wrap(GxNextionButton *btn, GxBool wrap)
{
    return gx_nextion_set_objt_text_wrap(btn, GX_NEXTION_BUTTON, wrap);
}
