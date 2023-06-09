/**
 * Copyright (c) 2023 I Gede Yogi Astawan
 *
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include "gx_nextion_timer.h"

GxNextionTimer gx_nextion_timer_bind(u8 pid, u8 cid, const char *name)
{
    GxNextionTimer o = {
        .base_obj = bind_gx_nextion_object_base(GX_NEXTION_TIMER, pid, cid, name)};
    return o;
}

GxBool gx_nextion_timer_set_interval(GxNextionTimer *tmr, u16 value)
{
    GxNextion *device = gx_nextion_current_device();
    return_val_if(!device, GX_FALSE);
    return_val_if(tmr->base_obj.obj_type != GX_NEXTION_TIMER, GX_FALSE);
    return_val_if(value < 50, GX_FALSE);
    // set
    char v[6] = {0};
    __utoa(value, v, 10);
    u16 len_cmd = strlen(tmr->base_obj.name) + 5 + 6; //".tim="+'\0'=6
    char *cmd = malloc(sizeof(char) * len_cmd);
    strcat(cmd, tmr->base_obj.name);
    strcat(cmd, ".tim=");
    strcat(cmd, v);
    gx_nextion_send_cmd(device, cmd);
    free(cmd);
    return gx_cmd_finished(device);
}

GxBool gx_timer_number_get_interval(GxNextionTimer *tmr, u16 *time_value)
{
    GxNextion *device = gx_nextion_current_device();
    return_val_if(!device, GX_FALSE);
    return_val_if(tmr->base_obj.obj_type != GX_NEXTION_TIMER, 0);
    // get
    u16 len_cmd = strlen(tmr->base_obj.name) + 8; //"get "+".tim"+'\0'=9
    char *cmd = malloc(sizeof(char) * len_cmd);
    strcat(cmd, "get ");
    strcat(cmd, tmr->base_obj.name);
    strcat(cmd, ".tim");
    gx_nextion_send_cmd(device, cmd);
    free(cmd);
    i32 value = 0;
    GxBool ret = gx_nextion_return_number(device, &value);
    *time_value = (u16)value;
    return ret;
}

GxBool gx_timer_set_enable(GxNextionTimer *tmr, GxBool enable)
{
    GxNextion *device = gx_nextion_current_device();
    return_val_if(!device, GX_FALSE);
    return_val_if(tmr->base_obj.obj_type != GX_NEXTION_TIMER, GX_FALSE);
    // set
    char v[4] = {0};
    __utoa(enable, v, 10);
    u16 len_cmd = strlen(tmr->base_obj.name) + 3 + 5; //".en="+'\0'=5
    char *cmd = malloc(sizeof(char) * len_cmd);
    strcat(cmd, tmr->base_obj.name);
    strcat(cmd, ".en=");
    strcat(cmd, v);
    gx_nextion_send_cmd(device, cmd);
    free(cmd);
    return gx_cmd_finished(device);
}

GxBool gx_nextion_timer_is_enable(GxNextionTimer *tmr, GxBool *is_enable)
{
    GxNextion *device = gx_nextion_current_device();
    return_val_if(!device, GX_FALSE);
    return_val_if(tmr->base_obj.obj_type != GX_NEXTION_TIMER, 0);
    u16 len_cmd = strlen(tmr->base_obj.name) + 8; //"get "+".en"+'\0'=8
    char *cmd = malloc(sizeof(char) * len_cmd);
    strcat(cmd, "get ");
    strcat(cmd, tmr->base_obj.name);
    strcat(cmd, ".en");
    gx_nextion_send_cmd(device, cmd);
    free(cmd);
    i32 value = 0;
    GxBool ret = gx_nextion_return_number(device, &value);
    *is_enable = (GxBool)value;
    return ret;
}
