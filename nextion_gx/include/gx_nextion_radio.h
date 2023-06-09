/**
 * Copyright (c) 2023 I Gede Yogi Astawan
 *
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#ifndef __GIHEX_NEXTION_RADIO_H__
#define __GIHEX_NEXTION_RADIO_H__

#include "gx_nextion_touch.h"

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct _gx_nextion_touch GxNextionRadio;

    GxNextionRadio gx_nextion_radio_bind(u8 pid, u8 cid, const char *name);

    void gx_nextion_radio_set_onclick(GxNextionRadio *cbk, GxNextionCallback clbk, void *data);
    void gx_nextion_radio_set_onrelease(GxNextionRadio *cbk, GxNextionCallback clbk, void *data);

    GxBool gx_nextion_radio_set_value(GxNextionRadio *cbk, GxBool active);
    GxBool gx_nexttion_radio_get_value(GxNextionRadio *cbk, GxBool *active);

    GxBool gx_nextion_radio_set_background_color(GxNextionRadio *cbk, u16 clr);
    GxBool gx_nextion_radio_set_foreground_color(GxNextionRadio *cbk, u16 clr);

#ifdef __cplusplus
}
#endif

#endif /* __GIHEX_NEXTION_RADIO_H__ */
