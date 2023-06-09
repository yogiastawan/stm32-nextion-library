/**
 * Copyright (c) 2023 I Gede Yogi Astawan
 *
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include "gx_nextion_crop.h"

GxNextionCrop gx_nextion_crop_bind(u8 pid, u8 cid, const char *name)
{
    GxNextionCrop o = {
        .base_obj = bind_gx_nextion_object_base(GX_NEXTION_CROP, pid, cid, name),
        .on_click = NULL,
        .on_release = NULL,
        .__data_click = NULL,
        .__data_release = NULL};
    return o;
}

void gx_nextion_crop_set_onclick(GxNextionCrop *pic, GxNextionCallback clbk, void *data)
{
    gx_nextion_set_objt_onclick(pic, GX_NEXTION_CROP, clbk, data);
}

void gx_nextion_crop_set_onrelease(GxNextionCrop *pic, GxNextionCallback clbk, void *data)
{
    gx_nextion_set_objt_onrelease(pic, GX_NEXTION_CROP, clbk, data);
}

GxBool gx_nextion_crop_set_crop(GxNextionCrop *pic, u32 img_id)
{
    return gx_nextion_set_objt_background_crop(pic, GX_NEXTION_CROP, img_id);
}
