/**
 * Copyright (c) 2023 I Gede Yogi Astawan
 *
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#ifndef __GIHEX_NEXTION_SLIDER_H__
#define __GIHEX_NEXTION_SLIDER_H__

#include "gx_nextion_touch.h"

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct _gx_nextion_touch GxNextionSlider;

    GxNextionSlider gx_nextion_slider_bind(u8 pid, u8 cid, const char *name);

    GxBool gx_nextion_slider_onclick(GxNextionSlider *slider, GxNextionCallback clbk, GxBool *data);
    void gx_nextion_slider_onrelease(GxNextionSlider *slider, GxNextionCallback clbk, void *data);
    void gx_nextion_slider_onmove_cursor(GxNextionSlider *slider, GxNextionCallback clbk, void *data);

    GxBool gx_nextion_slider_set_value(GxNextionSlider *slider, u16 value);
    GxBool gx_nextion_slider_get_value(GxNextionSlider *slider, u16 *active);

    GxBool gx_nextion_slider_set_background_color(GxNextionSlider *slider, u16 clr);
    GxBool gx_nextion_slider_set_background_img(GxNextionSlider *slider, u32 img);
    GxBool gx_nextion_slider_set_background_img_crop(GxNextionSlider *slider, u32 img);

    GxBool gx_nextion_slider_set_foreground_color(GxNextionSlider *slider, u16 clr);
    GxBool gx_nextion_slider_set_foreground_img_crop(GxNextionSlider *slider, u32 img);

    GxBool gx_nextion_slider_set_cursor_color(GxNextionSlider *slider, u16 clr);
    GxBool gx_nextion_slider_set_cursor_img(GxNextionSlider *slider, u32 img);

    GxBool gx_nextion_slider_set_max_value(GxNextionSlider *slider, u16 value);
    GxBool gx_nextion_slider_set_min_value(GxNextionSlider *slider, u16 value);

#ifdef __cplusplus
}
#endif

#endif /* __GIHEX_NEXTION_SLIDER_H__ */
