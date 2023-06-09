/**
 * Copyright (c) 2023 I Gede Yogi Astawan
 *
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include "gx_nextion_checkbox.h"

GxNextionCheckBox gx_nextion_checkbox_bind(u8 pid, u8 cid, const char *name)
{
    GxNextionCheckBox o = {
        .base_obj = bind_gx_nextion_object_base(GX_NEXTION_CHECKBOX, pid, cid, name),
        .on_click = NULL,
        .on_release = NULL,
        .__data_click = NULL,
        .__data_release = NULL};
    return o;
}

void gx_nextion_checkbox_set_onclick(GxNextionCheckBox *cbk, GxNextionCallback clbk, void *data)
{
    gx_nextion_set_objt_onclick(cbk, GX_NEXTION_CHECKBOX, clbk, data);
}

void gx_nextion_checkbox_set_onrelease(GxNextionCheckBox *cbk, GxNextionCallback clbk, void *data)
{
    gx_nextion_set_objt_onrelease(cbk, GX_NEXTION_CHECKBOX, clbk, data);
}

GxBool gx_nextion_checkbox_set_value(GxNextionCheckBox *cbk, GxBool active)
{
    return gx_nextion_set_objt_value(cbk, GX_NEXTION_CHECKBOX, (i32)active);
}

GxBool gx_nexttion_checkbox_get_value(GxNextionCheckBox *cbk, GxBool *value)
{
    i32 tmp = 0;
    GxBool a = gx_nextion_get_objt_value(cbk, GX_NEXTION_CHECKBOX, &tmp);
    *value = (GxBool)tmp;
    return a;
}

GxBool gx_nextion_checkbox_set_background_color(GxNextionCheckBox *cbk, u16 clr)
{
    return gx_nextion_set_objt_background_color(cbk, GX_NEXTION_CHECKBOX, clr);
}

GxBool gx_nextion_checkbox_set_foreground_color(GxNextionCheckBox *cbk, u16 clr)
{
    return gx_nextion_set_objt_foreground_color(cbk, GX_NEXTION_CHECKBOX, clr);
}
