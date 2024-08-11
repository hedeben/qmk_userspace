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
    GRA,
    FNUM,
    SYM,
    NAV,
    RGBO
};

#ifdef OLED_ENABLE
  #include "oled.c"
#endif

#ifdef TAP_DANCE_ENABLE
  #include "tapdance.c"
  #define MOD_ALT TD(TD_MA)
#else
  #define MOD_ALT KC_ALT
#endif

/*
SE_SECT // §
SE_CURR // ¤
SE_PND  // £
SE_DLR  // $
SE_EURO // €
SE_MICR // µ
*/

#define SE_DEG RALT(LSFT(KC_0)) // °
/* #define SE_NOT RALT(SE_ACUT)    // ¬ */

#define ESC_CTL MT(MOD_LCTL, KC_ESC)    // Esc on tap, Ctrl on hold
/* #define DEL_SYM LT(SYM,KC_DEL) */
#define SPC_NAV LT(NAV, KC_SPC)
/* #define TAB_NUM LT(FNNUM, KC_TAB) */
#define OS_RALT  OSM(MOD_RALT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK_DH] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y, SE_ODIA, SE_ARNG,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      ESC_CTL,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                         KC_M,    KC_N,    KC_E,    KC_I,    KC_O, SE_ADIA,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      MOD_ALT,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, SE_MINS, KC_LGUI,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          MO(SYM), KC_LSFT, KC_BSPC,     KC_ENT, SPC_NAV, MO(FNUM)
                                      //`--------------------------'  `--------------------------'
  ),

    [_GRAPHITE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_B,    KC_L,    KC_D,    KC_W,    KC_Z,                         KC_J,    KC_F,    KC_O,    KC_U, SE_ODIA, SE_ARNG,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      ESC_CTL,    KC_N,    KC_R,    KC_T,    KC_S,    KC_G,                         KC_Y,    KC_H,    KC_A,    KC_E,    KC_I, SE_ADIA,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      MOD_ALT,    KC_Q,    KC_X,    KC_M,    KC_C,    KC_V,                         KC_K,    KC_P, KC_COMM,  KC_DOT, SE_MINS, KC_LGUI,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          MO(SYM), KC_LSFT, KC_BSPC,     KC_ENT, SPC_NAV, MO(FNUM)
                                      //`--------------------------'  `--------------------------'
  ),

    [_FNNUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,   KC_F1,   KC_F2,   KC_F3,   KC_F4, KC_PSCR,                      XXXXXXX,    KC_7,    KC_8,    KC_9, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_RCTL,   KC_F5,   KC_F6,   KC_F7,   KC_F8, KC_PAUS,                      XXXXXXX,    KC_4,    KC_5,    KC_6,    KC_0, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      OS_RALT,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_INS,                      XXXXXXX,    KC_1,    KC_2,    KC_3,  KC_APP, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         MO(RGBO), KC_CAPS,  KC_DEL,    _______, TG(NAV), _______
                                      //`--------------------------'  `--------------------------'
  ),

    [_SYMBOLS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, SE_TILD, SE_BSLS, SE_SLSH, SE_AMPR, SE_PIPE,                      SE_DIAE, KC_PERC, KC_HASH, SE_ASTR, SE_PLUS,  SE_DEG,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, SE_LBRC, SE_RBRC, SE_LPRN, SE_RPRN,  SE_GRV,                      SE_CIRC, KC_EXLM, SE_QUOT, SE_DQUO,  SE_EQL,  SE_DLR,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, SE_LABK, SE_RABK, SE_LCBR, SE_RCBR, SE_ACUT,                        SE_AT, SE_QUES, SE_SCLN, SE_COLN, SE_UNDS, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______,  KC_DEL,    XXXXXXX, XXXXXXX,MO(RGBO)
                                      //`--------------------------'  `--------------------------'
  ),

    [_NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_WH_U, KC_WH_L, KC_MS_U, KC_WH_R, XXXXXXX,                      KC_VOLU, KC_HOME,   KC_UP,  KC_END, KC_PGUP, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX,                      KC_VOLD, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, KC_BTN3, KC_BTN1, KC_BTN2, XXXXXXX,                      KC_MUTE, KC_MPRV, KC_MPLY, KC_MNXT, KC_STOP, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, TG(NAV), _______
                                      //`--------------------------'  `--------------------------'
  ),

    [_RGB] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX,                      XXXXXXX, XXXXXXX, TG(GRA), XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, _______
                                      //`--------------------------'  `--------------------------'
  )

};
