/**
 * Copyright (c) 2023 I Gede Yogi Astawan
 *
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include "gx_nextion_touch.h"

static void iterate(GxNextionTouch **list, u8 pid, u16 cid, u8 event);

void gx_nextion_loop(GxNextion *nextion, GxNextionTouch *touch_obj[])
{
    GxNextion *device = gx_nextion_current_device();
    return_if(device == NULL);
    return_if(NULL == touch_obj);

    // get data from serial and run iterate
}

void gx_nextion_set_objt_onclick(void *obj, u8 obj_type, GxNextionCallback clbk, void *data)
{
    GxNextionTouch *obt = (GxNextionTouch *)obj;
    return_if(obt->base_obj.obj_type != obj_type);
    obt->on_click = clbk;
    obt->__data_click = data;
}

void gx_nextion_set_objt_onrelease(void *obj, u8 obj_type, GxNextionCallback clbk, void *data)
{
    GxNextionTouch *obt = (GxNextionTouch *)obj;
    return_if(obt->base_obj.obj_type != obj_type);
    obt->on_release = clbk;
    obt->__data_release = data;
}

GxBool gx_nextion_set_objt_text(void *obj, u8 obj_type, const char *txt)
{
    GxNextion *device = gx_nextion_current_device();
    return_val_if(device == NULL, GX_FALSE);
    GxNextionTouch *obt = (GxNextionTouch *)obj;
    return_val_if(obt->base_obj.obj_type != obj_type, GX_FALSE);

    // set text
    u16 len_txt = strlen(txt) + strlen(obt->base_obj.name) + 8; //".txt="+\"\"+'\0'=8
    char *cmd = (char *)malloc(sizeof(char *) * len_txt);
    strcat(cmd, obt->base_obj.name);
    strcat(cmd, ".txt=\"");
    strcat(cmd, txt);
    strcat(cmd, "\"");
    gx_nextion_send_cmd(device, cmd);
    free(cmd);
    return gx_cmd_finished(device);
}

u16 gx_nextion_get_objt_text(void *obj, u8 obj_type, char *buffer, u16 len)
{
    GxNextion *device = gx_nextion_current_device();
    return_val_if(!device, 0);
    GxNextionTouch *obt = (GxNextionTouch *)obj;
    return_val_if(obt->base_obj.obj_type != obj_type, 0);
    u16 len_cmd = strlen(obt->base_obj.name) + 9; //"get "+".txt"+'\0'=9
    char *cmd = malloc(sizeof(char) * len_cmd);
    strcat(cmd, "get ");
    strcat(cmd, obt->base_obj.name);
    strcat(cmd, ".txt");
    gx_nextion_send_cmd(device, cmd);
    free(cmd);
    return gx_nextion_return_string(device, buffer, len);
}

GxBool gx_nextion_set_objt_value(void *obj, u8 obj_type, i32 value)
{
    GxNextion *device = gx_nextion_current_device();
    return_val_if(!device, GX_FALSE);
    GxNextionTouch *obt = (GxNextionTouch *)obj;
    return_val_if(obt->base_obj.obj_type != obj_type, GX_FALSE);
    // set value
    char v[11] = {0};
    __itoa(value, v, 10);
    u16 len_cmd = strlen(obt->base_obj.name) + 10 + 6; //".val="+'\0'=6
    char *cmd = malloc(sizeof(char) * len_cmd);
    strcat(cmd, obt->base_obj.name);
    strcat(cmd, ".val=");
    strcat(cmd, v);
    gx_nextion_send_cmd(device, cmd);
    free(cmd);
    return gx_cmd_finished(device);
}

GxBool gx_nextion_get_objt_value(void *obj, u8 obj_type, i32 *value)
{
    GxNextion *device = gx_nextion_current_device();
    return_val_if(!device, 0);
    GxNextionTouch *obt = (GxNextionTouch *)obj;
    return_val_if(obt->base_obj.obj_type != obj_type, 0);
    u16 len_cmd = strlen(obt->base_obj.name) + 9; //"get "+".val"+'\0'=9
    char *cmd = malloc(sizeof(char) * len_cmd);
    strcat(cmd, "get ");
    strcat(cmd, obt->base_obj.name);
    strcat(cmd, ".val");
    gx_nextion_send_cmd(device, cmd);
    free(cmd);
    return gx_nextion_return_number(device, value);
}

GxBool gx_nextion_set_objt_background_color(void *obj, u8 obj_type, u16 color)
{
    GxNextion *device = gx_nextion_current_device();
    return_val_if(!device, GX_FALSE);
    GxNextionTouch *obt = (GxNextionTouch *)obj;
    return_val_if(obt->base_obj.obj_type != obj_type, GX_FALSE);
    char v[6] = {0};
    __utoa(color, v, 10);
    u16 len_cmd = strlen(obt->base_obj.name) + 5 + 6; //".bco="+'\0'=6
    char *cmd = malloc(sizeof(char) * len_cmd);
    strcat(cmd, obt->base_obj.name);
    strcat(cmd, ".bco=");
    strcat(cmd, v);
    gx_nextion_send_cmd(device, cmd);
    free(cmd);
    return gx_cmd_finished(device);
}

GxBool gx_nextion_set_objt_background_img(void *obj, u8 obj_type, u32 img)
{
    GxNextion *device = gx_nextion_current_device();
    return_val_if(!device, GX_FALSE);
    GxNextionTouch *obt = (GxNextionTouch *)obj;
    return_val_if(obt->base_obj.obj_type != obj_type, GX_FALSE);
    char v[11] = {0};
    __utoa(img, v, 10);
    u16 len_cmd = strlen(obt->base_obj.name) + 10 + 6; //".pic="+'\0'=6
    char *cmd = malloc(sizeof(char) * len_cmd);
    strcat(cmd, obt->base_obj.name);
    strcat(cmd, ".pic=");
    strcat(cmd, v);
    gx_nextion_send_cmd(device, cmd);
    free(cmd);
    return gx_cmd_finished(device);
}

GxBool gx_nextion_set_objt_background_crop(void *obj, u8 obj_type, u32 img_crop)
{
    GxNextion *device = gx_nextion_current_device();
    return_val_if(!device, GX_FALSE);
    GxNextionTouch *obt = (GxNextionTouch *)obj;
    return_val_if(obt->base_obj.obj_type != obj_type, GX_FALSE);
    char v[11] = {0};
    __utoa(img_crop, v, 10);
    u16 len_cmd = strlen(obt->base_obj.name) + 10 + 7; //".picc="+'\0'=7
    char *cmd = malloc(sizeof(char) * len_cmd);
    strcat(cmd, obt->base_obj.name);
    strcat(cmd, ".picc=");
    strcat(cmd, v);
    gx_nextion_send_cmd(device, cmd);
    free(cmd);
    return gx_cmd_finished(device);
}

GxBool gx_nextion_set_objt_foreground_color(void *obj, u8 obj_type, u16 color)
{
    GxNextion *device = gx_nextion_current_device();
    return_val_if(!device, GX_FALSE);
    GxNextionTouch *obt = (GxNextionTouch *)obj;
    return_val_if(obt->base_obj.obj_type != obj_type, GX_FALSE);
    char v[6] = {0};
    __utoa(color, v, 10);
    u16 len_cmd = strlen(obt->base_obj.name) + 5 + 6; //".pco="+'\0'=6
    char *cmd = malloc(sizeof(char) * len_cmd);
    strcat(cmd, obt->base_obj.name);
    strcat(cmd, ".pco=");
    strcat(cmd, v);
    gx_nextion_send_cmd(device, cmd);
    free(cmd);
    return gx_cmd_finished(device);
}

GxBool gx_nextion_set_objt_font(void *obj, u8 obj_type, u32 font_id)
{
    GxNextion *device = gx_nextion_current_device();
    return_val_if(!device, GX_FALSE);
    GxNextionTouch *obt = (GxNextionTouch *)obj;
    return_val_if(obt->base_obj.obj_type != obj_type, GX_FALSE);
    char v[11] = {0};
    __utoa(font_id, v, 10);
    u16 len_cmd = strlen(obt->base_obj.name) + 10 + 7; //".font="+'\0'=7
    char *cmd = malloc(sizeof(char) * len_cmd);
    strcat(cmd, obt->base_obj.name);
    strcat(cmd, ".font=");
    strcat(cmd, v);
    gx_nextion_send_cmd(device, cmd);
    free(cmd);
    return gx_cmd_finished(device);
}

GxBool gx_nextion_set_objt_text_hor_alignment(void *obj, u8 obj_type, u8 horiontal_alignemet)
{
    GxNextion *device = gx_nextion_current_device();
    return_val_if(!device, GX_FALSE);
    GxNextionTouch *obt = (GxNextionTouch *)obj;
    return_val_if(obt->base_obj.obj_type != obj_type, GX_FALSE);
    char v[4] = {0};
    __utoa(horiontal_alignemet, v, 10);
    u16 len_cmd = strlen(obt->base_obj.name) + 3 + 7; //".xcen="+'\0'=7
    char *cmd = malloc(sizeof(char) * len_cmd);
    strcat(cmd, obt->base_obj.name);
    strcat(cmd, ".xcen=");
    strcat(cmd, v);
    gx_nextion_send_cmd(device, cmd);
    free(cmd);
    return gx_cmd_finished(device);
}

GxBool gx_nextion_set_objt_text_ver_alignment(void *obj, u8 obj_type, u8 vertical_alignemet)
{
    GxNextion *device = gx_nextion_current_device();
    return_val_if(!device, GX_FALSE);
    GxNextionTouch *obt = (GxNextionTouch *)obj;
    return_val_if(obt->base_obj.obj_type != obj_type, GX_FALSE);
    char v[4] = {0};
    __utoa(vertical_alignemet, v, 10);
    u16 len_cmd = strlen(obt->base_obj.name) + 3 + 7; //".ycen="+'\0'=7
    char *cmd = malloc(sizeof(char) * len_cmd);
    strcat(cmd, obt->base_obj.name);
    strcat(cmd, ".ycen=");
    strcat(cmd, v);
    gx_nextion_send_cmd(device, cmd);
    free(cmd);
    return gx_cmd_finished(device);
}

GxBool gx_nextion_set_objt_text_wrap(void *obj, u8 obj_type, GxBool wrap)
{
    GxNextion *device = gx_nextion_current_device();
    return_val_if(!device, GX_FALSE);
    GxNextionTouch *obt = (GxNextionTouch *)obj;
    return_val_if(obt->base_obj.obj_type != obj_type, GX_FALSE);
    u16 len_cmd = strlen(obt->base_obj.name) + sizeof(wrap) + 7; //".isbr="+'\0'=7
    char v[sizeof(wrap)] = {0};
    memcpy(v, &wrap, sizeof(wrap));
    char *cmd = malloc(sizeof(char) * len_cmd);
    strcat(cmd, obt->base_obj.name);
    strcat(cmd, ".isbr=");
    strcat(cmd, v);
    gx_nextion_send_cmd(device, cmd);
    free(cmd);
    return gx_cmd_finished(device);
}

static void iterate(GxNextionTouch **list, u8 pid, u16 cid, u8 event)
{
    if (NULL == list)
    {
        return;
    }

    GxNextionTouch *t = NULL;
    u32 i = 0;

    for (i = 0; (t = list[i]) != NULL; i++)
    {
        if (t->base_obj.pid != pid)
        {
            continue;
        }
        if (cid != t->base_obj.cid)
        {
            continue;
        }

        if (GX_NEXTION_EVENT_TOUCHPRESS == event)
        {
            if (!t->on_click)
            {
                continue;
            }

            t->on_click(t->__data_click);
        }

        else if (GX_NEXTION_EVENT_RELEASE == event)
        {
            if (!t->on_release)
            {
                continue;
            }
            t->on_release(t->__data_release);
        }
    }
}