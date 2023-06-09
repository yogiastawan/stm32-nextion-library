/**
 * Copyright (c) 2023 I Gede Yogi Astawan
 *
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include "gx_nextion_object.h"

static GxNextion *nextion_device = NULL;

GxNextionObjectBase bind_gx_nextion_object_base(u8 obj_type, u8 pid, u8 cid, const char *name)
{
    GxNextionObjectBase obj = {
        .obj_type = obj_type,
        .pid = pid,
        .cid = cid,
        .name = name,
    };

    return obj;
}

GxBool gx_nextion_set_obj_value(void *obj, u8 obj_type, i32 value)
{
    GxNextion *device = gx_nextion_current_device();
    return_val_if(!device, GX_FALSE);
    GxNextionObject *o = (GxNextionObject *)obj;
    return_val_if(o->base_obj.obj_type != obj_type, GX_FALSE);
    // set value
    char v[11] = {0};
    __itoa(value, v, 10);
    u16 len_cmd = strlen(o->base_obj.name) + 10 + 6; //".val="+'\0'=6
    char *cmd = malloc(sizeof(char) * len_cmd);
    strcat(cmd, o->base_obj.name);
    strcat(cmd, ".val=");
    strcat(cmd, v);
    gx_nextion_send_cmd(device, cmd);
    free(cmd);
    return gx_cmd_finished(device);
}

GxBool gx_nextion_get_obj_value(void *obj, u8 obj_type, i32 *value)
{
    GxNextion *device = gx_nextion_current_device();
    return_val_if(!device, GX_FALSE);
    GxNextionObject *o = (GxNextionObject *)obj;
    return_val_if(o->base_obj.obj_type != obj_type, GX_FALSE);
    u16 len_cmd = strlen(o->base_obj.name) + 9; //"get "+".val"+'\0'=9
    char *cmd = malloc(sizeof(char) * len_cmd);
    strcat(cmd, "get ");
    strcat(cmd, o->base_obj.name);
    strcat(cmd, ".val");
    gx_nextion_send_cmd(device, cmd);
    free(cmd);
    return gx_nextion_return_number(device, value);
}

void gx_nextion_use_device(GxNextion *nextion)
{
    nextion_device = nextion;
}

GxNextion *gx_nextion_current_device()
{
    return nextion_device;
}
