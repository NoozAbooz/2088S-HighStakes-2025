#include "main.h"

ASSET_LIB(glaze_gif)

rd::Console console;
rd_view_t *gifview = rd_view_create("GIF");
rd_view_t *allianceview = rd_view_create("Alliance Colour");

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
        printf("Alliance set to: %s\n", alliance);
    }
}

void create_alliance_buttons() {
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

void rdconfig_init() {
	static Gif gif(glaze_gif, rd_view_obj(gifview));
	create_alliance_buttons();
}