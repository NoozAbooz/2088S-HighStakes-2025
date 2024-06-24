#include "main.h"

// Funky inits for robodash
rd::Console console;
rd_view_t *gifview = rd_view_create("Logo");
Gif gif("/usd/logo2.gif", rd_view_obj(gifview));

// odoormetry view
rd_view_t *odomview = rd_view_create("Odometry");
int horizontal_offset = -120;

static void create_marker(lv_obj_t* parent, double row, double col) {
    lv_obj_t* marker = lv_obj_create(parent);
    lv_obj_set_size(marker, 5, 5);
    lv_obj_set_style_bg_color(marker, lv_color_hex(0xFFFFFF), 0);
    lv_obj_set_style_radius(marker, LV_RADIUS_CIRCLE, 0);
    lv_obj_align(marker, LV_ALIGN_CENTER, row, col);
}

void strait::odomViewInit() {
  // LV_IMG_DECLARE(field);
  // lv_obj_t * img = lv_img_create(rd_view_obj(odomview));
  // LV_IMG_DECLARE(arrow);
  // lv_obj_t * img2 = lv_img_create(rd_view_obj(odomview));

  lv_obj_t* label1 = lv_label_create(rd_view_obj(odomview));
  lv_obj_t* label2 = lv_label_create(rd_view_obj(odomview));
  lv_obj_t* label3 = lv_label_create(rd_view_obj(odomview));
  lv_obj_t* label = lv_label_create(rd_view_obj(odomview));

  // lv_img_set_src(img, &field);
  // lv_obj_align(img, LV_ALIGN_CENTER, -120, 0);
  // lv_img_set_zoom(img, 84);

  // lv_img_set_src(img2, &arrow);
  // lv_obj_align(img2, LV_ALIGN_CENTER, 0, 0);
  // lv_img_set_zoom(img2, 64);

  static lv_style_t style_title;
  lv_style_init(&style_title);
  lv_style_set_text_font(&style_title, &lv_font_montserrat_20); 
  lv_style_set_text_decor(&style_title, LV_TEXT_DECOR_UNDERLINE);

  static lv_style_t style_data;
  lv_style_init(&style_data);
  lv_style_set_text_font(&style_data, &lv_font_montserrat_16); 

  lv_label_set_recolor(label, true); 
  lv_label_set_text(label, "#ffffff 2088S Debug");
  lv_obj_align(label, LV_ALIGN_CENTER, 120, -80);
  lv_obj_add_style(label, &style_title, 0);

  lv_label_set_recolor(label1, true); 
  lv_obj_align(label1, LV_ALIGN_CENTER, 60, -40);
  lv_obj_add_style(label1, &style_data, 0);

  lv_label_set_recolor(label2, true); 
  lv_obj_align(label2, LV_ALIGN_CENTER, 60, 0);
  lv_obj_add_style(label2, &style_data, 0);

  lv_label_set_recolor(label3, true); 
  lv_obj_align(label3, LV_ALIGN_CENTER, 60, 40);
  lv_obj_add_style(label3, &style_data, 0);

  // update
  while (true) {
	  double horizontal_pos = ((strait::odom_pos.x / 24.0) * 39.375 + horizontal_offset);
    double vertical_pos = ((strait::odom_pos.y / -24.0) * 39.375);
    // lv_obj_align(img2, LV_ALIGN_CENTER, horizontal_pos, vertical_pos);
    // lv_img_set_angle(img2, (strait::odom_pos.theta * 10));
    // create_marker(rd_view_obj(odomview), horizontal_pos, vertical_pos);
    // lv_obj_move_foreground(img2);
    
    char buf[32];
    snprintf(buf, 32, "#ffffff X: %f", strait::odom_pos.x);
    lv_label_set_text(label1, buf);

    snprintf(buf, 32, "#ffffff Y: %f", strait::odom_pos.y);
    lv_label_set_text(label2, buf);

    snprintf(buf, 32, LV_SYMBOL_GPS "#ffffff : %f°", strait::odom_pos.theta);
    lv_label_set_text(label3, buf);

	  pros::delay(10);
  }
}