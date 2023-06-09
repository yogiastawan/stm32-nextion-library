/**
 * Copyright (c) 2023 I Gede Yogi Astawan
 *
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

/**
 * @file gx_nextion.h
 * @brief Nextion display library
 */

#ifndef __GIHEX_NEXTION_H__
#define __GIHEX_NEXTION_H__

#include "stdlib.h"
#include "string.h"

#include "gx_common.h"

#include "gx_components.h"
#include "gx_mangle.h"

#ifdef __cplusplus
extern "C"
{
#endif

    /// @brief GxNextion object
    typedef struct _nextion_gx GxNextion;

    /// @brief Struct _nextion_gx object
    struct _nextion_gx
    {
        /// @brief Uart for communication to nextion device
        UART_HandleTypeDef *uart;
        /// @brief Uart nextion time out
        u32 time_out;
    };

    /**
     *@brief Create new nextion device
     * @param uart Pointer UART_HandleTypeDef
     */
    GxNextion new_gx_nextion(UART_HandleTypeDef *uart);

    /**
     * @brief Set nextion time out when send command or receive data
     * @param device Pointer to nextion device
     * @param time_ms time out in milliseconds
     */
    void gx_nextion_set_timeout(GxNextion *device, u32 time_ms);

    /**
     * @brief Initialize nextion device
     * @param nextion Pointer to nextion device
     * @param pid Page will be loaded when power on
     * @return Return GX_TRUE if success or GX_FALSE if false
     */
    GxBool gx_nextion_init(GxNextion *nextion, u8 pid);

    /**
     * @brief Send command to nextion device
     * @param nextion Pointer to nextion device
     * @param cmd Command will be send to nextion device
     */
    void gx_nextion_send_cmd(GxNextion *nextion, char *cmd);

    /**
     * @brief Get string from component display
     * @param nextion Pointer to nextion device
     * @param buffer Pointer to store string
     * @param len Length of character to store in buffer
     * @return Return length of character stored in buffer
     * @note Memory allocation for parameter buffer must be extra 1 byte (len +1) for null terminator. Example if we
     * want to get 30 characters (len=30), we must set size memory allocation of buffer to 31 (char buffer[31] or buffer=malloc(sizeof(char)*31))
     */
    u16 gx_nextion_return_string(GxNextion *nextion, char *buffer, u16 len);

    /**
     * @brief Get number from component display
     * @param nextion Pointer to nextion device
     * @param number Pointer to store 32 bit number
     * @return Return GX_TRUE if success or GX_FALSE if failed.
     */
    GxBool gx_nextion_return_number(GxNextion *nextion, i32 *number);

    /**
     * @brief Check if command sent to nextion device success or fail
     * @param nextion Pointer to nextion device
     * @return Return GX_TRUE if success or GX_FALSE if failed.
     */
    GxBool gx_cmd_finished(GxNextion *nextion);

#ifdef __cplusplus
}
#endif

#endif /* __GIHEX_NEXTION_H__ */
