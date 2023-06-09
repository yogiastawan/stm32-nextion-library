/**
 * Copyright (c) 2023 I Gede Yogi Astawan
 *
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include "gx_nextion_variable.h"

GxNextionVariable gx_nextion_variable_bind(u8 pid, u8 cid, const char *name)
{
    GxNextionVariable o = {
        .base_obj = bind_gx_nextion_object_base(GX_NEXTION_VARIABLE, pid, cid, name)};
    return o;
}

GxBool gx_nextion_variable_set_value(GxNextionVariable *obj, i32 value)
{
    gx_nextion_set_obj_value(obj, GX_NEXTION_VARIABLE, value);
}

GxBool gx_nextion_variable_get_value(GxNextionVariable *obj, i32 *value)
{
    return gx_nextion_get_obj_value(obj, GX_NEXTION_VARIABLE, value);
}
