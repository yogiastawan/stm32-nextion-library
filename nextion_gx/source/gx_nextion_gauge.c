/**
 * Copyright (c) 2023 I Gede Yogi Astawan
 *
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include "gx_nextion_gauge.h"

GxNextionGauge gx_nextion_gauge_bind(u8 pid, u8 cid, const char *name)
{
    GxNextionGauge o = {
        .base_obj = bind_gx_nextion_object_base(GX_NEXTION_GAUGE, pid, cid, name),
        .on_click = NULL,
        .on_release = NULL,
        .__data_click = NULL,
        .__data_release = NULL};
    return o;
}

void gx_nextion_gauge_set_onclick(GxNextionGauge *gauge, GxNextionCallback clbk, void *data)
{
    gx_nextion_set_objt_onclick(gauge, GX_NEXTION_GAUGE, clbk, data);
}

void gx_nextion_gauge_set_onrelease(GxNextionGauge *gauge, GxNextionCallback clbk, void *data)
{
    gx_nextion_set_objt_onrelease(gauge, GX_NEXTION_GAUGE, clbk, data);
}

GxBool gx_nextion_gauge_set_value(GxNextionGauge *gauge, i32 value)
{
    return gx_nextion_set_objt_value(gauge, GX_NEXTION_GAUGE, value);
}

GxBool gx_nextion_gauge_get_value(GxNextionGauge *gauge, i32 *value)
{
    return gx_nextion_get_objt_value(gauge, GX_NEXTION_GAUGE, value);
}

GxBool gx_nextion_gauge_set_background_color(GxNextionGauge *gauge, u16 clr)
{
    return gx_nextion_set_objt_background_color(gauge, GX_NEXTION_GAUGE, clr);
}

GxBool gx_nextion_gauge_set_background_image(GxNextionGauge *gauge, u32 img_id)
{
    return gx_nextion_set_objt_background_img(gauge, GX_NEXTION_GAUGE, img_id);
}

GxBool gx_nextion_gauge_set_background_crop(GxNextionGauge *gauge, u32 img_id)
{
    return gx_nextion_set_objt_background_crop(gauge, GX_NEXTION_GAUGE, img_id);
}

GxBool gx_nextion_gauge_set_pointer_color(GxNextionGauge *gauge, u16 clr)
{
    return gx_nextion_set_objt_foreground_color(gauge, GX_NEXTION_GAUGE, clr);
}

GxBool gx_nextion_gauge_set_pointer_width(GxNextionGauge *gauge, u8 width)
{
    GxNextion *device = gx_nextion_current_device();
    return_val_if(!device, GX_FALSE);
    return_val_if(gauge->base_obj.obj_type != GX_NEXTION_GAUGE, GX_FALSE);
    return_val_if(width > 20, GX_FALSE);
    char v[4] = {0};
    __utoa(width, v, 10);
    u16 len_cmd = strlen(gauge->base_obj.name) + 3 + 6; //".wid="+'\0'=6
    char *cmd = malloc(sizeof(char) * len_cmd);
    strcat(cmd, gauge->base_obj.name);
    strcat(cmd, ".wid=");
    strcat(cmd, v);
    gx_nextion_send_cmd(device, cmd);
    free(cmd);
    return gx_cmd_finished(device);
}
