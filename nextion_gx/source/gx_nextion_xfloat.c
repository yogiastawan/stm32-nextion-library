/**
 * Copyright (c) 2023 I Gede Yogi Astawan
 *
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include "gx_nextion_xfloat.h"

GxNextionXFloat gx_nextion_xfloat_bind(u8 pid, u8 cid, const char *name)
{
    GxNextionXFloat o = {
        .base_obj = bind_gx_nextion_object_base(GX_NEXTION_XFLOAT, pid, cid, name),
        .on_click = NULL,
        .on_release = NULL,
        .__data_click = NULL,
        .__data_release = NULL};
    return o;
}

void gx_nextion_xfloat_onclick(GxNextionXFloat *flt, GxNextionCallback clbk, void *data)
{
    gx_nextion_set_objt_onclick(flt, GX_NEXTION_XFLOAT, clbk, data);
}

void gx_nextion_xfloat_onrelease(GxNextionXFloat *flt, GxNextionCallback clbk, void *data)
{
    gx_nextion_set_objt_onrelease(flt, GX_NEXTION_XFLOAT, clbk, data);
}

GxBool gx_nextion_xfloat_set_value(GxNextionXFloat *flt, i32 value)
{
    return gx_nextion_set_objt_value(flt, GX_NEXTION_XFLOAT, value);
}

GxBool gx_nextion_xfloat_get_value(GxNextionXFloat *flt, i32 *value)
{
    return gx_nextion_get_objt_value(flt, GX_NEXTION_XFLOAT, value);
}

GxBool gx_nextion_xfloat_set_font(GxNextionXFloat *flt, u32 font_id)
{
    return gx_nextion_set_objt_font(flt, GX_NEXTION_XFLOAT, font_id);
}

GxBool gx_nextion_xfloat_set_background_color(GxNextionXFloat *flt, u16 clr)
{
    return gx_nextion_set_objt_background_color(flt, GX_NEXTION_XFLOAT, clr);
}

GxBool gx_nextion_xfloat_set_text_color(GxNextionXFloat *flt, u16 clr)
{
    return gx_nextion_set_objt_foreground_color(flt, GX_NEXTION_XFLOAT, clr);
}

GxBool gx_nextion_xfloat_set_background_image(GxNextionXFloat *flt, u32 img_id)
{
    return gx_nextion_set_objt_background_img(flt, GX_NEXTION_XFLOAT, img_id);
}

GxBool gx_nextion_xfloat_set_background_image_crop(GxNextionXFloat *flt, u32 img_id)
{
    return gx_nextion_set_objt_background_crop(flt, GX_NEXTION_XFLOAT, img_id);
}

GxBool gx_nextion_xfloat_set_text_h_alignment(GxNextionXFloat *flt, u8 h_alignment)
{
    return gx_nextion_set_objt_text_hor_alignment(flt, GX_NEXTION_XFLOAT, h_alignment);
}

GxBool gx_nextion_xfloat_set_text_v_alignment(GxNextionXFloat *flt, u8 v_alignment)
{
    return gx_nextion_set_objt_text_ver_alignment(flt, GX_NEXTION_XFLOAT, v_alignment);
}

GxBool gx_nextion_xfloat_set_wrap(GxNextionXFloat *flt, GxBool wrap)
{
    return gx_nextion_set_objt_text_wrap(flt, GX_NEXTION_XFLOAT, wrap);
}

GxBool gx_nextion_xfloat_horizontal_spacing(GxNextionXFloat *flt, u8 space)
{
    GxNextion *device = gx_nextion_current_device();
    return_val_if(!device, GX_FALSE);
    return_val_if(flt->base_obj.obj_type != GX_NEXTION_XFLOAT, GX_FALSE);
    // set
    char v[4] = {0};
    __utoa(space, v, 10);
    u16 len_cmd = strlen(flt->base_obj.name) + 3 + 7; //".spax="+'\0'=7
    char *cmd = malloc(sizeof(char) * len_cmd);
    strcat(cmd, flt->base_obj.name);
    strcat(cmd, ".spax=");
    strcat(cmd, v);
    gx_nextion_send_cmd(device, cmd);
    free(cmd);
    return gx_cmd_finished(device);
}

GxBool gx_nextion_xfloat_vertical_spacing(GxNextionXFloat *flt, u8 space)
{
    GxNextion *device = gx_nextion_current_device();
    return_val_if(!device, GX_FALSE);
    return_val_if(flt->base_obj.obj_type != GX_NEXTION_XFLOAT, GX_FALSE);
    char v[4] = {0};
    __utoa(space, v, 10);
    u16 len_cmd = strlen(flt->base_obj.name) + 3 + 7; //".spay="+'\0'=7
    char *cmd = malloc(sizeof(char) * len_cmd);
    strcat(cmd, flt->base_obj.name);
    strcat(cmd, ".spay=");
    strcat(cmd, v);
    gx_nextion_send_cmd(device, cmd);
    free(cmd);
    return gx_cmd_finished(device);
}

GxBool gx_nextion_xfloat_set_point_right(GxNextionXFloat *flt, u8 point)
{
    GxNextion *device = gx_nextion_current_device();
    return_val_if(!device, GX_FALSE);
    return_val_if(flt->base_obj.obj_type != GX_NEXTION_XFLOAT, GX_FALSE);
    return_val_if(point > 10, GX_FALSE);
    // set
    char v[4] = {0};
    __utoa(point, v, 10);
    u16 len_cmd = strlen(flt->base_obj.name) + 3 + 6; //".ws0="+'\0'=6
    char *cmd = malloc(sizeof(char) * len_cmd);
    strcat(cmd, flt->base_obj.name);
    strcat(cmd, ".ws0=");
    strcat(cmd, v);
    gx_nextion_send_cmd(device, cmd);
    free(cmd);
    return gx_cmd_finished(device);
}

GxBool gx_nextion_xfloat_set_point_left(GxNextionXFloat *flt, u8 point)
{
    GxNextion *device = gx_nextion_current_device();
    return_val_if(!device, GX_FALSE);
    return_val_if(flt->base_obj.obj_type != GX_NEXTION_XFLOAT, GX_FALSE);
    return_val_if(point > 8, GX_FALSE);
    // set
    char v[4] = {0};
    __utoa(point, v, 10);
    u16 len_cmd = strlen(flt->base_obj.name) + 3 + 6; //".ws1="+'\0'=6
    char *cmd = malloc(sizeof(char) * len_cmd);
    strcat(cmd, flt->base_obj.name);
    strcat(cmd, ".ws1=");
    strcat(cmd, v);
    gx_nextion_send_cmd(device, cmd);
    free(cmd);
    return gx_cmd_finished(device);
}
