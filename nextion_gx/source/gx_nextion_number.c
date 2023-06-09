/**
 * Copyright (c) 2023 I Gede Yogi Astawan
 *
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include "gx_nextion_number.h"

GxNextionNumber gx_nextion_number_bind(u8 pid, u8 cid, const char *name)
{
    GxNextionNumber o = {
        .base_obj = bind_gx_nextion_object_base(GX_NEXTION_NUMBER, pid, cid, name),
        .on_click = NULL,
        .on_release = NULL,
        .__data_click = NULL,
        .__data_release = NULL};

    return o;
}

void gx_nextion_number_onclick(GxNextionNumber *obj, GxNextionCallback clbk, void *data)
{
    gx_nextion_set_objt_onclick(obj, GX_NEXTION_NUMBER, clbk, data);
}

void gx_nextion_number_onrelease(GxNextionNumber *obj, GxNextionCallback clbk, void *data)
{
    gx_nextion_set_objt_onrelease(obj, GX_NEXTION_NUMBER, clbk, data);
}

GxBool gx_nextion_number_set_value(GxNextionNumber *obj, i32 value)
{
    return gx_nextion_set_objt_value(obj, GX_NEXTION_NUMBER, value);
}

GxBool gx_nextion_number_get_value(GxNextionNumber *obj, i32 *value)
{
    return gx_nextion_get_objt_value(obj, GX_NEXTION_NUMBER, value);
}

GxBool gx_nextion_number_set_background_color(GxNextionNumber *nmb, u16 clr)
{
    return gx_nextion_set_objt_background_color(nmb, GX_NEXTION_NUMBER, clr);
}

GxBool gx_nextion_number_set_text_color(GxNextionNumber *nmb, u16 clr)
{
    return gx_nextion_set_objt_foreground_color(nmb, GX_NEXTION_NUMBER, clr);
}

GxBool gx_nextion_number_set_font(GxNextionNumber *nmb, u32 font_id)
{
    return gx_nextion_set_objt_font(nmb, GX_NEXTION_NUMBER, font_id);
}

GxBool gx_nextion_number_set_background_image(GxNextionNumber *nmb, u32 img_id)
{
    return gx_nextion_set_objt_background_img(nmb, GX_NEXTION_NUMBER, img_id);
}

GxBool gx_nextion_number_set_background_image_crop(GxNextionNumber *nmb, u32 img_id)
{
    return gx_nextion_set_objt_background_crop(nmb, GX_NEXTION_NUMBER, img_id);
}

GxBool gx_nextion_number_set_text_h_alignment(GxNextionNumber *nmb, u8 h_alignment)
{
    return gx_nextion_set_objt_text_hor_alignment(nmb, GX_NEXTION_NUMBER, h_alignment);
}

GxBool gx_nextion_number_set_text_v_alignment(GxNextionNumber *nmb, u8 v_alignment)
{
    return gx_nextion_set_objt_text_ver_alignment(nmb, GX_NEXTION_NUMBER, v_alignment);
}

GxBool gx_nextion_number_set_wrap(GxNextionNumber *nmb, GxBool wrap)
{
    return gx_nextion_set_objt_text_wrap(nmb, GX_NEXTION_NUMBER, wrap);
}

GxBool gx_nextion_number_set_format(GxNextionNumber *nmb, u8 format)
{
    GxNextion *device = gx_nextion_current_device();
    return_val_if(!device, GX_FALSE);
    return_val_if(nmb->base_obj.obj_type != GX_NEXTION_NUMBER, GX_FALSE);
    // set format
    char v[4] = {0};
    __utoa(format, v, 10);
    u16 len_cmd = strlen(nmb->base_obj.name) + 3 + 9; //".format="+'\0'=9
    char *cmd = malloc(sizeof(char) * len_cmd);
    strcat(cmd, nmb->base_obj.name);
    strcat(cmd, ".format=");
    strcat(cmd, v);
    gx_nextion_send_cmd(device, cmd);
    free(cmd);
    return gx_cmd_finished(device);
}

GxBool gx_nextion_number_horizontal_spacing(GxNextionNumber *nmb, u8 space)
{
    GxNextion *device = gx_nextion_current_device();
    return_val_if(!device, GX_FALSE);
    return_val_if(nmb->base_obj.obj_type != GX_NEXTION_NUMBER, GX_FALSE);
    char v[4] = {0};
    __utoa(space, v, 10);
    u16 len_cmd = strlen(nmb->base_obj.name) + 3 + 7; //".spax="+'\0'=7
    char *cmd = malloc(sizeof(char) * len_cmd);
    strcat(cmd, nmb->base_obj.name);
    strcat(cmd, ".spax=");
    strcat(cmd, v);
    gx_nextion_send_cmd(device, cmd);
    free(cmd);
    return gx_cmd_finished(device);
}

GxBool gx_nextion_number_vertical_spacing(GxNextionNumber *nmb, u8 space)
{
    GxNextion *device = gx_nextion_current_device();
    return_val_if(!device, GX_FALSE);
    return_val_if(nmb->base_obj.obj_type != GX_NEXTION_NUMBER, GX_FALSE);
    char v[4] = {0};
    __utoa(space, v, 10);
    u16 len_cmd = strlen(nmb->base_obj.name) + 3 + 7; //".spay="+'\0'=7
    char *cmd = malloc(sizeof(char) * len_cmd);
    strcat(cmd, nmb->base_obj.name);
    strcat(cmd, ".spay=");
    strcat(cmd, v);
    gx_nextion_send_cmd(device, cmd);
    free(cmd);
    return gx_cmd_finished(device);
}

GxBool gx_nextion_number_set_length(GxNextionNumber *nmb, u8 length)
{
    GxNextion *device = gx_nextion_current_device();
    return_val_if(!device, GX_FALSE);
    return_val_if(nmb->base_obj.obj_type != GX_NEXTION_NUMBER, GX_FALSE);
    return_val_if(length > 15, GX_FALSE);
    char v[4] = {0};
    __utoa(length, v, 10);
    u16 len_cmd = strlen(nmb->base_obj.name) + 3 + 7; //".lenth="+'\0'=8
    char *cmd = malloc(sizeof(char) * len_cmd);
    strcat(cmd, nmb->base_obj.name);
    strcat(cmd, ".lenth=");
    strcat(cmd, v);
    gx_nextion_send_cmd(device, cmd);
    free(cmd);
    return gx_cmd_finished(device);
}
