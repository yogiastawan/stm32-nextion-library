/**
 * Copyright (c) 2023 I Gede Yogi Astawan
 *
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include "gx_nextion.h"

GxNextion new_gx_nextion(UART_HandleTypeDef *uart)
{
    GxNextion n = {
        .uart = uart,
        .time_out = 100};
    return n;
}

void gx_nextion_set_timeout(GxNextion *device, u32 time_ms)
{
    device->time_out = time_ms;
}

GxBool gx_nextion_init(GxNextion *nextion, u8 pid)
{
    return GX_FALSE;
}

void gx_nextion_send_cmd(GxNextion *nextion, char *cmd)
{
    u8 end[3] = {0xFF, 0xFF, 0xFF};
    HAL_UART_Transmit(nextion->uart, cmd, sizeof(char) * strlen(cmd), nextion->time_out);
    HAL_UART_Transmit(nextion->uart, end, sizeof(end), nextion->time_out);
}

u16 gx_nextion_return_string(GxNextion *nextion, char *buffer, u16 len)
{
    if (!buffer)
    {
        return 0;
    }

    u16 len_data = len + 4; // head_string in front +  0xFF in end 3 times
    char *tmp = (char *)malloc(sizeof(char) * (len_data));

    HAL_UART_Receive(nextion->uart, tmp, sizeof(char) * len_data, nextion->time_out);
    if (CMD_STRING_HEAD != tmp[0])
    {
        buffer = NULL;
        free(tmp);
        return 0;
    }

    u16 i = 0;
    char c;
    u8 end = 0;
    u16 count = 0;
    for (i = 1; (c = tmp[i]) != '\0' || i < len; i++) // start from index 1 because index 0 is string head
    {
        if (CMD_END == c)
        {
            end++;
            if (end >= 3)
            {
                break;
            }
        }
        else
        {
            count++;
            buffer[i] = c;
        }
    }
    buffer[count + 1] = '\0'; // add null terminator
    free(tmp);
    return count;
}

GxBool gx_nextion_return_number(GxNextion *nextion, i32 *number)
{
    if (!number)
    {
        return GX_FALSE;
    }

    GxBool ret = GX_FALSE;
    u8 tmp[8] = {0, 0, 0, 0, 0, 0, 0, 0};

    HAL_UART_Receive(nextion->uart, tmp, sizeof(tmp), nextion->time_out);
    if (CMD_NUMBER_HEAD == tmp[0] && CMD_END == tmp[5] && CMD_END == tmp[6] && CMD_END == tmp[7])
    {
        *number = ((i32)tmp[4] << 24) | ((i32)tmp[3] << 16) | (tmp[2] << 8) | (tmp[1]);
        ret = GX_TRUE;
    }
    return ret;
}

GxBool gx_cmd_finished(GxNextion *nextion)
{
    GxBool ret = GX_FALSE;
    u8 tmp[4] = {0, 0, 0, 0};

    HAL_UART_Receive(nextion->uart, tmp, sizeof(tmp), nextion->time_out);
    if (CMD_FINISH_OK == tmp[0] && CMD_END == tmp[1] && CMD_END == tmp[2] && CMD_END == tmp[3])
    {
        ret = GX_TRUE;
    }
    return ret;
}
