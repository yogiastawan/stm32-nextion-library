/**
 * Copyright (c) 2023 I Gede Yogi Astawan
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include "gx_nextion_hotspot.h"

GxNextionHotspot gx_nextion_hotspot_bind(u8 pid, u8 cid, const char *name)
{
    GxNextionHotspot o = {
        .base_obj = bind_gx_nextion_object_base(GX_NEXTION_HOTSPOT, pid, cid, name),
        .on_click = NULL,
        .on_release = NULL,
        .__data_click = NULL,
        .__data_release = NULL};
    return o;
}

void gx_nextion_hotspot_set_onclick(GxNextionHotspot *hpt, GxNextionCallback clbk, void *data)
{
    gx_nextion_set_objt_onclick(hpt, GX_NEXTION_HOTSPOT, clbk, data);
}

void gx_nextion_hotspot_set_onrelease(GxNextionHotspot *hpt, GxNextionCallback clbk, void *data)
{
    gx_nextion_set_objt_onrelease(hpt, GX_NEXTION_HOTSPOT, clbk, data);

}
