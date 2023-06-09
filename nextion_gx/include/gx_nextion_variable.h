/**
 * Copyright (c) 2023 I Gede Yogi Astawan
 *
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#ifndef __GIHEX_NEXTION_VARIABLE_H__
#define __GIHEX_NEXTION_VARIABLE_H__

#include "gx_nextion_object.h"

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct _gx_nextion_object GxNextionVariable;

    GxNextionVariable gx_nextion_variable_bind(u8 pid, u8 cid, const char *name);

    GxBool gx_nextion_variable_set_value(GxNextionVariable *obj, i32 value);
    GxBool gx_nextion_variable_get_value(GxNextionVariable *obj, i32 *value);

#ifdef __cplusplus
}
#endif

#endif /* __GIHEX_NEXTION_VARIABLE_H__ */
