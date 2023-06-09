/**
 * Copyright (c) 2023 I Gede Yogi Astawan
 *
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include "gx_nextion_slider.h"

GxNextionSlider gx_nextion_slider_bind(u8 pid, u8 cid, const char *name)
{
    GxNextionSlider o = {
        .base_obj = bind_gx_nextion_object_base(GX_NEXTION_SLIDER, pid, cid, name),
        .on_click = NULL,
        .on_release = NULL,
        .__data_click = NULL,
        .__data_release = NULL};
    return o;
}

GxBool gx_nextion_slider_onclick(GxNextionSlider *slider, GxNextionCallback clbk, GxBool *data)
{
    gx_nextion_set_objt_onclick(slider, GX_NEXTION_SLIDER, clbk, data);
}

void gx_nextion_slider_onrelease(GxNextionSlider *slider, GxNextionCallback clbk, void *data)
{
    gx_nextion_set_objt_onrelease(slider, GX_NEXTION_SLIDER, clbk, data);
}

void gx_nextion_slider_onmove_cursor(GxNextionSlider *slider, GxNextionCallback clbk, void *data)
{
    // fix thizzz
}

GxBool gx_nextion_slider_set_value(GxNextionSlider *slider, u16 value)
{
    return gx_nextion_set_objt_value(slider, GX_NEXTION_SLIDER, (i32)value);
}

GxBool gx_nextion_slider_get_value(GxNextionSlider *slider, u16 *value)
{
    i32 tmp = 0;
    GxBool ret = gx_nextion_get_objt_value(slider, GX_NEXTION_SLIDER, &tmp);
    *value = (u16)tmp;
    return ret;
}

GxBool gx_nextion_slider_set_background_color(GxNextionSlider *slider, u16 clr)
{
    return gx_nextion_set_objt_background_color(slider, GX_NEXTION_SLIDER, clr);
}

GxBool gx_nextion_slider_set_background_img(GxNextionSlider *slider, u32 img)
{
    return gx_nextion_set_objt_background_img(slider, GX_NEXTION_SLIDER, img);
}

GxBool gx_nextion_slider_set_background_img_crop(GxNextionSlider *slider, u32 img)
{
    return gx_nextion_set_objt_background_crop(slider, GX_NEXTION_SLIDER, img);
}

GxBool gx_nextion_slider_set_foreground_color(GxNextionSlider *slider, u16 clr)
{
    GxNextion *device = gx_nextion_current_device();
    return_val_if(!device, GX_FALSE);
    return_val_if(slider->base_obj.obj_type != GX_NEXTION_SLIDER, GX_FALSE);
    // set
    char v[6] = {0};
    __utoa(clr, v, 10);
    u16 len_cmd = strlen(slider->base_obj.name) + 5 + 7; //".bco1="+'\0'=7
    char *cmd = malloc(sizeof(char) * len_cmd);
    strcat(cmd, slider->base_obj.name);
    strcat(cmd, ".bco1=");
    strcat(cmd, v);
    gx_nextion_send_cmd(device, cmd);
    free(cmd);
    return gx_cmd_finished(device);
}



GxBool gx_nextion_slider_set_foreground_img_crop(GxNextionSlider *slider, u32 img)
{
    GxNextion *device = gx_nextion_current_device();
    return_val_if(!device, GX_FALSE);
    return_val_if(slider->base_obj.obj_type != GX_NEXTION_SLIDER, GX_FALSE);
    // set
    char v[11] = {0};
    __utoa(img, v, 10);
    u16 len_cmd = strlen(slider->base_obj.name) + 10 + 8; //".picc1="+'\0'=8
    char *cmd = malloc(sizeof(char) * len_cmd);
    strcat(cmd, slider->base_obj.name);
    strcat(cmd, ".picc1=");
    strcat(cmd, v);
    gx_nextion_send_cmd(device, cmd);
    free(cmd);
    return gx_cmd_finished(device);
}

GxBool gx_nextion_slider_set_cursor_color(GxNextionSlider *slider, u16 clr)
{
    return gx_nextion_set_objt_foreground_color(slider, GX_NEXTION_SLIDER, clr);
}

GxBool gx_nextion_slider_set_cursor_img(GxNextionSlider *slider, u32 img)
{
    GxNextion *device = gx_nextion_current_device();
    return_val_if(!device, GX_FALSE);
    return_val_if(slider->base_obj.obj_type != GX_NEXTION_SLIDER, GX_FALSE);
    // set
    char v[11] = {0};
    __utoa(img, v, 10);
    u16 len_cmd = strlen(slider->base_obj.name) + 10 + 7; //".pic2="+'\0'=7
    char *cmd = malloc(sizeof(char) * len_cmd);
    strcat(cmd, slider->base_obj.name);
    strcat(cmd, ".pic2=");
    strcat(cmd, v);
    gx_nextion_send_cmd(device, cmd);
    free(cmd);
    return gx_cmd_finished(device);
}

GxBool gx_nextion_slider_set_max_value(GxNextionSlider *slider, u16 value)
{
    GxNextion *device = gx_nextion_current_device();
    return_val_if(!device, GX_FALSE);
    return_val_if(slider->base_obj.obj_type != GX_NEXTION_SLIDER, GX_FALSE);
    // set
    char v[6] = {0};
    __utoa(value, v, 10);
    u16 len_cmd = strlen(slider->base_obj.name) + 5 + 9; //".maxval="+'\0'=9
    char *cmd = malloc(sizeof(char) * len_cmd);
    strcat(cmd, slider->base_obj.name);
    strcat(cmd, ".maxval=");
    strcat(cmd, v);
    gx_nextion_send_cmd(device, cmd);
    free(cmd);
    return gx_cmd_finished(device);
}

GxBool gx_nextion_slider_set_min_value(GxNextionSlider *slider, u16 value)
{
    GxNextion *device = gx_nextion_current_device();
    return_val_if(!device, GX_FALSE);
    return_val_if(slider->base_obj.obj_type != GX_NEXTION_SLIDER, GX_FALSE);
    // set
    char v[6] = {0};
    __utoa(value, v, 10);
    u16 len_cmd = strlen(slider->base_obj.name) + 5 + 9; //".minval="+'\0'=9
    char *cmd = malloc(sizeof(char) * len_cmd);
    strcat(cmd, slider->base_obj.name);
    strcat(cmd, ".minval=");
    strcat(cmd, v);
    gx_nextion_send_cmd(device, cmd);
    free(cmd);
    return gx_cmd_finished(device);
}
