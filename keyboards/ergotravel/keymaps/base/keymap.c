#include QMK_KEYBOARD_H
#include "keymap_swedish.h"


enum layer_names {
    _COLEMAK,
    _FNNUM,
    _SYMBOLS,
    _NAV,
};

enum custom_keycodes {
  COLEMAK = SAFE_RANGE,
  FNNUM,
  SYMBOLS,
  NAV,
};

#define ESC_C LCTL_T(KC_ESC)
#define SPC_NAV LT(NAV,KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAK] = LAYOUT(
  //,--------+--------+--------+--------+--------+--------+--------.        ,--------+--------+--------+--------+--------+--------+--------.
      KC_TAB ,  KC_Q  ,  KC_W  ,  KC_F  ,  KC_P  ,  KC_B  , KC_MPLY,          KC_VOLU,  KC_J  ,  KC_L  ,  KC_U  ,  KC_Y  , SE_ODIA, SE_ARNG,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
      ESC_C  ,  KC_A  ,  KC_R  ,  KC_S  ,  KC_T  ,  KC_G  , KC_MUTE,          KC_VOLD,  KC_M  ,  KC_N  ,  KC_E  ,  KC_I  ,  KC_O  , SE_ADIA,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
      KC_LALT,  KC_Z  ,  KC_X  ,  KC_C  ,  KC_D  ,  KC_V  , KC_DEL ,          KC_LGUI,  KC_K  ,  KC_H  , KC_COMM,  KC_DOT,  KC_UP , SE_MINS,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
      KC_LCTL, KC_LGUI, KC_LALT, SYMBOLS,      KC_LSFT,     KC_BSPC,          KC_ENT ,      SPC_NAV,      FNNUM , KC_LEFT, KC_DOWN, KC_RGHT
  //`--------+--------+--------+--------+--------+--------+--------/        \--------+--------+--------+--------+--------+--------+--------'
  ),

  [_FNNUM] = LAYOUT(
  //,--------+--------+--------+--------+--------+--------+--------.        ,--------+--------+--------+--------+--------+--------+--------.
      _______,  KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 , KC_PSCR, KC_MSTP,          KC_MNXT, XXXXXXX,  KC_P7 ,  KC_P8 ,  KC_P9 , XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
      KC_RCTL,  KC_F5 ,  KC_F6 ,  KC_F7 ,  KC_F8 , KC_PAUS, _______,          KC_MPRV, XXXXXXX,  KC_P4 ,  KC_P5 ,  KC_P6 , KC_P0  , XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
      KC_RALT,  KC_F9 ,  KC_F10,  KC_F11,  KC_F12, KC_INS , _______,          KC_APP , XXXXXXX,  KC_P1 ,  KC_P2 ,  KC_P3 , KC_PGUP, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
      KC_RCTL, KC_RGUI, KC_RALT, _______,      KC_CAPS,     KC_DEL ,          _______,      KC_NUM ,     XXXXXXX, KC_HOME, KC_PGDN, KC_END
  //`--------+--------+--------+--------+--------+--------+--------/        \--------+--------+--------+--------+--------+--------+--------'
  ),

  [_SYMBOLS] = LAYOUT(
  //,--------+--------+--------+--------+--------+--------+--------.        ,--------+--------+--------+--------+--------+--------+--------.
      _______, SE_BSLS, SE_SLSH, SE_QUOT, SE_DQUO, SE_TILD, _______,          KC_MFFD, SE_DIAE, KC_PERC, KC_HASH, SE_CIRC, SE_PLUS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
      _______, SE_LBRC, SE_RBRC, SE_LPRN, SE_RPRN, SE_GRV , _______,          KC_MRWD, SE_PIPE, KC_EXLM, SE_AMPR, SE_ASTR, SE_EQL , SE_DLR ,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
      _______, SE_LABK, SE_RABK, SE_LCBR, SE_RCBR, SE_ACUT, _______,          _______, SE_AT  , SE_QUES, SE_SCLN, SE_COLN, _______, SE_UNDS,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      _______,     KC_DEL ,          _______,      _______,     _______, _______, _______, _______
  //`--------+--------+--------+--------+--------+--------+--------/        \--------+--------+--------+--------+--------+--------+--------'
  ),

  [_NAV] = LAYOUT(
  //,--------+--------+--------+--------+--------+--------+--------.        ,--------+--------+--------+--------+--------+--------+--------.
      _______, KC_WH_U, KC_WH_L, KC_MS_U, KC_WH_R, XXXXXXX, _______,          _______, KC_VOLU, KC_HOME, KC_UP  , KC_END , KC_PGUP, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
      _______, KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, _______,          _______, KC_VOLD, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, KC_BTN1, KC_BTN3, KC_BTN2, XXXXXXX, _______,          _______, KC_MUTE, KC_MPRV, KC_MPLY, KC_MNXT, _______, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      _______,     _______,          _______,      _______,     XXXXXXX, _______, _______, _______
  //`--------+--------+--------+--------+--------+--------+--------/        \--------+--------+--------+--------+--------+--------+--------'
  )

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case COLEMAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case FNNUM:
      if (record->event.pressed) {
        layer_on(_FNNUM);
        update_tri_layer(_FNNUM, _SYMBOLS, _NAV);
      } else {
        layer_off(_FNNUM);
        update_tri_layer(_FNNUM, _SYMBOLS, _NAV);
      }
      return false;
      break;
    case SYMBOLS:
      if (record->event.pressed) {
        layer_on(_SYMBOLS);
        update_tri_layer(_FNNUM, _SYMBOLS, _NAV);
      } else {
        layer_off(_SYMBOLS);
        update_tri_layer(_FNNUM, _SYMBOLS, _NAV);
      }
      return false;
      break;
    case NAV:
      if (record->event.pressed) {
        layer_on(_NAV);
      } else {
        layer_off(_NAV);
      }
      return false;
      break;
  }
  return true;
}
