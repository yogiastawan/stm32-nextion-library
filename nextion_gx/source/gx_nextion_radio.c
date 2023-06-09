/**
 * Copyright (c) 2023 I Gede Yogi Astawan
 *
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include "gx_nextion_radio.h"

GxNextionRadio gx_nextion_radio_bind(u8 pid, u8 cid, const char *name)
{
    GxNextionRadio o = {
        .base_obj = bind_gx_nextion_object_base(GX_NEXTION_CHECKBOX, pid, cid, name),
        .on_click = NULL,
        .on_release = NULL,
        .__data_click = NULL,
        .__data_release = NULL};
    return o;
}

void gx_nextion_radio_set_onclick(GxNextionRadio *cbk, GxNextionCallback clbk, void *data)
{
    gx_nextion_set_objt_onclick(cbk, GX_NEXTION_CHECKBOX, clbk, data);
}

void gx_nextion_radio_set_onrelease(GxNextionRadio *cbk, GxNextionCallback clbk, void *data)
{
    gx_nextion_set_objt_onrelease(cbk, GX_NEXTION_CHECKBOX, clbk, data);
}

GxBool gx_nextion_radio_set_value(GxNextionRadio *cbk, GxBool active)
{
    return gx_nextion_set_objt_value(cbk, GX_NEXTION_CHECKBOX, (i32)active);
}

GxBool gx_nexttion_radio_get_value(GxNextionRadio *cbk, GxBool *active)
{
    i32 tmp = 0;
    GxBool ret = gx_nextion_get_objt_value(cbk, GX_NEXTION_CHECKBOX, &tmp);
    *active = (GxBool)tmp;
    return ret;
}

GxBool gx_nextion_radio_set_background_color(GxNextionRadio *cbk, u16 clr)
{
    return gx_nextion_set_objt_background_color(cbk, GX_NEXTION_CHECKBOX, clr);
}

GxBool gx_nextion_radio_set_foreground_color(GxNextionRadio *cbk, u16 clr)
{
    return gx_nextion_set_objt_foreground_color(cbk, GX_NEXTION_CHECKBOX, clr);
}
