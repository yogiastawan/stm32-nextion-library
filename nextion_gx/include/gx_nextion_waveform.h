/**
 * Copyright (c) 2023 I Gede Yogi Astawan
 *
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#ifndef __GIHEX_NEXTION_WAVEFORM_H__
#define __GIHEX_NEXTION_WAVEFORM_H__

#include "gx_nextion_touch.h"

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct _gx_nextion_touch GxNextionWaveform;

    GxNextionWaveform gx_nextion_waveform_bind(u8 pid, u8 cid, const char *name);

    void gx_nextion_waveform_set_onclick(GxNextionWaveform *wave, GxNextionCallback clbk, void *data);
    void gx_nextion_waveform_set_onrelease(GxNextionWaveform *wave, GxNextionCallback clbk, void *data);

    GxBool gx_nextion_waveform_set_background_color(GxNextionWaveform *wave, u16 clr);
    GxBool gx_nextion_waveform_set_background_image(GxNextionWaveform *wave, u32 img);
    GxBool gx_nextion_waveform_set_background_image_crop(GxNextionWaveform *wave, u32 img);

    GxBool gx_nextion_waveform_set_grid_color(GxNextionWaveform *wave, u16 clr);
    GxBool gx_nextion_waveform_set_grid_width(GxNextionWaveform *wave, u32 width);
    GxBool gx_nextion_waveform_set_grid_height(GxNextionWaveform *wave, u32 height);

    GxBool gx_nextion_waveform_set_data_scaling(GxNextionWaveform *wave, u8 scale);
    GxBool gx_nextion_waveform_set_channel_color(GxNextionWaveform *wave, u8 channel_index, u16 clr);

    GxBool gx_nextion_wave_form_add_data(GxNextionWaveform *wave, u8 channel_index, u8 data);
    GxBool gx_nextion_wave_form_clear_data(GxNextionWaveform *wave, u8 channel_index);

#ifdef __cplusplus
}
#endif

#endif /* __GIHEX_NEXTION_WAVEFORM_H__ */
