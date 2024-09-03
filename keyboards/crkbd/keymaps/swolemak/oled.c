#pragma once

/* #include "graphics/logo.c" */
#include "graphics/ow.c"

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

void write_current_layer(void) {
    // Switch on current active layer
    switch (get_highest_layer(layer_state)) {
        case _COLEMAK_DH :
            oled_write("C-DH ", false);
            break;
        case _GRAPHITE :
            oled_write("Graph", false);
            break;
        case _SYMBOLS :
            oled_write("Sym  ", false);
            break;
        case _FNNUM :
            oled_write("Func ", false);
            break;
        case _NAV :
            oled_write("Nav  ", false);
            break;
        case _RGB :
            oled_write("Opts ", false);
            break;
    }
}

void write_led_status(void) {
    // LED status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.caps_lock ? PSTR("CAPS") : PSTR("    "), false);
    oled_write("\n", false);
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write("\n", false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCRL") : PSTR("    "), false);
}


bool oled_task_user(void) {
  if (!is_keyboard_master()) {
    oled_set_cursor(0,0);
    oled_write_raw_P(solar, sizeof(solar));
    /* render_animation(); */
  } else {
    /* oled_render_logo(); */
    oled_set_cursor(0,1);
    write_current_layer();
    oled_set_cursor(0,3);
    write_led_status();
  }
  return false;
}

#ifdef CAPS_WORD_ENABLE
void caps_word_set_user(bool active) {
    if (active) {
        // Do something when Caps Word activates.
        oled_set_cursor(0,8);
        oled_write("WORD",false);
    } else {
        // Do something when Caps Word deactivates.
        oled_set_cursor(0,8);
        oled_write("word",false);
    }
}
#endif
