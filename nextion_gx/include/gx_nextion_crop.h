/**
 * Copyright (c) 2023 I Gede Yogi Astawan
 *
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#ifndef __GIHEX_NEXTION_CROP_H__
#define __GIHEX_NEXTION_CROP_H__

#include "gx_nextion_touch.h"

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct _gx_nextion_touch GxNextionCrop;

    GxNextionCrop gx_nextion_crop_bind(u8 pid, u8 cid, const char *name);

    void gx_nextion_crop_set_onclick(GxNextionCrop *pic, GxNextionCallback clbk, void *data);
    void gx_nextion_crop_set_onrelease(GxNextionCrop *pic, GxNextionCallback clbk, void *data);

    GxBool gx_nextion_crop_set_crop(GxNextionCrop *pic, u32 img_id);

#ifdef __cplusplus
}
#endif

#endif /* __GIHEX_NEXTION_CROP_H__ */
