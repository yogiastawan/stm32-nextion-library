/**
 * Copyright (c) 2023 I Gede Yogi Astawan
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#ifndef __GX_NEXTION_TEXT_H__
#define __GX_NEXTION_TEXT_H__

#include "gx_nextion_touch.h"

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct _gx_nextion_touch GxNextionText;

    GxNextionText gx_nextion_text_bind(u8 pid, u8 cid, const char *name);

    void gx_nextion_text_onclick(GxNextionText *obj, GxNextionCallback clbk, void *data);
    void gx_nextion_text_onrelease(GxNextionText *obj, GxNextionCallback clbk, void *data);

    GxBool gx_nextion_text_set_text(GxNextionText *obj, const char *text);
    u16 gx_nextion_text_get_text(GxNextionText *obj, char *buffer, u16 len);

    GxBool gx_nextion_text_set_font(GxNextionText *txt, u32 font_id);
    GxBool gx_nextion_text_set_background_color(GxNextionText *txt, u16 clr);

    GxBool gx_nextion_text_set_text_color(GxNextionText *txt, u16 clr);

    GxBool gx_nextion_text_set_background_image(GxNextionText *txt, u32 img_id);
    GxBool gx_nextion_text_set_background_image_crop(GxNextionText *txt, u32 img_id);

    GxBool gx_nextion_text_set_h_alignment(GxNextionText *txt, u8 h_alignment);
    GxBool gx_nextion_text_set_v_alignment(GxNextionText *txt, u8 v_alignment);

    GxBool gx_nextion_text_set_wrap(GxNextionText *txt, GxBool wrap);

    GxBool gx_nextion_text_set_type(GxNextionText *txt, u8 text_type);

#ifdef __cplusplus
}
#endif

#endif /* __GX_NEXTION_TEXT_H__ */
