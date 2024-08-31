
/**
 * @file main
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include <SDL2/SDL_video.h>
#define _DEFAULT_SOURCE /* needed for usleep() */
#include <stdlib.h>
#include <unistd.h>
#define SDL_MAIN_HANDLED /*To fix SDL's "undefined reference to WinMain" issue*/
#include <SDL2/SDL.h>
#include "lvgl/lvgl.h"
#include "lvgl/examples/lv_examples.h"
#include "lvgl/demos/lv_demos.h"
#include "lv_drivers/sdl/sdl.h"
// #include "lv_drivers/display/monitor.h"
// #include "lv_drivers/indev/mouse.h"
// #include "lv_drivers/indev/keyboard.h"
// #include "lv_drivers/indev/mousewheel.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void hal_init(void);
static int tick_thread(void *data);

/**********************
 *  STATIC VARIABLES
 **********************/
  int x = 0;
  int y = 0;
  int theta = 0;

static lv_obj_t * create_slider(lv_color_t color);
static void slider_event_cb(lv_event_t * e);
static lv_obj_t * red_slider, * green_slider, * blue_slider;

static void slider_event_cb(lv_event_t * e)
{
    LV_UNUSED(e);

    /*Recolor the image based on the sliders' values*/
    x = lv_slider_get_value(red_slider);
    y = lv_slider_get_value(green_slider);
    theta = lv_slider_get_value(blue_slider);
}
static lv_obj_t * create_slider(lv_color_t color)
{
    lv_obj_t * slider = lv_slider_create(lv_scr_act());
    lv_slider_set_range(slider, -72, 72);
    lv_obj_set_size(slider, 10, 200);
    lv_obj_set_style_bg_color(slider, color, LV_PART_KNOB);
    lv_obj_set_style_bg_color(slider, lv_color_darken(color, LV_OPA_40), LV_PART_INDICATOR);
    lv_obj_add_event_cb(slider, slider_event_cb, LV_EVENT_VALUE_CHANGED, NULL);
    return slider;
}
static void create_marker(lv_obj_t* parent, double row, double col) {
    lv_obj_t* marker = lv_obj_create(parent);
    lv_obj_set_size(marker, 5, 5);
    lv_obj_set_style_bg_color(marker, lv_color_hex(0xFFFFFF), 0);
    lv_obj_set_style_radius(marker, LV_RADIUS_CIRCLE, 0);
    lv_obj_align(marker, LV_ALIGN_CENTER, row, col);
}

/**********************
 *   GLOBAL FUNCTIONS
 **********************/
int main(int argc, char **argv)
{
  (void)argc; /*Unused*/
  (void)argv; /*Unused*/

  /*Initialize LVGL*/
  lv_init();

  /*Initialize the HAL (display, input devices, tick) for LVGL*/
  hal_init();

red_slider = create_slider(lv_palette_main(LV_PALETTE_RED));
lv_obj_align(red_slider, LV_ALIGN_LEFT_MID, 25, 120);
lv_obj_align_to(green_slider, red_slider, LV_ALIGN_OUT_RIGHT_MID, 25, 0);
lv_obj_align_to(blue_slider, green_slider, LV_ALIGN_OUT_RIGHT_MID, 25, 0);

  int horizontal_offset = -120;
  slider_event_cb(LV_EVENT_VALUE_CHANGED);
  while(1) {
    double horizontal_pos = ((x / 24.0) * 39.375 + horizontal_offset);
    double vertical_pos = ((y / -24.0) * 39.375);
    lv_obj_align(img2, LV_ALIGN_CENTER, horizontal_pos, vertical_pos);
    lv_img_set_angle(img2, (theta * 10));
    create_marker(view_cont, horizontal_pos, vertical_pos);
    lv_obj_move_foreground(img2);
    /* Periodically call the lv_task handler.
     * It could be done in a timer interrupt or an OS task too.*/
    lv_timer_handler();
    usleep(5 * 1000);
  }

  return 0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

/**
 * Initialize the Hardware Abstraction Layer (HAL) for the LVGL graphics
 * library
 */
static void hal_init(void)
{
  /* Use the 'monitor' driver which creates window on PC's monitor to simulate a display*/
  sdl_init();
  /* Tick init.
   * You have to call 'lv_tick_inc()' in periodically to inform LittelvGL about
   * how much time were elapsed Create an SDL thread to do this*/
  SDL_CreateThread(tick_thread, "tick", NULL);

  /*Create a display buffer*/
  static lv_disp_draw_buf_t disp_buf1;
  static lv_color_t buf1_1[MONITOR_HOR_RES * 100];
  static lv_color_t buf1_2[MONITOR_HOR_RES * 100];
  lv_disp_draw_buf_init(&disp_buf1, buf1_1, buf1_2, MONITOR_HOR_RES * 100);

  /*Create a display*/
  static lv_disp_drv_t disp_drv;
  lv_disp_drv_init(&disp_drv); /*Basic initialization*/
  disp_drv.draw_buf = &disp_buf1;
  disp_drv.flush_cb = sdl_display_flush;
  disp_drv.hor_res = MONITOR_HOR_RES;
  disp_drv.ver_res = MONITOR_VER_RES;
  disp_drv.antialiasing = 1;

  lv_disp_t * disp = lv_disp_drv_register(&disp_drv);

  lv_theme_t * th = lv_theme_default_init(disp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), LV_THEME_DEFAULT_DARK, LV_FONT_DEFAULT);
  lv_disp_set_theme(disp, th);

  lv_group_t * g = lv_group_create();
  lv_group_set_default(g);          /*Connect the image  object to the driver*/
}

/**
 * A task to measure the elapsed time for LVGL
 * @param data unused
 * @return never return
 */
static int tick_thread(void *data) {
  (void)data;

  while(1) {
    SDL_Delay(5);
    lv_tick_inc(5); /*Tell LittelvGL that 5 milliseconds were elapsed*/
  }

  return 0;
}
