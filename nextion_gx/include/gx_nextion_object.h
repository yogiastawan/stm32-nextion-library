/**
 * Copyright (c) 2023 I Gede Yogi Astawan
 *
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#ifndef __GIHEX_NEXTION_OBJECT_H__
#define __GIHEX_NEXTION_OBJECT_H__

#include "gx_common.h"

#include "gx_mangle.h"
#include "gx_components.h"

#include "gx_nextion.h"

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * @brief GxNextionObjectBase object. Aliased from struct _gx_nextion_obj
     */
    typedef struct _gx_nextion_obj GxNextionObjectBase;

    /**
     * @brief Struct _gx_nextion_obj
     * @note This struct hold base object information
     */
    struct _gx_nextion_obj
    {
        /**
         * @brief Type of object
         * @note Can be assigened by GX_NEXTION_[TYPE]_[TYPE]
         */
        u8 obj_type;
        /**
         * @brief Page id where object located
         */
        u8 pid;
        /**
         * @brief Component id of object
         */
        u8 cid;
        /**
         * @brief Name of component
         */
        const char *name;
    };

    /**
     * @brief Bind new GxNextionObjectBase
     * @param obj_type Object yype. GX_NEXTION_[TYPE]_[TYPE]
     * @param pid Page id where object located
     * @param cid Component id
     * @param name Component name
     * @return Return GxNextionObjectBase
     */
    GxNextionObjectBase bind_gx_nextion_object_base(u8 obj_type, u8 pid, u8 cid, const char *name);

    /**
     * @brief GxNextionObject object. Aliased from struct _gx_nextion_object
     */
    typedef struct _gx_nextion_object GxNextionObject;

    /// @brief Struct _gx_nextion_object
    /// @note Derive this object to create component
    struct _gx_nextion_object
    {
        /**
         * @brief Base object
         */
        GxNextionObjectBase base_obj;
    };

    /**
     * @brief Set value to object
     * @param obj Object will be set
     * @param obj_type Type of object
     * @param value value to set
     * @return Return GX_TRUE if success, otherwise return GX_FALSE
     * @note Parameter obj_type can be assigned by GX_NEXTION_[TYPE]_[TYPE]
     */
    GxBool gx_nextion_set_obj_value(void *obj, u8 obj_type, i32 value);

    /**
     * @brief Get value of object
     * @param obj Object
     * @param obj_type Type of object
     * @param value Pointer to hold the value
     * @return Return GX_TRUE if success, otherwise return GX_FALSE
     * @note Parameter obj_type can be assigned by GX_NEXTION_[TYPE]_[TYPE]
     */
    GxBool gx_nextion_get_obj_value(void *obj, u8 obj_type, i32 *value);

    /**
     * @brief Select device will be use
     * @param nextion Nextion object device
     * @note If we have multiple Nextion device display, we can rely between device using this function
     */
    void gx_nextion_use_device(GxNextion *nextion);

    /**
     * @brief Get currrent used Nextion object display
     * @return Pointer of current Nextion Object
     */
    GxNextion *gx_nextion_current_device();

#ifdef __cplusplus
}
#endif

#endif /* __GIHEX_NEXTION_OBJECT_H__ */
