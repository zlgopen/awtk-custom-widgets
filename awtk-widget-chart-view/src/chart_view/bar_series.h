﻿/**
 * File:   bar_series.h
 * Author: AWTK Develop Team
 * Brief:  bar series
 *
 * Copyright (c) 2018 - 2018  Guangzhou ZHIYUAN Electronics Co.,Ltd.
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
 * 2018-12-05 Xu ChaoZe <xuchaoze@zlg.cn> created
 *
 */

#ifndef TK_BAR_SERIES_H
#define TK_BAR_SERIES_H

#include "series.h"

BEGIN_C_DECLS

/**
 * @class bar_series_t
 * @parent widget_t
 * @annotation ["scriptable","design","widget"]
 * 柱条序列。
 * 
 * 在xml中使用"bar\_series"标签创建扩展按钮控件。如：
 *
 * ```xml
 * <!-- ui -->
 * <bar_series x="c" y="50" w="200" h="100" />
 * ```
 *
 * 可用通过style来设置控件的显示风格，如字体的大小和颜色等等。如：
 *
 * ```xml
 * <!-- style -->
 * <bar_series>
 *  <style name="default">
 *      <normal margin_bottom="1" margin_left="20" margin_right="2" margin_top="3" fg_color="#69CF5C"/>
 *  </style>
 * <bar_series_minmax>
 *  <style name="default">
 *      <normal margin_bottom="1" margin_left="20" margin_right="2" margin_top="3" fg_color="#36B3C3"/>
 *  </style>
 * </bar_series_minmax>
 * ```
 */
typedef struct _bar_series_t {
  series_t base;
  /**
   * @property {char*} series_axis
   * @annotation ["set_prop","get_prop","readable","persitent","design","scriptable"]
   * 标示序列位置的轴。
   */
  char* series_axis;
  /**
   * @property {char*} value_axis
   * @annotation ["set_prop","get_prop","readable","persitent","design","scriptable"]
   * 标示序列值的轴。
   */
  char* value_axis;
  /**
   * 柱条参数。
   */
  series_bar_params_t bar;
} bar_series_t;

/**
 * @method bar_series_create
 * 创建bar_series对象
 * @annotation ["constructor", "scriptable"]
 * @param {widget_t*} parent 父控件
 * @param {xy_t} x x坐标
 * @param {xy_t} y y坐标
 * @param {wh_t} w 宽度
 * @param {wh_t} h 高度
 *
 * @return {widget_t*} 对象。
 */
widget_t* bar_series_create(widget_t* widget, xy_t x, xy_t y, wh_t w, wh_t h);

/**
 * @method bar_series_minmax_create
 * 创建bar_series_minmax对象（同时显示最大最小值）
 * @annotation ["constructor", "scriptable"]
 * @param {widget_t*} parent 父控件
 * @param {xy_t} x x坐标
 * @param {xy_t} y y坐标
 * @param {wh_t} w 宽度
 * @param {wh_t} h 高度
 *
 * @return {widget_t*} 对象。
 */
widget_t* bar_series_minmax_create(widget_t* widget, xy_t x, xy_t y, wh_t w, wh_t h);

/**
 * @method bar_series_cast
 * 转换为bar_series对象(供脚本语言使用)。
 * @annotation ["cast", "scriptable"]
 * @param {widget_t*} widget bar_series对象。
 *
 * @return {widget_t*} bar_series对象。
 */
widget_t* bar_series_cast(widget_t* series);

/**
 * @method bar_series_register
 * 注册bar_series控件。
 *
 * @annotation ["scriptable", "static"]
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t bar_series_register(void);

/**
 * @method bar_series_minmax_register
 * 注册bar_series_minmax控件。
 *
 * @annotation ["scriptable", "static"]
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t bar_series_minmax_register(void);

#define BAR_SERIES(widget) ((bar_series_t*)(bar_series_cast(WIDGET(widget))))

END_C_DECLS

#endif /*TK_BAR_SERIES_H*/