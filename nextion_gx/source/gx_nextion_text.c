/**
 * Copyright (c) 2023 I Gede Yogi Astawan
 *
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include "gx_nextion_text.h"

GxNextionText gx_nextion_text_bind(u8 pid, u8 cid, const char *name)
{
    GxNextionText o = {
        .base_obj = bind_gx_nextion_object_base(GX_NEXTION_TEXT, pid, cid, name),
        .on_click = NULL,
        .on_release = NULL,
        .__data_click = NULL,
        .__data_release = NULL};
    return o;
}

void gx_nextion_text_onclick(GxNextionText *obj, GxNextionCallback clbk, void *data)
{
    gx_nextion_set_objt_onclick(obj, GX_NEXTION_TEXT, clbk, data);
}

void gx_nextion_text_onrelease(GxNextionText *obj, GxNextionCallback clbk, void *data)
{
    gx_nextion_set_objt_onrelease(obj, GX_NEXTION_TEXT, clbk, data);
}

GxBool gx_nextion_text_set_text(GxNextionText *obj, const char *text)
{
    return gx_nextion_set_objt_text(obj, GX_NEXTION_TEXT, text);
}

u16 gx_nextion_text_get_text(GxNextionText *obj, char *buffer, u16 len)
{
    return gx_nextion_get_objt_text(obj, GX_NEXTION_TEXT, buffer, len);
}

GxBool gx_nextion_text_set_font(GxNextionText *txt, u32 font_id)
{
    return gx_nextion_set_objt_font(txt, GX_NEXTION_TEXT, font_id);
}

GxBool gx_nextion_text_set_background_color(GxNextionText *txt, u16 clr)
{
    return gx_nextion_set_objt_background_color(txt, GX_NEXTION_TEXT, clr);
}

GxBool gx_nextion_text_set_text_color(GxNextionText *txt, u16 clr)
{
    return gx_nextion_set_objt_foreground_color(txt, GX_NEXTION_TEXT, clr);
}

GxBool gx_nextion_text_set_background_image(GxNextionText *txt, u32 img_id)
{
    return gx_nextion_set_objt_background_img(txt, GX_NEXTION_TEXT, img_id);
}

GxBool gx_nextion_text_set_background_image_crop(GxNextionText *txt, u32 img_id)
{
    return gx_nextion_set_objt_background_crop(txt, GX_NEXTION_TEXT, img_id);
}

GxBool gx_nextion_text_set_h_alignment(GxNextionText *txt, u8 h_alignment)
{
    return gx_nextion_set_objt_text_hor_alignment(txt, GX_NEXTION_TEXT, h_alignment);
}

GxBool gx_nextion_text_set_v_alignment(GxNextionText *txt, u8 v_alignment)
{
    return gx_nextion_set_objt_text_ver_alignment(txt, GX_NEXTION_TEXT, v_alignment);
}

GxBool gx_nextion_text_set_wrap(GxNextionText *txt, GxBool wrap)
{
    return gx_nextion_set_objt_text_wrap(txt, GX_NEXTION_TEXT, wrap);
}

GxBool gx_nextion_text_set_type(GxNextionText *txt, u8 text_type)
{
    GxNextion *device = gx_nextion_current_device();
    return_val_if(!device, GX_FALSE);
    return_val_if(txt->base_obj.obj_type != GX_NEXTION_TEXT, GX_FALSE);
    // set
    char v[4] = {0};
    __utoa(text_type, v, 10);
    u16 len_cmd = strlen(txt->base_obj.name) + 3 + 5; //".pw="+'\0'=5
    char *cmd = malloc(sizeof(char) * len_cmd);
    strcat(cmd, txt->base_obj.name);
    strcat(cmd, ".pw=");
    strcat(cmd, v);
    gx_nextion_send_cmd(device, cmd);
    free(cmd);
    return gx_cmd_finished(device);
}
