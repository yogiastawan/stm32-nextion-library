/**
 * Copyright (c) 2023 I Gede Yogi Astawan
 *
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include "gx_nextion_scroll_text.h"

GxNextionScrollText gx_nextion_scroll_text_bind(u8 pid, u8 cid, const char *name)
{
    GxNextionScrollText o = {
        .base_obj = bind_gx_nextion_object_base(GX_NEXTION_TEXT, pid, cid, name),
        .on_click = NULL,
        .on_release = NULL,
        .__data_click = NULL,
        .__data_release = NULL};
    return o;
}

void gx_nextion_scroll_text_onclick(GxNextionScrollText *obj, GxNextionCallback clbk, void *data)
{
    gx_nextion_set_objt_onclick(obj, GX_NEXTION_SCROLLING_TEXT, clbk, data);
}

void gx_nextion_scroll_text_onrelease(GxNextionScrollText *obj, GxNextionCallback clbk, void *data)
{
    gx_nextion_set_objt_onrelease(obj, GX_NEXTION_SCROLLING_TEXT, clbk, data);
}

GxBool gx_nextion_scroll_text_set_text(GxNextionScrollText *obj, const char *text)
{
    return gx_nextion_set_objt_text(obj, GX_NEXTION_TEXT, text);
}

u16 gx_nextion_scroll_text_get_text(GxNextionScrollText *obj, char *buffer, u16 len)
{
    return gx_nextion_get_objt_text(obj, GX_NEXTION_TEXT, buffer, len);
}

GxBool gx_nextion_scroll_text_set_background_color(GxNextionScrollText *txt, u16 clr)
{
    return gx_nextion_set_objt_background_color(txt, GX_NEXTION_TEXT, clr);
}

GxBool gx_nextion_scroll_text_set_text_color(GxNextionScrollText *txt, u16 clr)
{
    return gx_nextion_set_objt_foreground_color(txt, GX_NEXTION_TEXT, clr);
}

GxBool gx_nextion_scroll_text_set_font(GxNextionScrollText *txt, u32 font_id)
{
    return gx_nextion_set_objt_font(txt, GX_NEXTION_SCROLLING_TEXT, font_id);
}

GxBool gx_nextion_scroll_text_set_background_image(GxNextionScrollText *txt, u32 img_id)
{
    return gx_nextion_set_objt_background_img(txt, GX_NEXTION_TEXT, img_id);
}

GxBool gx_nextion_scroll_text_set_background_image_crop(GxNextionScrollText *txt, u32 img_id)
{
    return gx_nextion_set_objt_background_crop(txt, GX_NEXTION_SCROLLING_TEXT, img_id);
}

GxBool gx_nextion_scroll_text_set_label_h_alignment(GxNextionScrollText *txt, u8 h_alignment)
{
    return gx_nextion_set_objt_text_hor_alignment(txt, GX_NEXTION_TEXT, h_alignment);
}

GxBool gx_nextion_scroll_text_set_label_v_alignment(GxNextionScrollText *txt, u8 v_alignment)
{
    return gx_nextion_set_objt_text_ver_alignment(txt, GX_NEXTION_TEXT, v_alignment);
}

GxBool gx_nextion_scroll_text_set_wrap(GxNextionScrollText *txt, GxBool wrap)
{
    return gx_nextion_set_objt_text_wrap(txt, GX_NEXTION_TEXT, wrap);
}

GxBool gx_nextion_scroll_text_set_direction(GxNextionScrollText *txt, u8 direction)
{
    GxNextion *device = gx_nextion_current_device();
    return_val_if(!device, GX_FALSE);
    return_val_if(txt->base_obj.obj_type != GX_NEXTION_SCROLLING_TEXT, GX_FALSE);
    char v[4] = {0};
    __utoa(direction, v, 10);
    u16 len_cmd = strlen(txt->base_obj.name) + 3 + 6; //".dir="+'\0'=6
    char *cmd = malloc(sizeof(char) * len_cmd);
    strcat(cmd, txt->base_obj.name);
    strcat(cmd, ".dir=");
    strcat(cmd, v);
    gx_nextion_send_cmd(device, cmd);
    free(cmd);
    return gx_cmd_finished(device);
}

GxBool gx_nextion_scroll_text_set_distance(GxNextionScrollText *txt, u8 distance_in_ms)
{
    GxNextion *device = gx_nextion_current_device();
    return_val_if(!device, GX_FALSE);
    return_val_if(txt->base_obj.obj_type != GX_NEXTION_SCROLLING_TEXT, GX_FALSE);
    return_val_if(distance_in_ms < 2 || distance_in_ms > 50, GX_FALSE);
    char v[4] = {0};
    __utoa(distance_in_ms, v, 10);
    u16 len_cmd = strlen(txt->base_obj.name) + 3 + 6; //".dis="+'\0'=6
    char *cmd = malloc(sizeof(char) * len_cmd);
    strcat(cmd, txt->base_obj.name);
    strcat(cmd, ".dis=");
    strcat(cmd, v);
    gx_nextion_send_cmd(device, cmd);
    free(cmd);
    return gx_cmd_finished(device);
}

GxBool gx_nextion_scroll_text_set_interval_ms(GxNextionScrollText *txt, u16 interval_ms)
{
    GxNextion *device = gx_nextion_current_device();
    return_val_if(!device, GX_FALSE);
    return_val_if(txt->base_obj.obj_type != GX_NEXTION_SCROLLING_TEXT, GX_FALSE);
    return_val_if(interval_ms < 80, GX_FALSE);
    // set
    char v[6] = {0};
    __utoa(interval_ms, v, 10);
    u16 len_cmd = strlen(txt->base_obj.name) + 5 + 6; //".tim="+'\0'=6
    char *cmd = malloc(sizeof(char) * len_cmd);
    strcat(cmd, txt->base_obj.name);
    strcat(cmd, ".tim=");
    strcat(cmd, v);
    gx_nextion_send_cmd(device, cmd);
    free(cmd);
    return gx_cmd_finished(device);
}

GxBool gx_nextion_scroll_text_enable(GxNextionScrollText *txt, GxBool enable)
{
    GxNextion *device = gx_nextion_current_device();
    return_val_if(!device, GX_FALSE);
    return_val_if(txt->base_obj.obj_type != GX_NEXTION_SCROLLING_TEXT, GX_FALSE);
    char v[4] = {0};
    __utoa(enable, v, 10);
    u16 len_cmd = strlen(txt->base_obj.name) + 3 + 5; //".en="+'\0'=5
    char *cmd = malloc(sizeof(char) * len_cmd);
    strcat(cmd, txt->base_obj.name);
    strcat(cmd, ".en=");
    strcat(cmd, v);
    gx_nextion_send_cmd(device, cmd);
    free(cmd);
    return gx_cmd_finished(device);
}

GxBool gx_nextion_scroll_text_horizontal_spacing(GxNextionScrollText *txt, u8 space)
{
    GxNextion *device = gx_nextion_current_device();
    return_val_if(!device, GX_FALSE);
    return_val_if(txt->base_obj.obj_type != GX_NEXTION_SCROLLING_TEXT, GX_FALSE);
    char v[4] = {0};
    __utoa(space, v, 10);
    u16 len_cmd = strlen(txt->base_obj.name) + 3 + 7; //".spax="+'\0'=7
    char *cmd = malloc(sizeof(char) * len_cmd);
    strcat(cmd, txt->base_obj.name);
    strcat(cmd, ".spax=");
    strcat(cmd, v);
    gx_nextion_send_cmd(device, cmd);
    free(cmd);
    return gx_cmd_finished(device);
}

GxBool gx_nextion_scroll_text_vertical_spacing(GxNextionScrollText *txt, u8 space)
{
    GxNextion *device = gx_nextion_current_device();
    return_val_if(!device, GX_FALSE);
    return_val_if(txt->base_obj.obj_type != GX_NEXTION_SCROLLING_TEXT, GX_FALSE);
    char v[4] = {0};
    __utoa(space, v, 10);
    u16 len_cmd = strlen(txt->base_obj.name) + 3 + 7; //".spay="+'\0'=7
    char *cmd = malloc(sizeof(char) * len_cmd);
    strcat(cmd, txt->base_obj.name);
    strcat(cmd, ".spay=");
    strcat(cmd, v);
    gx_nextion_send_cmd(device, cmd);
    free(cmd);
    return gx_cmd_finished(device);
}
