/**
 * Copyright (c) 2023 I Gede Yogi Astawan
 *
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include "gx_nextion_progress_bar.h"

GxNextionProgressBar gihex_nextion_prog_bar_bind(u8 pid, u8 cid, const char *name)
{
    GxNextionProgressBar o = {
        .base_obj = bind_gx_nextion_object_base(GX_NEXTION_PROGRESS_BAR, pid, cid, name),
        .on_click = NULL,
        .on_release = NULL,
        .__data_click = NULL,
        .__data_release = NULL};
    return o;
}

void gx_nextion_prog_bar_onclick(GxNextionProgressBar *pbr, GxNextionCallback clbk, void *data)
{
    gx_nextion_set_objt_onclick(pbr, GX_NEXTION_PROGRESS_BAR, clbk, data);
}

void gx_nextion_prog_bar_onrelease(GxNextionProgressBar *pbr, GxNextionCallback clbk, void *data)
{
    gx_nextion_set_objt_onrelease(pbr, GX_NEXTION_PROGRESS_BAR, clbk, data);
}

GxBool gx_nextion_prog_bar_set_value(GxNextionProgressBar *pbr, u32 value)
{
    return gx_nextion_set_objt_value(pbr, GX_NEXTION_PROGRESS_BAR, value);
}

GxBool gx_nextion_prog_bar_get_value(GxNextionProgressBar *pbr, u32 *value)
{
    i32 tmp = 0;
    GxBool ret = gx_nextion_get_objt_value(pbr, GX_NEXTION_PROGRESS_BAR, &tmp);
    *value = (u32)tmp;
    return ret;
}

GxBool gx_nextion_prog_bar_set_background_color(GxNextionProgressBar *pbr, u16 clr)
{
    return gx_nextion_set_objt_background_color(pbr, GX_NEXTION_PROGRESS_BAR, clr);
}

GxBool gx_nextion_prog_bar_set_foreground_color(GxNextionProgressBar *pbr, u16 clr)
{
    return gx_nextion_set_objt_foreground_color(pbr, GX_NEXTION_PROGRESS_BAR, clr);
}

GxBool gx_nextion_prog_bar_set_background_img(GxNextionProgressBar *pbr, u32 img)
{
    GxNextion *device = gx_nextion_current_device();
    return_val_if(!device, GX_FALSE);
    return_val_if(pbr->base_obj.obj_type != GX_NEXTION_PROGRESS_BAR, GX_FALSE);
    char v[11] = {0};
    __utoa(img, v, 10);
    u16 len_cmd = strlen(pbr->base_obj.name) + 10 + 7; //".bpic="+'\0'=7
    char *cmd = malloc(sizeof(char) * len_cmd);
    strcat(cmd, pbr->base_obj.name);
    strcat(cmd, ".bpic=");
    strcat(cmd, v);
    gx_nextion_send_cmd(device, cmd);
    free(cmd);
    return gx_cmd_finished(device);
}

GxBool gx_nextion_prog_bar_set_foreground_img(GxNextionProgressBar *pbr, u32 img)
{
    GxNextion *device = gx_nextion_current_device();
    return_val_if(!device, GX_FALSE);
    return_val_if(pbr->base_obj.obj_type != GX_NEXTION_PROGRESS_BAR, GX_FALSE);
    char v[11] = {0};
    __utoa(img, v, 10);
    u16 len_cmd = strlen(pbr->base_obj.name) + 10 + 7; //".ppic="+'\0'=7
    char *cmd = malloc(sizeof(char) * len_cmd);
    strcat(cmd, pbr->base_obj.name);
    strcat(cmd, ".ppic=");
    strcat(cmd, v);
    gx_nextion_send_cmd(device, cmd);
    free(cmd);
    return gx_cmd_finished(device);
}
