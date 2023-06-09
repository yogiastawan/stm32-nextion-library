/**
 * Copyright (c) 2023 I Gede Yogi Astawan
 *
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#ifndef __GIHEX_NEXTION_BUTTON_H__
#define __GIHEX_NEXTION_BUTTON_H__

#include "gx_mangle.h"
#include "gx_components.h"

#include "gx_nextion_touch.h"

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * @brief GxNextionButton object. Aliased from struct _gx_nextion_touch
     */
    typedef struct _gx_nextion_touch GxNextionButton;

    /**
     * @brief Binding new GxNextionButton object to Button in nextion device
     * @param pid Page id of Button located
     * @param cid Component id of button
     * @param name Name of the button
     * @return Return new GxNextionButton object
     */
    GxNextionButton gx_nextion_button_bind(u8 pid, u8 cid, const char *name);

    /**
     * @brief Set on click touchscreen handler for GxNextionButton object
     * @param obj GxNextionButton object will be set
     * @param clbk Callback function
     * @param data Pointer data will be pass to callback function
     */
    void gx_nextion_button_onclick(GxNextionButton *obj, GxNextionCallback clbk, void *data);

    /**
     * @brief Set on release touchscreen handler for GxNextionButton object
     * @param obj GxNextionButton object will be set
     * @param clbk Callback function
     * @param data Pointer data will be pass to callback function
     */
    void gx_nextion_button_onrelease(GxNextionButton *obj, GxNextionCallback clbk, void *data);

    /**
     * @brief Change GxNextionButton object text label
     * @param obj GxNextionButton object will be set
     * @param label New text label
     * @return Return GX_TRUE if success or otherwise GX_FALSE
     */
    GxBool gx_nextion_button_set_label(GxNextionButton *obj, const char *label);

    /**
     * @brief Get GxNextionButton object text label
     * @param obj Gx Nextion object
     * @param buffer Pointer to hold text label
     * @param len Length of text label will be saved to buffer
     * @return Return the length of text saved in buffer
     * @note Memory allocation for buffer must be 1 extra bytes from len to store null terminator. Example if length of text will be saved to buffer
     * is 30 character (len=30), we must allocated buffer 30+1 bytes (30 bytes): char buffer[31]={0} or char *buffer=malloc(sizeof(char)*31)
     */
    u16 gx_nextion_button_get_label(GxNextionButton *obj, char *buffer, u16 len);

    /**
     * @brief Change font for GxNextionButton object label
     * @param obj GxNextionButton object will be set
     * @param font_id Id of font.
     * @return Return GX_TRUE if success or otherwise GX_FALSE
     */
    GxBool gx_nextion_button_set_font(GxNextionButton *obj, u32 font_id);

    /**
     * @brief Set background color of GxNextionButton
     * @param btn GxNextionButton object will be set
     * @param clr New color
     * @return Return GX_TRUE if success or otherwise GX_FALSE
     */
    GxBool gx_nextion_button_set_background_color(GxNextionButton *btn, u16 clr);

    /**
     * @brief Set background color of clicked GxNextionButton
     * @param btn GxNextionButton object will be set
     * @param clr New color
     * @return Return GX_TRUE if success or otherwise GX_FALSE
     */
    GxBool gx_nextion_button_set_onclick_background_color(GxNextionButton *btn, u16 clr);

    /**
     * @brief Set text label color of GxNextionButton
     * @param btn GxNextionButton object will be set
     * @param clr New color
     * @return Return GX_TRUE if success or otherwise GX_FALSE
     */
    GxBool gx_nextion_button_set_label_color(GxNextionButton *btn, u16 clr);

    /**
     * @brief Set text label color of clicked GxNextionButton
     * @param btn GxNextionButton object will be set
     * @param clr New color
     * @return Return GX_TRUE if success or otherwise GX_FALSE
     */
    GxBool gx_nextion_button_set_onclick_label_color(GxNextionButton *btn, u16 clr);

    /**
     * @brief Set background image of GxNextionButton
     * @param btn GxNextionButton object will be set
     * @param img_id New image id
     * @return Return GX_TRUE if success or otherwise GX_FALSE
     */
    GxBool gx_nextion_button_set_background_image(GxNextionButton *btn, u32 img_id);

    /**
     * @brief Set background image of clicked GxNextionButton
     * @param btn GxNextionButton object will be set
     * @param img_id New image id
     * @return Return GX_TRUE if success or otherwise GX_FALSE
     */
    GxBool gx_nextion_button_set_onclick_background_image(GxNextionButton *btn, u32 img_id);

    /**
     * @brief Set background image crop of GxNextionButton
     * @param btn GxNextionButton object will be set
     * @param img_id New image id
     * @return Return GX_TRUE if success or otherwise GX_FALSE
     */
    GxBool gx_nextion_button_set_background_image_crop(GxNextionButton *btn, u32 img_id);

    /**
     * @brief Set background image crop of clicked GxNextionButton
     * @param btn GxNextionButton object will be set
     * @param img_id New image id
     * @return Return GX_TRUE if success or otherwise GX_FALSE
     */
    GxBool gx_nextion_button_set_onclick_background_image_crop(GxNextionButton *btn, u32 img_id);

    /**
     * @brief Set horizontal alignment of text label GxNextionButton
     * @param btn GxNextionButton object will be set
     * @param h_alignment Horizontal alignment. HORIZONTAL_ALIGNMENT_[LEFT | CENTER | RIGHT]
     * @return Return GX_TRUE if success or otherwise GX_FALSE
     */
    GxBool gx_nextion_button_set_label_h_alignment(GxNextionButton *btn, u8 h_alignment);

    /**
     * @brief Set vertical alignment of text label GxNextionButton
     * @param btn GxNextionButton object will be set
     * @param v_alignment Vertical alignment. VERTICAL_ALIGNMENT_[TOP | CENTER | BOTTOM]
     * @return Return GX_TRUE if success or otherwise GX_FALSE
     */
    GxBool gx_nextion_button_set_label_v_alignment(GxNextionButton *btn, u8 v_alignment);

    /**
     * @brief Wrap GxNextionButton text label or not
     * @param btn GxNextionButton object
     * @param wrap Set wrap or not. Set value wrap to GX_TRUE to wrap, otherwise set to GX_FALSE
     * @return Return GX_TRUE if success or otherwise GX_FALSE
     */
    GxBool gx_nextion_button_set_label_wrap(GxNextionButton *btn, GxBool wrap);

#ifdef __cplusplus
}
#endif

#endif /* __GIHEX_NEXTION_BUTTON_H__ */
