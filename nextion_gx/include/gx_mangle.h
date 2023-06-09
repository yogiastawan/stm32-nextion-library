/**
 * Copyright (c) 2023 I Gede Yogi Astawan
 *
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#ifndef __GIHEX_NEXTION_MANGLE_H__
#define __GIHEX_NEXTION_MANGLE_H__

#include "stdint.h"

#ifdef __cplusplus
extern "C"
{
#endif

    typedef char i8;
    typedef unsigned char u8;
    typedef int16_t i16;
    typedef uint16_t u16;
    typedef int32_t i32;
    typedef uint32_t u32;
    typedef int64_t i64;
    typedef uint64_t u64;

    typedef float f32;
    typedef double f64;

    typedef u8 GxBool;

#define GX_FALSE (u8)0
#define GX_TRUE (u8)1

#ifdef __cplusplus
}
#endif

#endif /* __GIHEX_NEXTION_MANGLE_H__ */
