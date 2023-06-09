/**
 * Copyright (c) 2023 I Gede Yogi Astawan
 *
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#ifndef __GIHEX_NEXTION_GAUGE_H__
#define __GIHEX_NEXTION_GAUGE_H__

#include "gx_nextion_touch.h"

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct _gx_nextion_touch GxNextionGauge;

    GxNextionGauge gx_nextion_gauge_bind(u8 pid, u8 cid, const char *name);

    void gx_nextion_gauge_set_onclick(GxNextionGauge *gauge, GxNextionCallback clbk, void *data);
    void gx_nextion_gauge_set_onrelease(GxNextionGauge *gauge, GxNextionCallback clbk, void *data);

    GxBool gx_nextion_gauge_set_value(GxNextionGauge *gauge, i32 value);
    GxBool gx_nextion_gauge_get_value(GxNextionGauge *gauge, i32 *value);

    GxBool gx_nextion_gauge_set_background_color(GxNextionGauge *gauge, u16 clr);
    GxBool gx_nextion_gauge_set_background_image(GxNextionGauge *gauge, u32 img_id);
    GxBool gx_nextion_gauge_set_background_crop(GxNextionGauge *gauge, u32 img_id);

    GxBool gx_nextion_gauge_set_pointer_color(GxNextionGauge *gauge, u16 clr);

    GxBool gx_nextion_gauge_set_pointer_width(GxNextionGauge *gauge, u8 width);

#ifdef __cplusplus
}
#endif

#endif /* __GIHEX_NEXTION_GAUGE_H__ */
