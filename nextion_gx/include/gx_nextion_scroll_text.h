/**
 * Copyright (c) 2023 I Gede Yogi Astawan
 *
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#ifndef __GX_NEXTION_SCROLLING_TEXT_H__
#define __GX_NEXTION_SCROLLING_TEXT_H__

#include "gx_nextion_touch.h"

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct _gx_nextion_touch GxNextionScrollText;

    GxNextionScrollText gx_nextion_scroll_text_bind(u8 pid, u8 cid, const char *name);

    void gx_nextion_scroll_text_onclick(GxNextionScrollText *obj, GxNextionCallback clbk, void *data);
    void gx_nextion_scroll_text_onrelease(GxNextionScrollText *obj, GxNextionCallback clbk, void *data);

    GxBool gx_nextion_scroll_text_set_text(GxNextionScrollText *obj, const char *text);
    u16 gx_nextion_scroll_text_get_text(GxNextionScrollText *obj, char *buffer, u16 len);

    GxBool gx_nextion_scroll_text_set_background_color(GxNextionScrollText *txt, u16 clr);

    GxBool gx_nextion_scroll_text_set_text_color(GxNextionScrollText *txt, u16 clr);
    GxBool gx_nextion_scroll_text_set_font(GxNextionScrollText *txt, u32 font_id);

    GxBool gx_nextion_scroll_text_set_background_image(GxNextionScrollText *txt, u32 img_id);
    GxBool gx_nextion_scroll_text_set_background_image_crop(GxNextionScrollText *txt, u32 img_id);

    GxBool gx_nextion_scroll_text_set_label_h_alignment(GxNextionScrollText *txt, u8 h_alignment);
    GxBool gx_nextion_scroll_text_set_label_v_alignment(GxNextionScrollText *txt, u8 v_alignment);

    GxBool gx_nextion_scroll_text_set_wrap(GxNextionScrollText *txt, GxBool wrap);

    GxBool gx_nextion_scroll_text_set_direction(GxNextionScrollText *txt, u8 direction);
    GxBool gx_nextion_scroll_text_set_distance(GxNextionScrollText *txt, u8 distance_in_ms);
    GxBool gx_nextion_scroll_text_set_interval_ms(GxNextionScrollText *txt, u16 interval_ms);
    GxBool gx_nextion_scroll_text_enable(GxNextionScrollText *txt, GxBool enable);
    GxBool gx_nextion_scroll_text_horizontal_spacing(GxNextionScrollText *txt, u8 space);
    GxBool gx_nextion_scroll_text_vertical_spacing(GxNextionScrollText *txt, u8 space);

#ifdef __cplusplus
}
#endif

#endif /* __GX_NEXTION_SCROLLING_TEXT_H__ */
