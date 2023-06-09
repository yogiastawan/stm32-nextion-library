/**
 * Copyright (c) 2023 I Gede Yogi Astawan
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include "gx_nextion_picture.h"

GxNextionPicture gx_nextion_picture_bind(u8 pid, u8 cid, const char *name)
{
    GxNextionPicture o = {
        .base_obj = bind_gx_nextion_object_base(GX_NEXTION_PICTURE, pid, cid, name),
        .on_click = NULL,
        .on_release = NULL,
        .__data_click = NULL,
        .__data_release = NULL};
    return o;
}

void gx_nextion_picture_set_onclick(GxNextionPicture *pic, GxNextionCallback clbk, void *data)
{
    gx_nextion_set_objt_onclick(pic, GX_NEXTION_PICTURE, clbk, data);
}

void gx_nextion_picture_set_onrelease(GxNextionPicture *pic, GxNextionCallback clbk, void *data)
{
    gx_nextion_set_objt_onrelease(pic, GX_NEXTION_PICTURE, clbk, data);
}

GxBool gx_nextion_picture_set_image(GxNextionPicture *pic, u32 img_id)
{
   return gx_nextion_set_objt_background_img(pic, GX_NEXTION_PICTURE, img_id);
}
