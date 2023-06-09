/**
 * Copyright (c) 2023 I Gede Yogi Astawan
 *
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include "gx_nextion_qr_code.h"

GxNextionQRCode gx_nextion_qr_code_bind(u8 pid, u8 cid, const char *name)
{
    GxNextionQRCode o = {
        .base_obj = bind_gx_nextion_object_base(GX_NEXTION_QR_CODE, pid, cid, name),
        .on_click = NULL,
        .on_release = NULL,
        .__data_click = NULL,
        .__data_release = NULL};
    return o;
}

void gx_nextion_qr_code_set_onclick(GxNextionQRCode *qr, GxNextionCallback clbk, void *data)
{
    gx_nextion_set_objt_onclick(qr, GX_NEXTION_QR_CODE, clbk, data);
}

void gx_nextion_qr_code_set_onrelease(GxNextionQRCode *qr, GxNextionCallback clbk, void *data)
{
    gx_nextion_set_objt_onrelease(qr, GX_NEXTION_QR_CODE, clbk, data);
}

GxBool gx_nextion_qr_code_set_spax(GxNextionQRCode *qr, u8 spax)
{
    GxNextion *device = gx_nextion_current_device();
    return_val_if(!device, GX_FALSE);
    return_val_if(qr->base_obj.obj_type != GX_NEXTION_QR_CODE, GX_FALSE);
    char v[6] = {0};
    __utoa(spax, v, 10);
    u16 len_cmd = strlen(qr->base_obj.name) + 5 + 6; //".dis="+'\0'=6
    char *cmd = malloc(sizeof(char) * len_cmd);
    strcat(cmd, qr->base_obj.name);
    strcat(cmd, ".dis=");
    strcat(cmd, v);
    gx_nextion_send_cmd(device, cmd);
    free(cmd);
    return gx_cmd_finished(device);
}

GxBool gx_nextion_qr_code_set_text(GxNextionQRCode *qr, const char *txt)
{
    return gx_nextion_set_objt_text(qr, GX_NEXTION_QR_CODE, txt);
}

GxBool gx_nextion_qr_code_set_background_color(GxNextionQRCode *qr, u16 clr)
{
    return gx_nextion_set_objt_background_color(qr, GX_NEXTION_QR_CODE, clr);
}

GxBool gx_nextion_qr_code_set_foreground_color(GxNextionQRCode *qr, u16 clr)
{
    return gx_nextion_set_objt_foreground_color(qr, GX_NEXTION_QR_CODE, clr);
}
