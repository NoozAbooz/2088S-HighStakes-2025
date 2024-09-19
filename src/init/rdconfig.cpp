#include "main.h"

ASSET_LIB(glaze_gif)
ASSET_LIB(sus_gif)

rd::Console console;
rd_view_t *homeview = rd_view_create("Home");
rd_view_t *gifview = rd_view_create("Glaze");
rd_view_t *allianceview = rd_view_create("Alliance Colour");

// alliance select
static lv_obj_t *red_btn, *blue_btn, *next_btn;
static char alliance[10] = "";

#define BORDER_WIDTH 8
#define HIGHLIGHT_COLOR lv_color_hex(0xFFFF00)

static void highlight_button(lv_obj_t *btn) {
    lv_obj_set_style_border_width(red_btn, (btn == red_btn) ? BORDER_WIDTH : 0, 0);
    lv_obj_set_style_border_width(blue_btn, (btn == blue_btn) ? BORDER_WIDTH : 0, 0);
    lv_obj_set_style_border_color(btn, HIGHLIGHT_COLOR, 0);
}

static void btn_event_cb(lv_event_t *e) {
    if (lv_event_get_code(e) == LV_EVENT_CLICKED) {
        lv_obj_t *btn = lv_event_get_target(e);
        strcpy(alliance, (btn == red_btn) ? "red" : "blue");
        highlight_button(btn);
        
        if (!next_btn) {
            next_btn = lv_btn_create(lv_obj_get_parent(btn));
            lv_obj_set_size(next_btn, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_align(next_btn, LV_ALIGN_BOTTOM_RIGHT, -10, -10);
            lv_obj_add_event_cb(next_btn, [](lv_event_t *e) { gui_selector.focus(); }, LV_EVENT_CLICKED, NULL);
            lv_label_set_text(lv_label_create(next_btn), "Next ->");
        }
        lv_obj_clear_flag(next_btn, LV_OBJ_FLAG_HIDDEN);
        console.printf("Alliance set to: %s\n", alliance);
    }
}

void render_alliance_view() {
    lv_obj_t *parent = rd_view_obj(allianceview);
    
    red_btn = lv_btn_create(parent);
    blue_btn = lv_btn_create(parent);
    
    for (int i = 0; i < 2; i++) {
        lv_obj_t *btn = (i == 0) ? red_btn : blue_btn;
        lv_obj_set_size(btn, lv_pct(45), lv_pct(80));
        lv_obj_align(btn, i == 0 ? LV_ALIGN_LEFT_MID : LV_ALIGN_RIGHT_MID, i == 0 ? 10 : -10, 0);
        lv_obj_set_style_bg_color(btn, lv_color_hex(i == 0 ? 0xFF0000 : 0x0000FF), 0);
        lv_obj_add_event_cb(btn, btn_event_cb, LV_EVENT_ALL, NULL);
        lv_label_set_text(lv_label_create(btn), i == 0 ? "RED" : "BLUE");
    }
    
    next_btn = NULL;
}

void render_home_view() {
    lv_obj_t *parent = rd_view_obj(homeview);

    // Create a container for the left side content
    lv_obj_t *left_container = lv_obj_create(parent);
    lv_obj_set_size(left_container, 240, 240);  // Half the screen width
    lv_obj_align(left_container, LV_ALIGN_LEFT_MID, 0, 0);

    // Add your centered object here (e.g., an image or another UI element)
    lv_obj_t *centered_obj = lv_obj_create(left_container);
    lv_obj_set_size(centered_obj, 200, 240);  // Example size
    lv_obj_center(centered_obj);
    Gif* gif = new Gif(sus_gif, centered_obj);

    // Create right side content
    lv_obj_t *right_container = lv_obj_create(parent);
    lv_obj_set_size(right_container, 240, 240);  // Half the screen width
    lv_obj_align(right_container, LV_ALIGN_RIGHT_MID, 0, 0);

    // Add "Kawaii Kittens" text
    lv_obj_t *title = lv_label_create(right_container);
    lv_label_set_text(title, "210K - Kawaii Kittens");
    lv_obj_set_style_text_color(title, lv_color_hex(0xfa4482), 0); 
    lv_obj_align(title, LV_ALIGN_TOP_MID, 0, 20);

    // Add "Setup" button
    lv_obj_t *setup_btn = lv_btn_create(right_container);
    lv_obj_t *btn_label = lv_label_create(setup_btn);
    lv_label_set_text(btn_label, "Setup Auton");
    lv_obj_center(btn_label);
    lv_obj_align(setup_btn, LV_ALIGN_BOTTOM_MID, 0, -20);
    lv_obj_add_event_cb(setup_btn, [](lv_event_t *e) {
        if (lv_event_get_code(e) == LV_EVENT_CLICKED) {
            rd_view_focus(allianceview);
        }
    }, LV_EVENT_CLICKED, NULL);
}

void rdconfig_init() {
    render_home_view();
	render_alliance_view();
	rd_view_focus(homeview);

    //Gif* gif = new Gif(glaze_gif, rd_view_obj(gifview));
}