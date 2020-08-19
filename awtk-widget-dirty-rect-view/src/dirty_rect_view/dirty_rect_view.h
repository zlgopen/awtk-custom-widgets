﻿/**
 * File:   dirty_rect_view.h
 * Author: AWTK Develop Team
 * Brief:  自定义脏矩形控件
 *
 * Copyright (c) 2020 - 2020 Guangzhou ZHIYUAN Electronics Co.,Ltd.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * License file for more details.
 *
 */

/**
 * History:
 * ================================================================
 * 2020-06-16 Luo ZhiMing <luozhiming@zlg.cn> created
 *
 */


#ifndef TK_DIRTY_RECT_VIEW_H
#define TK_DIRTY_RECT_VIEW_H

#include "base/widget.h"

BEGIN_C_DECLS
/**
 * @class dirty_rect_view_t
 * @parent widget_t
 * @annotation ["scriptable","design","widget"]
 * 自定义脏矩形控件
 * 
 * 在xml中使用dirty\_rect\_view"标签创建扩展按钮控件。如：
 *
 * ```xml
 * <!-- ui -->
 * <dirty_rect_view x="c" y="50" w="24" h="100" />
 * ```
 */
typedef struct _dirty_rect_view_t {
  widget_t widget;


  /**
   * @property {int32_t} lcd_buff_number
   * @annotation ["set_prop","get_prop","readable","persitent","design","scriptable"]
   * lcd 的缓冲 buff 个数，注意 lcd 的缓冲一定是要按照顺序来切换，否则会乱套。
   */
  int32_t lcd_buff_number;

  /**
   * @property {bool_t} enable_dirty_rect_view
   * @annotation ["set_prop","get_prop","readable","persitent","design","scriptable"]
   * 是否开启自定义脏矩形。
   */
  bool_t enable_dirty_rect_view;
  
  /* private */
  int32_t paint_background_number;
} dirty_rect_view_t;

/**
 * @method dirty_rect_view_create
 * @annotation ["constructor", "scriptable"]
 * 创建dirty_rect_view对象
 * @param {widget_t*} parent 父控件
 * @param {xy_t} x x坐标
 * @param {xy_t} y y坐标
 * @param {wh_t} w 宽度
 * @param {wh_t} h 高度
 *
 * @return {widget_t*} dirty_rect_view对象。
 */
widget_t* dirty_rect_view_create(widget_t* parent, xy_t x, xy_t y, wh_t w, wh_t h);

/**
 * @method dirty_rect_view_cast
 * 转换为dirty_rect_view对象(供脚本语言使用)。
 * @annotation ["cast", "scriptable"]
 * @param {widget_t*} widget dirty_rect_view对象。
 *
 * @return {widget_t*} dirty_rect_view对象。
 */
widget_t* dirty_rect_view_cast(widget_t* widget);


/**
 * @method dirty_rect_view_set_lcd_buff_number
 * 设置 lcd 的缓冲 buff 个数，注意 lcd 的缓冲一定是要按照顺序来切换，否则会乱套。
 * @annotation ["scriptable"]
 * @param {widget_t*} widget widget对象。
 * @param {int32_t} lcd_buff_number lcd 的缓冲 buff 个数，注意 lcd 的缓冲一定是要按照顺序来切换，否则会乱套。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t dirty_rect_view_set_lcd_buff_number(widget_t* widget, int32_t lcd_buff_number);

/**
 * @method dirty_rect_view_set_enable_dirty_rect_view
 * 设置是否开启自定义脏矩形。
 * @annotation ["scriptable"]
 * @param {widget_t*} widget widget对象。
 * @param {bool_t} enable_dirty_rect_view 是否开启自定义脏矩形。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t dirty_rect_view_set_enable_dirty_rect_view(widget_t* widget, bool_t enable_dirty_rect_view);


#define DIRTY_RECT_VIEW_PROP_LCD_BUFF_NUMBER "lcd_buff_number"
#define DIRTY_RECT_VIEW_PROP_ENABLE_DIRTY_RECT_VIEW "enable_dirty_rect_view"

#define WIDGET_TYPE_DIRTY_RECT_VIEW "dirty_rect_view"

#define DIRTY_RECT_VIEW(widget) ((dirty_rect_view_t*)(dirty_rect_view_cast(WIDGET(widget))))

/*public for subclass and runtime type check*/
TK_EXTERN_VTABLE(dirty_rect_view);

END_C_DECLS

#endif /*TK_DIRTY_RECT_VIEW_H*/