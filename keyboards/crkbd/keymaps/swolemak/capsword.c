#pragma once

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        case KC_A ... KC_Z:
        case SE_ADIA:
        case SE_ARNG:
        case SE_ODIA:
            add_weak_mods(MOD_BIT(KC_LSFT));
            return true;

        case KC_1 ... KC_0:
        case KC_LSFT:
        case KC_BSPC:
        case KC_DEL:
        case KC_DOT:
        case KC_MINS:
        case SE_MINS:
        case KC_UNDS:
        case SE_UNDS:
            return true;

        default:
            return false;
    }
}
