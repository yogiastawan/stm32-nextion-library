/**
 * Copyright (c) 2023 I Gede Yogi Astawan
 *
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#ifndef __GIHEX_NEXTION_TOUCH_H__
#define __GIHEX_NEXTION_TOUCH_H__

#include "gx_nextion_object.h"

#ifdef __cplusplus
extern "C"
{
#endif

#define GX_NEXTION_EVENT_RELEASE (u8)0x00
#define GX_NEXTION_EVENT_TOUCHPRESS (u8)0x01

    /**
     * @brief Callback function
     */
    typedef void (*GxNextionCallback)(void *data);

    /// @brief GxNextionTouch Object
    typedef struct _gx_nextion_touch GxNextionTouch;

    /// @brief Struct _gx_nextion_touch
    /// @note Derive this object to create component with touch handler
    struct _gx_nextion_touch
    {
        /// @brief Store pointer click handler callback
        GxNextionCallback on_click;
        /// @brief Store pointer data used in click callback
        void *__data_click;
        /// @brief Store pointer release handler callback
        GxNextionCallback on_release;
        /// @brief Store pointer data used in release callback
        void *__data_release;
        /// @brief Store base object
        GxNextionObjectBase base_obj;
    };

    /**
     * @brief Loop to capture touch event
     * @param nextion Pointer to nextion device
     * @param touch_obj List of pointer component that contain touch event
     * @note List component must ended with NULL. Example: GxNextionTouch *touch_obj[]={&t0,&t1,NULL}
     */
    void gx_nextion_loop(GxNextion *nextion, GxNextionTouch *touch_obj[]);

    /**
     * @brief Set onclick event callback
     * @param obj Pointer to object that will be set
     * @param obj_type Object type => GX_NEXTION_[TYPE]_[TYPE]
     * @param clbk Callback function
     * @param data Pointer containt data to callback function
     */
    void gx_nextion_set_objt_onclick(void *obj, u8 obj_type, GxNextionCallback clbk, void *data);

    /**
     * @brief Set onrelease event callback
     * @param obj Pointer to object that will be set
     * @param obj_type Object type => GX_NEXTION_[TYPE]_[TYPE]
     * @param clbk Callback function
     * @param data Pointer containt data to callback function
     */
    void gx_nextion_set_objt_onrelease(void *obj, u8 obj_type, GxNextionCallback clbk, void *data);

    /**
     * @brief Set text to component display
     * @param obj Pointe to object will be set
     * @param obj_type Object type => GX_NEXTION_[TYPE]_[TYPE]
     * @param txt String text
     * @return Return GX_TRUE if success else GX_FALSE
     */
    GxBool gx_nextion_set_objt_text(void *obj, u8 obj_type, const char *txt);

    /**
     * @brief Get string text from component display
     * @param obj Pointer to component display
     * @param obj_type Object type => GX_NEXTION_[TYPE]_[TYPE]
     * @param buffer Buffer that store text
     * @param len Length of string to store in buffer
     * @return Return length of string stored in buffer
     * @note Memory allocation for buffer must be extra 1 byte from len to store null terminator.
     * Example if we want to store 30 characters [len=30], we must allocate buffer [30+1]bytes like: char buffer[31]={0}
     * or char *buffer=malloc(sizeof(char)*31).
     */
    u16 gx_nextion_get_objt_text(void *obj, u8 obj_type, char *buffer, u16 len);

    /**
     * @brief
     * @param obj
     * @param obj_type
     * @param value
     * @return
     */
    GxBool gx_nextion_set_objt_value(void *obj, u8 obj_type, i32 value);

    /**
     * @brief
     * @param obj
     * @param obj_type
     * @param value
     * @return
     */
    GxBool gx_nextion_get_objt_value(void *obj, u8 obj_type, i32 *value);

    /**
     * @brief
     * @param obj
     * @param obj_type
     * @param color
     * @return
     */
    GxBool gx_nextion_set_objt_background_color(void *obj, u8 obj_type, u16 color);

    /**
     * @brief
     * @param obj
     * @param obj_type
     * @param img
     * @return
     */
    GxBool gx_nextion_set_objt_background_img(void *obj, u8 obj_type, u32 img);

    /**
     * @brief
     * @param obj
     * @param obj_type
     * @param img_crop
     * @return
     */
    GxBool gx_nextion_set_objt_background_crop(void *obj, u8 obj_type, u32 img_crop);

    /**
     * @brief
     * @param obj
     * @param obj_type
     * @param color
     * @return
     */
    GxBool gx_nextion_set_objt_foreground_color(void *obj, u8 obj_type, u16 color);

    /**
     * @brief
     * @param obj
     * @param obj_type
     * @param font_id
     * @return
     */
    GxBool gx_nextion_set_objt_font(void *obj, u8 obj_type, u32 font_id);

    /**
     * @brief
     * @param obj
     * @param obj_type
     * @param horiontal_alignemet
     * @return
     */
    GxBool gx_nextion_set_objt_text_hor_alignment(void *obj, u8 obj_type, u8 horiontal_alignemet);

    /**
     * @brief
     * @param obj
     * @param obj_type
     * @param vertical_alignemet
     * @return
     */
    GxBool gx_nextion_set_objt_text_ver_alignment(void *obj, u8 obj_type, u8 vertical_alignemet);

    /**
     * @brief Set text of object to wrap or not
     * @param obj Object will be set
     * @param obj_type Type of object
     * @param wrap Wrap value
     * @return Return GX_TRUE if success, otherwise return GX_FALSE
     * @note Parameter obj_type can be assigned using GX_NEXTION_[TYPE]_[TYPE]. To make text wraps set the parameter wrap
     * to GX_TRUE, otherwise set to GX_FALSE
     */
    GxBool gx_nextion_set_objt_text_wrap(void *obj, u8 obj_type, GxBool wrap);

#ifdef __cplusplus
}
#endif
#endif /* __GIHEX_NEXTION_TOUCH_H__ */
