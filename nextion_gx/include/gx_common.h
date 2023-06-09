/**
 * Copyright (c) 2023 I Gede Yogi Astawan
 *
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#ifndef __GIHEX_COMMON_H__
#define __GIHEX_COMMON_H__

// #define STM32_HAL "stm32f1xx_hal.h"

#include "stm32f1xx_hal.h"

#ifdef __cplusplus
extern "C"
{
#endif
#define return_if(cond) \
                        \
    if (cond)           \
    {                   \
        return;         \
    }
#define return_val_if(cond, val) \
                                 \
    if (cond)                    \
    {                            \
        return val;              \
    }

#define HORIZONTAL_ALIGNMENT_LEFT 0x00
#define HORIZONTAL_ALIGNMENT_CENTER 0x01
#define HORIZONTAL_ALIGNMENT_RIGHT 0x02
#define VERTICAL_ALIGNMENT_TOP 0x00
#define VERTICAL_ALIGNMENT_CENTER 0x01
#define VERTICAL_ALIGNMENT_BOTTOM 0x02
#define SCROLL_LEFT_TO_RIGHT 0x00
#define SCROLL_RIGHT_TO_LEFT 0x01
#define SCROLL_UP_TO_DOWN 0x02
#define SCROLL_DOWN_TO_UP 0x03

#define TEXT_TYPE_CHARACTER 0x00
#define TEXT_TYPE_PASSWORD 0x01

#define NUMBER_LENGTH_AUTO 0x00

#define NUMBER_FORMAT_DECIMAL 0x00
#define NUMBER_FORMAT_CURRENCY 0x01
#define NUMBER_FORMAT_HEX 0x02

#define WAVEFORM_GRID_NONE 0x00

#define CMD_END 0xFF

#define CMD_FINISH_OK 0x01
#define CMD_EVENT_LAUNCHED (0x88)
#define CMD_EVENT_UPGRADED (0x89)
#define CMD_EVENT_TOUCH_HEAD (0x65)
#define CMD_EVENT_POSITION_HEAD (0x67)
#define CMD_EVENT_SLEEP_POSITION_HEAD (0x68)
#define CMD_CURRENT_PAGE_ID_HEAD (0x66)
#define CMD_STRING_HEAD (0x70)
#define CMD_NUMBER_HEAD (0x71)
#define CMD_INVALID_CMD (0x00)
#define CMD_INVALID_COMPONENT_ID (0x02)
#define CMD_INVALID_PAGE_ID (0x03)
#define CMD_INVALID_PICTURE_ID (0x04)
#define CMD_INVALID_FONT_ID (0x05)
#define CMD_INVALID_BAUD (0x11)
#define CMD_INVALID_VARIABLE (0x1A)
#define CMD_INVALID_OPERATION (0x1B)

#ifdef _cplusplus
}
#endif
#endif /* __GIHEX_COMMON_H__ */
