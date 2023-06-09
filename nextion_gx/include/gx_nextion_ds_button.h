/**
 * Copyright (c) 2023 I Gede Yogi Astawan
 *
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#ifndef __GIHEX_NEXTION_DS_BUTTON_H__
#define __GIHEX_NEXTION_DS_BUTTON_H__

#include "gx_nextion_touch.h"

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct _gx_nextion_touch GxNextionDSButton;

    GxNextionDSButton gx_nextion_ds_button_bind(u8 pid, u8 cid, const char *name);

    void gx_nextion_ds_button_set_onclick(GxNextionDSButton *btn, GxNextionCallback clbk, void *data);
    void gx_nextion_ds_button_set_onrelease(GxNextionDSButton *btn, GxNextionCallback clbk, void *data);

    GxBool gx_nextion_ds_button_set_value(GxNextionDSButton *btn, GxBool active);
    GxBool gx_nextion_ds_button_get_value(GxNextionDSButton *btn, GxBool *value);

    GxBool gx_nextion_ds_button_set_font(GxNextionDSButton *btn, u32 font_id);

    GxBool gx_nextion_ds_button_set_backgroud_color(GxNextionDSButton *btn, u16 clr);
    GxBool gx_nextion_ds_button_set_backgroud_image(GxNextionDSButton *btn, u32 img);
    GxBool gx_nextion_ds_button_set_backgroud_image_crop(GxNextionDSButton *btn, u32 img);

    GxBool gx_nextion_ds_button_set_active_backgroud_color(GxNextionDSButton *btn, u16 clr);
    GxBool gx_nextion_ds_button_set_active_backgroud_image(GxNextionDSButton *btn, u32 img);
    GxBool gx_nextion_ds_button_set_active_backgroud_image_crop(GxNextionDSButton *btn, u32 img);

    GxBool gx_nextion_ds_button_set_text_color(GxNextionDSButton *btn, u16 clr);
    GxBool gx_nextion_ds_button_set_active_text_color(GxNextionDSButton *btn, u16 clr);

    GxBool gx_nextion_ds_button_set_text_h_alignment(GxNextionDSButton *btn, u8 h_alignment);
    GxBool gx_nextion_ds_button_set_text_v_alignment(GxNextionDSButton *btn, u8 v_alignment);

    GxBool gx_nextion_ds_button_set_text(GxNextionDSButton *btn, const char *txt);

    GxBool gx_nextion_ds_button_set_text_wrap(GxNextionDSButton *btn, GxBool wrap);

#ifdef __cplusplus
}
#endif

#endif /* __GIHEX_NEXTION_DS_BUTTON_H__ */
