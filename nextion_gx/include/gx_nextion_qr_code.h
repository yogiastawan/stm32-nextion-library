/**
 * Copyright (c) 2023 I Gede Yogi Astawan
 *
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#ifndef __GIHEX_NEXTION_QRCODE_H__
#define __GIHEX_NEXTION_QRCODE_H__

#include "gx_nextion_touch.h"

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct _gx_nextion_touch GxNextionQRCode;

    GxNextionQRCode gx_nextion_qr_code_bind(u8 pid, u8 cid, const char *name);

    void gx_nextion_qr_code_set_onclick(GxNextionQRCode *qr, GxNextionCallback clbk, void *data);
    void gx_nextion_qr_code_set_onrelease(GxNextionQRCode *qr, GxNextionCallback clbk, void *data);

    GxBool gx_nextion_qr_code_set_spax(GxNextionQRCode *qr, u8 spax);
    GxBool gx_nextion_qr_code_set_text(GxNextionQRCode *qr, const char *txt);

    GxBool gx_nextion_qr_code_set_background_color(GxNextionQRCode *qr, u16 clr);
    GxBool gx_nextion_qr_code_set_foreground_color(GxNextionQRCode *qr, u16 clr);

#ifdef __cplusplus
}
#endif

#endif /* __GIHEX_NEXTION_QRCODE_H__ */
