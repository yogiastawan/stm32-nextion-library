/**
 * Copyright (c) 2023 I Gede Yogi Astawan
 *
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#ifndef __GIHEX_NEXTION_NUMBER_H__
#define __GIHEX_NEXTION_NUMBER_H__

#include "gx_nextion_touch.h"

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct _gx_nextion_touch GxNextionNumber;

    GxNextionNumber gx_nextion_number_bind(u8 pid, u8 cid, const char *name);

    void gx_nextion_number_onclick(GxNextionNumber *obj, GxNextionCallback clbk, void *data);
    void gx_nextion_number_onrelease(GxNextionNumber *obj, GxNextionCallback clbk, void *data);

    GxBool gx_nextion_number_set_value(GxNextionNumber *obj, i32 value);
    GxBool gx_nextion_number_get_value(GxNextionNumber *obj, i32 *value);

    GxBool gx_nextion_number_set_background_color(GxNextionNumber *nmb, u16 clr);

    GxBool gx_nextion_number_set_text_color(GxNextionNumber *nmb, u16 clr);
    GxBool gx_nextion_number_set_font(GxNextionNumber *nmb, u32 font_id);

    GxBool gx_nextion_number_set_background_image(GxNextionNumber *nmb, u32 img_id);
    GxBool gx_nextion_number_set_background_image_crop(GxNextionNumber *nmb, u32 img_id);

    GxBool gx_nextion_number_set_text_h_alignment(GxNextionNumber *nmb, u8 h_alignment);
    GxBool gx_nextion_number_set_text_v_alignment(GxNextionNumber *nmb, u8 v_alignment);

    GxBool gx_nextion_number_set_length(GxNextionNumber *nmb, u8 length);

    GxBool gx_nextion_number_set_format(GxNextionNumber *nmb, u8 format);

    GxBool gx_nextion_number_set_wrap(GxNextionNumber *nmb, GxBool wrap);
    GxBool gx_nextion_number_horizontal_spacing(GxNextionNumber *nmb, u8 space);
    GxBool gx_nextion_number_vertical_spacing(GxNextionNumber *nmb, u8 space);

#ifdef __cplusplus
}
#endif

#endif /* __GIHEX_NEXTION_NUMBER_H__ */
