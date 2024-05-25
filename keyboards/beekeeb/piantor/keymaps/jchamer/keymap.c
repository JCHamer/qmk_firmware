// Copyright 2022 beekeeb
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_R LCTL_T(KC_R)
#define HOME_S LSFT_T(KC_S)
#define HOME_T LALT_T(KC_T)

// Right-hand home row mods
#define HOME_N LALT_T(KC_N)
#define HOME_E RSFT_T(KC_E)
#define HOME_I RCTL_T(KC_I)
#define HOME_O RGUI_T(KC_O)

enum custom_layers {
  _COLEMAKDH,
  _MVMT,
  _MODS,
  _NUMROW,
  _NUMPAD//,
  //_QWERTY
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │Tab│ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │Bsp│
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Ctl│ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │ ' │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Sft│ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │Sft│
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │GUI├───┐           ┌───┤Alt│
      *               └───┤Bsp├───┐   ┌───┤Ent├───┘
      *                   └───┤   │   │   ├───┘
      *                       └───┘   └───┘
      */
    /*
    [0] = LAYOUT_split_3x6_3(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                            KC_LGUI, KC_BSPC, KC_SPC,           KC_SPC,  KC_ENT,  KC_RALT
    ),
    */

[_COLEMAKDH] = LAYOUT_split_3x6_3(
         KC_TAB,   KC_Q,   KC_W,   KC_F,     KC_P,              KC_B,                                  KC_J,    KC_L,    KC_U,   KC_Y, KC_SCLN, LT(_MODS, KC_BSLS),
         KC_GRV, HOME_A, HOME_R, HOME_S,   HOME_T,              KC_G,                                  KC_M,  HOME_N,  HOME_E, HOME_I,  HOME_O,           KC_QUOTE,
LSFT_T(KC_LBRC),   KC_Z,   KC_X,   KC_C,     KC_V,   LT(_MODS, KC_V),                                  KC_K,    KC_H, KC_COMM, KC_DOT, KC_SLSH, LT(_MVMT, KC_RBRC),
                                         KC_SPACE, LT(_MVMT, KC_ESC), TT(_NUMROW),         KC_DEL, LT(_MVMT, KC_ENT), KC_BSPC
),

[_MVMT] = LAYOUT_split_3x6_3(
  _______, _______, _______, _______, _______, _______,                        KC_DOWN,KC_RIGHT, KC_PGUP, _______, _______, _______,
  _______, KC_LGUI, KC_LCTL, KC_LSFT, KC_LALT, _______,                        _______, KC_HOME,  KC_END,  KC_TAB, _______, _______,
  _______, _______, _______, _______, _______, _______,                          KC_UP, KC_LEFT, KC_PGDN, _______, _______, _______,
                                      _______, _______, _______,      _______, _______, _______
),

[_MODS] = LAYOUT_split_3x6_3(
  _______, _______, _______, _______,    _______, _______,                         _______, KC_VOLU, _______, _______, _______, _______,
  _______, KC_CAPS, KC_EJCT, KC_PSCR,    KC_CALC, _______,                         KC_MUTE, KC_MPLY, KC_MPRV, KC_MNXT, _______, _______,
  _______, _______, _______, _______,TG(_NUMPAD), _______,                         _______, KC_VOLD, KC_RALT, KC_RGUI, KC_RCTL, _______,
                                         _______, _______, _______,       _______, _______, _______
),

[_NUMROW] = LAYOUT_split_3x6_3(
   KC_EQL,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                             KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,
   KC_F11, _______, _______, _______, _______, KC_LPRN,                          KC_RPRN, _______, _______, _______, _______,  KC_F12,
  _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                            KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, _______,
                                      _______, _______, _______,        _______, _______,  _______
),

[_NUMPAD] = LAYOUT_split_3x6_3(
  _______, _______, _______, _______, _______, _______,                         KC_PCMM,   KC_P7,   KC_P8,   KC_P9, KC_PENT,  KC_NUM,
  _______, _______, _______, _______, _______, _______,                         KC_PDOT,   KC_P4,   KC_P5,   KC_P6, KC_PPLS, KC_PAST,
  _______, _______, _______, _______, _______, _______,                           KC_P0,   KC_P1,   KC_P2,   KC_P3, KC_PMNS, KC_PSLS,
                                      _______, _______, _______,       _______, _______,  _______
)

};

/**
 * Runs just one time when the keyboard initializes.
 */
void matrix_init_user(void) {

};

/**
 * Runs constantly in the background, in a loop.
 */
void matrix_scan_user(void) {
  /*
  uint8_t layer = get_highest_layer(layer_state);

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  switch (layer) {
    case _MODS:
      ergodox_right_led_1_on();
      ergodox_infinity_lcd_color(0, 30, 200);
      break;
    case _NUMPAD:
      ergodox_right_led_2_on();
      ergodox_infinity_lcd_color(220, 120, 0);
      break;
  }
  */
};
