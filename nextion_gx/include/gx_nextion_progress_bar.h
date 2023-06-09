/**
 * Copyright (c) 2023 I Gede Yogi Astawan
 *
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#ifndef __GIHEX_NEXTION_PROGRESS_BAR_H__
#define __GIHEX_NEXTION_PROGRESS_BAR_H__

#include "gx_nextion_touch.h"

#ifdef __cplusplus
extern "C"
{
#endif
    typedef struct _gx_nextion_touch GxNextionProgressBar;

    GxNextionProgressBar gihex_nextion_prog_bar_bind(u8 pid, u8 cid, const char *name);

    void gx_nextion_prog_bar_onclick(GxNextionProgressBar *pbr, GxNextionCallback clbk, void *data);
    void gx_nextion_prog_bar_onrelease(GxNextionProgressBar *pbr, GxNextionCallback clbk, void *data);

    GxBool gx_nextion_prog_bar_set_value(GxNextionProgressBar *pbr, u32 value);
    GxBool gx_nextion_prog_bar_get_value(GxNextionProgressBar *pbr, u32 *value);

    GxBool gx_nextion_prog_bar_set_background_color(GxNextionProgressBar *pbr, u16 clr);
    GxBool gx_nextion_prog_bar_set_foreground_color(GxNextionProgressBar *pbr, u16 clr);

    GxBool gx_nextion_prog_bar_set_background_img(GxNextionProgressBar *pbr, u32 img);
    GxBool gx_nextion_prog_bar_set_foreground_img(GxNextionProgressBar *pbr, u32 img);

#ifdef __cplusplus
}
#endif

#endif /* __GIHEX_NEXTION_PROGRESS_BAR_H__ */
