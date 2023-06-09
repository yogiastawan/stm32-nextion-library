/**
 * Copyright (c) 2023 I Gede Yogi Astawan
 *
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include "gx_nextion_waveform.h"

GxNextionWaveform gx_nextion_waveform_bind(u8 pid, u8 cid, const char *name)
{
    GxNextionWaveform o = {
        .base_obj = bind_gx_nextion_object_base(GX_NEXTION_WAVEFORM, pid, cid, name),
        .on_click = NULL,
        .on_release = NULL,
        .__data_click = NULL,
        .__data_release = NULL};
    return o;
}

void gx_nextion_waveform_set_onclick(GxNextionWaveform *wave, GxNextionCallback clbk, void *data)
{
    gx_nextion_set_objt_onclick(wave, GX_NEXTION_WAVEFORM, clbk, data);
}

void gx_nextion_waveform_set_onrelease(GxNextionWaveform *wave, GxNextionCallback clbk, void *data)
{
    gx_nextion_set_objt_onrelease(wave, GX_NEXTION_WAVEFORM, clbk, data);
}

GxBool gx_nextion_waveform_set_background_color(GxNextionWaveform *wave, u16 clr)
{
    return gx_nextion_set_objt_background_color(wave, GX_NEXTION_WAVEFORM, clr);
}

GxBool gx_nextion_waveform_set_background_image(GxNextionWaveform *wave, u32 img)
{
    return gx_nextion_set_objt_background_img(wave, GX_NEXTION_WAVEFORM, img);
}

GxBool gx_nextion_waveform_set_background_image_crop(GxNextionWaveform *wave, u32 img)
{
    return gx_nextion_set_objt_background_crop(wave, GX_NEXTION_WAVEFORM, img);
}

GxBool gx_nextion_waveform_set_grid_color(GxNextionWaveform *wave, u16 clr)
{
    GxNextion *device = gx_nextion_current_device();
    return_val_if(!device, GX_FALSE);
    return_val_if(wave->base_obj.obj_type != GX_NEXTION_WAVEFORM, GX_FALSE);
    // set
    char v[6] = {0};
    __utoa(clr, v, 10);
    u16 len_cmd = strlen(wave->base_obj.name) + 5 + 6; //".gdc="+'\0'=6
    char *cmd = malloc(sizeof(char) * len_cmd);
    strcat(cmd, wave->base_obj.name);
    strcat(cmd, ".gdc=");
    strcat(cmd, v);
    gx_nextion_send_cmd(device, cmd);
    free(cmd);
    return gx_cmd_finished(device);
}

GxBool gx_nextion_waveform_set_grid_width(GxNextionWaveform *wave, u32 width)
{
    GxNextion *device = gx_nextion_current_device();
    return_val_if(!device, GX_FALSE);
    return_val_if(wave->base_obj.obj_type != GX_NEXTION_WAVEFORM, GX_FALSE);
    char v[11] = {0};
    __utoa(width, v, 10);
    u16 len_cmd = strlen(wave->base_obj.name) + 10 + 6; //".gdw="+'\0'=6
    char *cmd = malloc(sizeof(char) * len_cmd);
    strcat(cmd, wave->base_obj.name);
    strcat(cmd, ".gdw=");
    strcat(cmd, v);
    gx_nextion_send_cmd(device, cmd);
    free(cmd);
    return gx_cmd_finished(device);
}

GxBool gx_nextion_waveform_set_grid_height(GxNextionWaveform *wave, u32 height)
{
    GxNextion *device = gx_nextion_current_device();
    return_val_if(!device, GX_FALSE);
    return_val_if(wave->base_obj.obj_type != GX_NEXTION_WAVEFORM, GX_FALSE);
    char v[11] = {0};
    __utoa(height, v, 10);
    u16 len_cmd = strlen(wave->base_obj.name) + 10 + 6; //".gdh="+'\0'=6
    char *cmd = malloc(sizeof(char) * len_cmd);
    strcat(cmd, wave->base_obj.name);
    strcat(cmd, ".gdh=");
    strcat(cmd, v);
    gx_nextion_send_cmd(device, cmd);
    free(cmd);
    return gx_cmd_finished(device);
}

GxBool gx_nextion_waveform_set_data_scaling(GxNextionWaveform *wave, u8 scale)
{
    GxNextion *device = gx_nextion_current_device();
    return_val_if(!device, GX_FALSE);
    return_val_if(wave->base_obj.obj_type != GX_NEXTION_WAVEFORM, GX_FALSE);
    return_val_if(scale < 10 || scale > 100, GX_FALSE);
    char v[6] = {0};
    __utoa(scale, v, 10);
    u16 len_cmd = strlen(wave->base_obj.name) + 5 + 6; //".dis="+'\0'=6
    char *cmd = malloc(sizeof(char) * len_cmd);
    strcat(cmd, wave->base_obj.name);
    strcat(cmd, ".dis=");
    strcat(cmd, v);
    gx_nextion_send_cmd(device, cmd);
    free(cmd);
    return gx_cmd_finished(device);
}

GxBool gx_nextion_waveform_set_channel_color(GxNextionWaveform *wave, u8 channel_index, u16 clr)
{
    GxNextion *device = gx_nextion_current_device();
    return_val_if(!device, GX_FALSE);
    return_val_if(wave->base_obj.obj_type != GX_NEXTION_WAVEFORM, GX_FALSE);
    return_val_if(channel_index <= 0 || channel_index > 4, GX_FALSE);
    // set
    char v[6] = {0};
    __utoa(clr, v, 10);
    char i[4] = {0};
    __utoa(channel_index, i, 10);
    u16 len_cmd = strlen(wave->base_obj.name) + 5 + 3 + 7; //".pcoX="+'\0'=7
    char *cmd = malloc(sizeof(char) * len_cmd);
    strcat(cmd, wave->base_obj.name);
    strcat(cmd, ".pco");
    strcat(cmd, i);
    strcat(cmd, "=");
    strcat(cmd, v);
    gx_nextion_send_cmd(device, cmd);
    free(cmd);
    return gx_cmd_finished(device);
}

GxBool gx_nextion_wave_form_add_data(GxNextionWaveform *wave, u8 channel_index, u8 data)
{
    GxNextion *device = gx_nextion_current_device();
    return_val_if(!device, GX_FALSE);
    return_val_if(wave->base_obj.obj_type != GX_NEXTION_WAVEFORM, GX_FALSE);
    return_val_if(channel_index <= 0 || channel_index > 4, GX_FALSE);

    // set=>add id,ch,val
    char id[4] = {0};
    __utoa(wave->base_obj.cid, id, 10);
    char ch[4] = {0};
    __utoa(channel_index, ch, 10);
    char dt[4] = {0};
    __utoa(data, dt, 10);
    u16 len_cmd = 9 + 7; //"add ,,"+'\0'=7
    char *cmd = malloc(sizeof(char) * len_cmd);
    strcat(cmd, "add ");
    strcat(cmd, id);
    strcat(cmd, ",");
    strcat(cmd, ch);
    strcat(cmd, ",");
    strcat(cmd, dt);
    gx_nextion_send_cmd(device, cmd);
    free(cmd);
    return gx_cmd_finished(device);
}

GxBool gx_nextion_wave_form_clear_data(GxNextionWaveform *wave, u8 channel_index)
{
    GxNextion *device = gx_nextion_current_device();
    return_val_if(!device, GX_FALSE);
    return_val_if(wave->base_obj.obj_type != GX_NEXTION_WAVEFORM, GX_FALSE);
    return_val_if(channel_index <= 0 || channel_index > 4, GX_FALSE);

    // set=>cle id,ch
    char id[4] = {0};
    __utoa(wave->base_obj.cid, id, 10);
    char ch[4] = {0};
    __utoa(channel_index, ch, 10);
    u16 len_cmd = strlen(wave->base_obj.name) + 6 + 7; //"cle ,"+'\0'=6
    char *cmd = malloc(sizeof(char) * len_cmd);
    strcat(cmd, "cle ");
    strcat(cmd, id);
    strcat(cmd, ",");
    strcat(cmd, ch);
    gx_nextion_send_cmd(device, cmd);
    free(cmd);
    return gx_cmd_finished(device);
}
