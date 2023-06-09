/**
 * Copyright (c) 2023 I Gede Yogi Astawan
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#ifndef __GIHEX_NEXTION_HOTSPOT_H__
#define __GIHEX_NEXTION_HOTSPOT_H__

#include "gx_nextion_touch.h"

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct _gx_nextion_touch GxNextionHotspot;

    GxNextionHotspot gx_nextion_hotspot_bind(u8 pid, u8 cid, const char *name);

    void gx_nextion_hotspot_set_onclick(GxNextionHotspot *hpt, GxNextionCallback clbk, void *data);
    void gx_nextion_hotspot_set_onrelease(GxNextionHotspot *hpt, GxNextionCallback clbk, void *data);

#ifdef __cplusplus
}
#endif

#endif /* __GIHEX_NEXTION_HOTSPOT_H__ */
