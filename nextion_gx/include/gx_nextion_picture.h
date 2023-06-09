/**
 * Copyright (c) 2023 I Gede Yogi Astawan
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#ifndef __GIHEX_NEXTION_PICTURE_H__
#define __GIHEX_NEXTION_PICTURE_H__

#include "gx_nextion_touch.h"

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct _gx_nextion_touch GxNextionPicture;

    GxNextionPicture gx_nextion_picture_bind(u8 pid, u8 cid, const char *name);

    void gx_nextion_picture_set_onclick(GxNextionPicture *pic, GxNextionCallback clbk, void *data);
    void gx_nextion_picture_set_onrelease(GxNextionPicture *pic, GxNextionCallback clbk, void *data);

    GxBool gx_nextion_picture_set_image(GxNextionPicture *pic, u32 img_id);

#ifdef __cplusplus
}
#endif

#endif /* __GIHEX_NEXTION_PICTURE_H__ */
