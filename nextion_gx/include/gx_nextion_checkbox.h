#ifndef __GIHEX_NEXTION_CHECKBOX_H__
#define __GIHEX_NEXTION_CHECKBOX_H__

#include "gx_nextion_touch.h"

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * @brief GxNextionCheckBox object. Aliased from struct _gx_nextion_touch
     */
    typedef struct _gx_nextion_touch GxNextionCheckBox;

    GxNextionCheckBox gx_nextion_checkbox_bind(u8 pid, u8 cid, const char *name);

    void gx_nextion_checkbox_set_onclick(GxNextionCheckBox *cbk, GxNextionCallback clbk, void *data);
    void gx_nextion_checkbox_set_onrelease(GxNextionCheckBox *cbk, GxNextionCallback clbk, void *data);

    GxBool gx_nextion_checkbox_set_value(GxNextionCheckBox *cbk, GxBool active);
    GxBool gx_nexttion_checkbox_get_value(GxNextionCheckBox *cbk, GxBool *value);

    GxBool gx_nextion_checkbox_set_background_color(GxNextionCheckBox *cbk, u16 clr);
    GxBool gx_nextion_checkbox_set_foreground_color(GxNextionCheckBox *cbk, u16 clr);

#ifdef __cplusplus
}
#endif

#endif /* __GIHEX_NEXTION_CHECKBOX_H__ */
