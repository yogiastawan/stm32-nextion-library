/**
 * Copyright (c) 2023 I Gede Yogi Astawan
 *
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#ifndef __GIHEX_NEXTION_TIMER_H__
#define __GIHEX_NEXTION_TIMER_H__

#include "gx_nextion_touch.h"

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * @brief GxNextionTimer object. Aliased from struct _gx_nextion_object
     */
    typedef struct _gx_nextion_object GxNextionTimer;

    /**
     * @brief Binding new GxNextionTimer to Timer in nextion device
     * @param pid Page id location of Timer
     * @param cid Component id of Timer
     * @param name Name of Timer
     * @return Return GxNextionTimer object
     */
    GxNextionTimer gx_nextion_timer_bind(u8 pid, u8 cid, const char *name);

    /**
     * @brief Set time interval of GxNextionTimer
     * @param tmr GxNextionTimer object will be set
     * @param time_value Time interval value in milliseconds
     * @return Return GX_TRUE if success or otherwise GX_FALSE
     * @note The minimun time_value is 50 ms and maximum time_value is 65535 ms
     */
    GxBool gx_nextion_timer_set_interval(GxNextionTimer *tmr, u16 time_value);

    /**
     * @brief Get current time interval of the GxNextionTimer
     * @param tmr GxNextionTimer object
     * @param time_value Pointer that hold time interval value in milliseconds
     * @return Return GX_TRUE if success or otherwise return GX_FALSE
     */
    GxBool gx_timer_number_get_interval(GxNextionTimer *tmr, u16 *time_value);

    /**
     * @brief Enable or disable GxNextionTimer
     * @param tmr GxNextionTimer object
     * @param enable set to GX_TRUE to enable Timer or set to GX_FALSE to disable Timer
     * @return Return GX_TRUE if success or otherwise return GX_FALSE
     */
    GxBool gx_timer_set_enable(GxNextionTimer *tmr, GxBool enable);

    /**
     * @brief Get current status of GxNextionTimer
     * @param tmr GxNextionTimer object
     * @param is_enable Pointer that hold current status. Value will be GX_TRU if enabled, otherwise GX_FALSE
     * @return Return GX_TRUE if success or otherwise return GX_FALSE
     */
    GxBool gx_nextion_timer_is_enable(GxNextionTimer *tmr, GxBool *is_enable);

#ifdef __cplusplus
}
#endif

#endif /* __GIHEX_NEXTION_TIMER_H__ */
