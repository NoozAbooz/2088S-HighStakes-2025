
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
green_slider = create_slider(lv_palette_main(LV_PALETTE_GREEN));
blue_slider = create_slider(lv_palette_main(LV_PALETTE_BLUE));

lv_slider_set_value(red_slider, 24, LV_ANIM_OFF);
lv_slider_set_value(green_slider, 24, LV_ANIM_OFF);
lv_slider_set_value(blue_slider, 0, LV_ANIM_OFF);

lv_obj_align(red_slider, LV_ALIGN_LEFT_MID, 25, 120);
lv_obj_align_to(green_slider, red_slider, LV_ALIGN_OUT_RIGHT_MID, 25, 0);
lv_obj_align_to(blue_slider, green_slider, LV_ALIGN_OUT_RIGHT_MID, 25, 0);
    

  lv_obj_t *screen = lv_scr_act();
  lv_obj_t *view_cont = lv_obj_create(screen);
  lv_obj_clear_flag(view_cont, LV_OBJ_FLAG_SCROLLABLE);
	lv_obj_set_size(view_cont, 480, 240);
	lv_obj_align(view_cont, LV_ALIGN_TOP_LEFT, 0, 0);
  lv_obj_set_style_bg_color(view_cont, lv_color_black(), LV_PART_MAIN);

  static lv_style_t style_title;
  lv_style_init(&style_title);
  lv_style_set_text_font(&style_title, &lv_font_montserrat_20); 
  lv_style_set_text_decor(&style_title, LV_TEXT_DECOR_UNDERLINE);

  static lv_style_t style_data;
  lv_style_init(&style_data);
  lv_style_set_text_font(&style_data, &lv_font_montserrat_16); 

  lv_obj_t* label = lv_label_create(view_cont);
  lv_label_set_recolor(label, true); 
  lv_label_set_text(label, "#ffffff 210P Odom");
  lv_obj_align(label, LV_ALIGN_CENTER, 120, -80);
  lv_obj_add_style(label, &style_title, 0);

  lv_obj_t* label1 = lv_label_create(view_cont);
  lv_label_set_recolor(label1, true); 
  lv_obj_align(label1, LV_ALIGN_CENTER, 60, -40);
  lv_obj_add_style(label1, &style_data, 0);

  lv_obj_t* label2 = lv_label_create(view_cont);
  lv_label_set_recolor(label2, true); 
  lv_obj_align(label2, LV_ALIGN_CENTER, 60, 0);
  lv_obj_add_style(label2, &style_data, 0);

  lv_obj_t* label3 = lv_label_create(view_cont);
  lv_label_set_recolor(label3, true); 
  lv_obj_align(label3, LV_ALIGN_CENTER, 60, 40);
  lv_obj_add_style(label3, &style_data, 0);

  LV_IMG_DECLARE(field);
  lv_obj_t * img = lv_img_create(view_cont);
  lv_img_set_src(img, &field);
  lv_obj_align(img, LV_ALIGN_CENTER, -120, 0);
  lv_img_set_zoom(img, 84);

  LV_IMG_DECLARE(arrow);
  lv_obj_t * img2 = lv_img_create(view_cont);
  lv_img_set_src(img2, &arrow);
  lv_obj_align(img2, LV_ALIGN_CENTER, 0, 0);
  lv_img_set_zoom(img2, 64);

  int horizontal_offset = -120;
  slider_event_cb(LV_EVENT_VALUE_CHANGED);
  while(1) {
    double horizontal_pos = ((x / 24.0) * 39.375 + horizontal_offset);
    double vertical_pos = ((y / -24.0) * 39.375);
    lv_obj_align(img2, LV_ALIGN_CENTER, horizontal_pos, vertical_pos);
    lv_img_set_angle(img2, (theta * 10));
    create_marker(view_cont, horizontal_pos, vertical_pos);
    lv_obj_move_foreground(img2);
    
    char buf[32];
    snprintf(buf, 32, "#ffffff X: %d", lv_slider_get_value(red_slider));
    lv_label_set_text(label1, buf);

    snprintf(buf, 32, "#ffffff Y: %d", lv_slider_get_value(green_slider));
    lv_label_set_text(label2, buf);

    snprintf(buf, 32, LV_SYMBOL_GPS "#ffffff : %d°", lv_slider_get_value(blue_slider));
    lv_label_set_text(label3, buf);

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
  lv_group_set_default(g);

  /* Add the mouse as input device
   * Use the 'mouse' driver which reads the PC's mouse*/
  // mouse_init();
  static lv_indev_drv_t indev_drv_1;
  lv_indev_drv_init(&indev_drv_1); /*Basic initialization*/
  indev_drv_1.type = LV_INDEV_TYPE_POINTER;

  /*This function will be called periodically (by the library) to get the mouse position and state*/
  indev_drv_1.read_cb = sdl_mouse_read;
  lv_indev_t *mouse_indev = lv_indev_drv_register(&indev_drv_1);

  // keyboard_init();
  static lv_indev_drv_t indev_drv_2;
  lv_indev_drv_init(&indev_drv_2); /*Basic initialization*/
  indev_drv_2.type = LV_INDEV_TYPE_KEYPAD;
  indev_drv_2.read_cb = sdl_keyboard_read;
  lv_indev_t *kb_indev = lv_indev_drv_register(&indev_drv_2);
  lv_indev_set_group(kb_indev, g);
  // mousewheel_init();
  static lv_indev_drv_t indev_drv_3;
  lv_indev_drv_init(&indev_drv_3); /*Basic initialization*/
  indev_drv_3.type = LV_INDEV_TYPE_ENCODER;
  indev_drv_3.read_cb = sdl_mousewheel_read;

  lv_indev_t * enc_indev = lv_indev_drv_register(&indev_drv_3);
  lv_indev_set_group(enc_indev, g);

  /*Set a cursor for the mouse*/
  LV_IMG_DECLARE(mouse_cursor_icon); /*Declare the image file.*/
  lv_obj_t * cursor_obj = lv_img_create(lv_scr_act()); /*Create an image object for the cursor */
  lv_img_set_src(cursor_obj, &mouse_cursor_icon);           /*Set the image source*/
  lv_indev_set_cursor(mouse_indev, cursor_obj);            /*Connect the image  object to the driver*/
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
