#include QMK_KEYBOARD_H
#include "keymap_swedish.h"

enum layer_names {
    _COLEMAK_DH,
    _GRAPHITE,
    _FNNUM,
    _SYMBOLS,
    _NAV,
    _RGB
};

enum custom_keycodes {
    CMDH = SAFE_RANGE,
    GRAPH,
    FNNUM,
    SYM,
    NAV,
    RGBOPT
};

// SE_SECT // §
// SE_CURR // ¤
// SE_PND  // £
// SE_DLR  // $
// SE_EURO // €
// SE_MICR // µ

#define SE_DEG RALT(LSFT(KC_0)) // °
#define SE_NOT RALT(SE_ACUT)    // ¬

#define ESC_C LCTL_T(KC_ESC)    // Esc on tap, Ctrl on hold
// #define DEL_SYM LT(SYM,KC_DEL)
/* #define BS_SYM LT(SYM, KC_BSPC) */
/* #define ENT_NUM LT(FNNUM, KC_ENT) */
#define SPC_NAV LT(NAV, KC_SPC)
// #define ESC_NUM LT(FNNUM,KC_ESC)
/* #define TAB_NUM LT(FNNUM, KC_TAB) */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK_DH] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y, SE_ODIA, SE_ARNG,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        ESC_C,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                         KC_M,    KC_N,    KC_E,    KC_I,    KC_O, SE_ADIA,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LALT,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, SE_MINS, KC_LGUI,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                              SYM, KC_LSFT, KC_BSPC,     KC_ENT, SPC_NAV, FNNUM
                                      //`--------------------------'  `--------------------------'
  ),

    [_GRAPHITE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_B,    KC_L,    KC_D,    KC_W,    KC_Z,                      SE_ODIA,    KC_F,    KC_O,    KC_U,    KC_J, SE_ARNG,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        ESC_C,    KC_N,    KC_R,    KC_T,    KC_S,    KC_G,                         KC_Y,    KC_H,    KC_A,    KC_E,    KC_I, SE_ADIA,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LALT,    KC_Q,    KC_X,    KC_M,    KC_C,    KC_V,                         KC_K,    KC_P, KC_COMM,  KC_DOT, SE_MINS, KC_LGUI,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                              SYM, KC_LSFT, KC_BSPC,     KC_ENT, SPC_NAV, FNNUM
                                      //`--------------------------'  `--------------------------'
  ),

    [_FNNUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,   KC_F1,   KC_F2,   KC_F3,   KC_F4, KC_PSCR,                      XXXXXXX,   KC_P7,   KC_P8,   KC_P9, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_RCTL,   KC_F5,   KC_F6,   KC_F7,   KC_F8, KC_PAUS,                        GRAPH,   KC_P4,   KC_P5,   KC_P6,   KC_P0, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_RALT,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_INS,                         CMDH,   KC_P1,   KC_P2,   KC_P3,  KC_APP, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           RGBOPT, KC_CAPS,  KC_DEL,    _______,  KC_NUM, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [_SYMBOLS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, SE_BSLS, SE_SLSH, SE_QUOT, SE_DQUO, SE_TILD,                      SE_DIAE, KC_PERC, KC_HASH, SE_CIRC, SE_PLUS, SE_DEG,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, SE_LBRC, SE_RBRC, SE_LPRN, SE_RPRN,  SE_GRV,                      SE_PIPE, KC_EXLM, SE_AMPR, SE_ASTR, SE_EQL, SE_DLR,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, SE_LABK, SE_RABK, SE_LCBR, SE_RCBR, SE_ACUT,                        SE_AT, SE_QUES, SE_SCLN, SE_COLN, SE_UNDS, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______,  KC_DEL,    XXXXXXX, XXXXXXX,  RGBOPT
                                      //`--------------------------'  `--------------------------'
  ),

    [_NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, KC_WH_U, KC_WH_L, KC_MS_U, KC_WH_R, XXXXXXX,                      KC_VOLU, KC_HOME,   KC_UP,  KC_END, KC_PGUP, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX,                      KC_VOLD, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, KC_BTN3, KC_BTN1, KC_BTN2, XXXXXXX,                      KC_MUTE, KC_MPRV, KC_MPLY, KC_MNXT, KC_STOP, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [_RGB] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, _______
                                      //`--------------------------'  `--------------------------'
  )

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CMDH:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK_DH);
            }
            return false;
            break;
        case GRAPH:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_GRAPHITE);
            }
            return false;
            break;
        case SYM:
            (record->event.pressed) ? layer_on(_SYMBOLS) : layer_off(_SYMBOLS);
            return false;
            break;
        case FNNUM:
            (record->event.pressed) ? layer_on(_FNNUM) : layer_off(_FNNUM);
            return false;
            break;
        case NAV:
            (record->event.pressed) ? layer_on(_NAV) : layer_off(_NAV);
            return false;
            break;
        case RGBOPT:
            (record->event.pressed) ? layer_on(_RGB) : layer_off(_RGB);
            return false;
            break;
    }
    return true;
}
