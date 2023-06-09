/**
 * Copyright (c) 2023 I Gede Yogi Astawan
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include "gx_nextion_touch_cap.h"

GxNextionTouchCap gx_nextion_touch_cap_bind(u8 pid, u8 cid, const char *name)
{
    GxNextionTouchCap o = {
        .base_obj = bind_gx_nextion_object_base(GX_NEXTION_TOUCH_CAP, pid, cid, name),
        .on_click = NULL,
        .on_release = NULL,
        .__data_click = NULL,
        .__data_release = NULL};
    return o;
}

void gx_nextion_touch_cap_set_onclick(GxNextionTouchCap *tcp, GxNextionCallback clbk, void *data)
{
    gx_nextion_set_objt_onclick(tcp, GX_NEXTION_TOUCH_CAP, clbk, data);
}

void gx_nextion_touch_cap_set_onrelease(GxNextionTouchCap *tcp, GxNextionCallback clbk, void *data)
{
    gx_nextion_set_objt_onrelease(tcp, GX_NEXTION_TOUCH_CAP, clbk, data);

}
