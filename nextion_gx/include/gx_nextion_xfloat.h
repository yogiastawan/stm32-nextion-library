/**
 * Copyright (c) 2023 I Gede Yogi Astawan
 *
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#ifndef __GIHEX_NEXTION_XFLOAT_H__
#define __GIHEX_NEXTION_XFLOAT_H__

#include "gx_nextion_touch.h"

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct _gx_nextion_touch GxNextionXFloat;

    GxNextionXFloat gx_nextion_xfloat_bind(u8 pid, u8 cid, const char *name);

    void gx_nextion_xfloat_onclick(GxNextionXFloat *flt, GxNextionCallback clbk, void *data);
    void gx_nextion_xfloat_onrelease(GxNextionXFloat *flt, GxNextionCallback clbk, void *data);

    GxBool gx_nextion_xfloat_set_value(GxNextionXFloat *flt, i32 value);
    GxBool gx_nextion_xfloat_get_value(GxNextionXFloat *flt, i32 *value);

    GxBool gx_nextion_xfloat_set_font(GxNextionXFloat *flt, u32 font_id);

    GxBool gx_nextion_xfloat_set_background_color(GxNextionXFloat *flt, u16 clr);

    GxBool gx_nextion_xfloat_set_text_color(GxNextionXFloat *flt, u16 clr);

    GxBool gx_nextion_xfloat_set_background_image(GxNextionXFloat *flt, u32 img_id);
    GxBool gx_nextion_xfloat_set_background_image_crop(GxNextionXFloat *flt, u32 img_id);

    GxBool gx_nextion_xfloat_set_text_h_alignment(GxNextionXFloat *flt, u8 h_alignment);
    GxBool gx_nextion_xfloat_set_text_v_alignment(GxNextionXFloat *flt, u8 v_alignment);

    GxBool gx_nextion_xfloat_set_wrap(GxNextionXFloat *flt, GxBool wrap);
    GxBool gx_nextion_xfloat_horizontal_spacing(GxNextionXFloat *flt, u8 space);
    GxBool gx_nextion_xfloat_vertical_spacing(GxNextionXFloat *flt, u8 space);

    GxBool gx_nextion_xfloat_vertical_spacing(GxNextionXFloat *flt, u8 space);

    GxBool gx_nextion_xfloat_set_point_right(GxNextionXFloat *flt, u8 point);

    GxBool gx_nextion_xfloat_set_point_left(GxNextionXFloat *flt, u8 point);

#ifdef __cplusplus
}
#endif

#endif /* __GIHEX_NEXTION_XFLOAT_H__ */
