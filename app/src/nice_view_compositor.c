#include <lvgl.h>
#include <zmk/display.h>

static int moon_pos = 0;
static int moon_dir = 1;

void nice_view_compositor(lv_obj_t *parent) {
    // Tamaño de la pantalla Nice!View (ejemplo: 250x122 píxeles)
    const int width = 250;
    const int height = 122;

    // Actualiza la posición de la luna
    moon_pos += moon_dir * 10;
    if (moon_pos > width - 20) {
        moon_dir = -1;
        moon_pos = width - 20;
    } else if (moon_pos < 0) {
        moon_dir = 1;
        moon_pos = 0;
    }

    // Dibuja la luna (círculo blanco)
    lv_obj_t *moon = lv_obj_create(parent, NULL);
    lv_obj_set_size(moon, 20, 20);
    lv_obj_set_style_local_bg_color(moon, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_WHITE);
    lv_obj_set_style_local_radius(moon, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_RADIUS_CIRCLE);
    lv_obj_set_style_local_border_width(moon, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, 0);
    lv_obj_align(moon, NULL, LV_ALIGN_IN_TOP_LEFT, moon_pos, height / 2 - 10);
}