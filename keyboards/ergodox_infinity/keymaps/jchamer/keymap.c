#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "visualizer.h"

enum custom_layers {
  _COLEMAK,
  _FUNC,
  _NUM,
  _QWERTY
};

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic Colemak layer
 *
 * ,---------------------------------------------.           ,---------------------------------------------.
 * |   =+   |  1! |  2@ |  3# |  4$ |  5% | PgUp |           | PgDn |  6^ |  7& |  8* |  9( |  0) |    -_  |
 * |--------+-----+-----+-----+-----+------------|           |------+-----+-----+-----+-----+-----+--------|
 * |  Tab   |  Q  |  W  |  F  |  P  |  G  |  [{  |           |  ]}  |  J  |  L  |  U  |  Y  |  ;  |   \|   |
 * |--------+-----+-----+-----+-----+-----|      |           |      |-----+-----+-----+-----+-----+--------|
 * | CAPSLK |  A  |  R  |  S  |  T  |  D  |------|           |------|  H  |  N  |  E  |  I  |  O  |   '"   |
 * |--------+-----+-----+-----+-----+-----| Home |           |  End |-----+-----+-----+-----+-----+--------|
 * | LShift |  Z  |  X  |  C  |  V  |  B  | LT->FUNC |   | LT->FUNC |  K  |  M  |  ,< |  .> |  /? | RShift |
 * `--------+-----+-----+-----+-----+------------'           `------------+-----+-----+-----+-----+--------'
 *   |  `~  |  \| |LCTRL| LGUI| LALT|                                     |Left |Down | Up  |Right| RALT |
 *   `------------------------------'                                     `------------------------------'
 *                                   ,------------.          ,------------.
 *                                   |HOME | END  |          | PGUP |RCTRL|
 *                              ,----|-----|------|          |------+-----+-----.
 *                              |    |     | LGUI |          | PGDN |     |     |
 *                              | [] | ESC |------|          |------|ENTR |BKSP |
 *                              |    |     |L-NUM |          |  DEL |     |     |
 *                              `-----------------'          `------------------'
 */
[_COLEMAK] = LAYOUT_ergodox(
  // left hand
	KC_EQL,   KC_1,    KC_2,    KC_3,    KC_4,  KC_5, KC_PGUP,
	KC_TAB,   KC_Q,    KC_W,    KC_F,    KC_P,  KC_G, KC_LBRACKET,
   KC_CLCK,   KC_A,    KC_R,    KC_S,    KC_T,  KC_D,
   KC_LSFT,   KC_Z,    KC_X,    KC_C,    KC_V,  KC_B, LT(_FUNC, KC_HOME),
	KC_GRV,KC_BSLS, KC_LCTL, KC_LGUI, KC_LALT,

                                              KC_HOME,  KC_END,
                                                       KC_LGUI,
                                    KC_SPACE,  KC_ESC,TG(_NUM),

  // right hand
      KC_PGDN,			KC_6,    KC_7,  KC_8,    KC_9,    KC_0,        KC_MINS,
  KC_RBRACKET,			KC_J,	 KC_L,  KC_U,    KC_Y,    KC_SCOLON,   KC_BSLS,
						KC_H,    KC_N,  KC_E,    KC_I,    KC_O,        KC_QUOTE,
  LT(_FUNC, KC_END),	KC_K,    KC_M,  KC_COMM, KC_DOT,  KC_SLSH,     KC_RSFT,
                     KC_LEFT,  KC_DOWN, KC_UP,   KC_RIGHT,    KC_RALT,

  KC_PGUP, KC_RCTL,
  KC_PGDN,
  KC_DEL,  KC_ENT,  KC_BSPC
),

/* Keymap 0: Basic QWERTY layer
 *
 * ,---------------------------------------------.           ,---------------------------------------------.
 * |   =+   |  1! |  2@ |  3# |  4$ |  5% | PgUp |           | PgDn |  6^ |  7& |  8* |  9( |  0) |    -_  |
 * |--------+-----+-----+-----+-----+------------|           |------+-----+-----+-----+-----+-----+--------|
 * |  Tab   |  Q  |  W  |  E  |  R  |  T  |  [{  |           |  ]}  |  Y  |  U  |  I  |  O  |  P  |    \|  |
 * |--------+-----+-----+-----+-----+-----|      |           |      |-----+-----+-----+-----+-----+--------|
 * | CAPSLK |  A  |  S  |  D  |  F  |  G  |------|           |------|  H  |  J  |  K  |  L  |  ;  |    '"  |
 * |--------+-----+-----+-----+-----+-----| Home |           | End  |-----+-----+-----+-----+-----+--------|
 * | LShift |  Z  |  X  |  C  |  V  |  B  | LT->FUNC |   | LT->FUNC |  N  |  M  |  ,< |  .> |  /? | RShift |
 * `--------+-----+-----+-----+-----+------------'           `------------+-----+-----+-----+-----+--------'
 *   |  `~  |  \| |LCTRL| LGUI| LALT|                                     |Left |Down | Up  |Right| RALT |
 *   `------------------------------'                                     `------------------------------'
 *                                   ,------------.          ,------------.
 *                                   |HOME | END  |          | PGUP |RCTRL|
 *                              ,----|-----|------|          |------+-----+-----.
 *                              |    |     | LGUI |          | PGDN |     |     |
 *                              | [] | ESC |------|          |------|ENTR |BKSP |
 *                              |    |     |L-NUM |          |  DEL |     |     |
 *                              `-----------------'          `------------------'
 * /
[_QWERTY] = LAYOUT_ergodox(
  // left hand
	KC_EQL,   KC_1,    KC_2,    KC_3,    KC_4,  KC_5, KC_PGUP,
	KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,  KC_T, KC_LBRACKET,
   KC_CLCK,   KC_A,    KC_S,    KC_D,    KC_F,  KC_G,
   KC_LSFT,   KC_Z,    KC_X,    KC_C,    KC_V,  KC_B, LT(_FUNC, KC_HOME),
	KC_GRV,KC_BSLS, KC_LCTL, KC_LGUI, KC_LALT,

                                              KC_HOME,  KC_END,
                                                       KC_LGUI,
                                    KC_SPACE,  KC_ESC,TG(_NUM),

  // right hand
      KC_PGDN,			KC_6,    KC_7,     KC_8,   KC_9,      KC_0,    KC_MINS,
  KC_RBRACKET,			KC_Y,	 KC_U,     KC_I,   KC_O,      KC_P,    KC_BSLS,
						KC_H,    KC_J,     KC_K,   KC_L, KC_SCOLON,   KC_QUOTE,
	 LT(_FUNC, KC_END),	KC_N,    KC_M,  KC_COMM, KC_DOT,   KC_SLSH,    KC_RSFT,
                     KC_LEFT,  KC_DOWN, KC_UP,   KC_RIGHT,    KC_RALT,

  KC_PGUP, KC_RCTL,
  KC_PGDN,
  KC_DEL,  KC_ENT,  KC_BSPC
),
*/

/* Keymap 1: Functions
 *
 * ,---------------------------------------------.           ,---------------------------------------------.
 * |        |  F1 |  F2 |  F3 |  F4 |  F5 | F11  |           |  F12 |  F6 |  F7 |  F8 |  F9 | F10 |        |
 * |--------+-----+-----+-----+-----+------------|           |------+-----+-----+-----+-----+-----+--------|
 * |        |     |     |     |     | BL+ |      |           |      |     | VOL+|     |     |     |        |
 * |--------+-----+-----+-----+-----+-----|      |           |      |-----+-----+-----+-----+-----+--------|
 * |        |     |EJECT|PRTSC| CALC|BLTog|------|           |------| MUTE|PL/PS| PREV| NEXT|     |        |
 * |--------+-----+-----+-----+-----+-----|      |           |      |-----+-----+-----+-----+-----+--------|
 * |        |     |     |     |     | BL- |      |           |      |     | VOL-|     |     |     |        |
 * `--------+-----+-----+-----+-----+------------'           `------------+-----+-----+-----+-----+--------'
 *   |      |     |     |     |     |                                     |     |     |     |     |      |
 *   `------------------------------'                                     `------------------------------'
 *                                   ,------------.          ,------------.
 *                                   |     |      |          |      |     |
 *                              ,----|-----|------|          |------+-----+-----.
 *                              |    |     |      |          |      |     |     |
 *                              |    |     |------|          |------|     |     |
 *                              |    |     |      |          |      |     |     |
 *                              `-----------------'          `------------------'
 */
[_FUNC] = LAYOUT_ergodox(
	// left hand
   _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,  KC_F11,
   _______, _______, _______, _______, _______,  BL_INC, _______,
   _______, _______, KC_EJCT, KC_PSCR, KC_CALC, BL_TOGG,
   _______, _______, _______, _______, _______,  BL_DEC, _______,
   _______, _______, _______, _______, _______,
												  _______, _______,
														   _______,
										 _______, _______, _______,

	// right hand
	KC_F12,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, _______,
   _______, _______, KC_VOLU, _______, _______, _______, _______,
			KC_MUTE, KC_MPLY, KC_MPRV, KC_MNXT, _______, _______,
   _______, _______, KC_VOLD, _______, _______, _______, _______,
					 _______, _______, _______, _______, _______,
   _______, _______,
   _______,
   _______, _______, _______
),

/* Keymap 2: NumPad
 *
 * ,---------------------------------------------.           ,---------------------------------------------.
 * | FLASH  |     |     |     |     |     |DEBUG |           | NUMLK|     |     |  /  |  *  |  -  |        |
 * |--------+-----+-----+-----+-----+------------|           |------+-----+-----+-----+-----+-----+--------|
 * |        | Home|  Up | End | PgUp|     |      |           |      |     |  7  |  8  |  9  |  +  |        |
 * |--------+-----+-----+-----+-----+-----|      |           |      |-----+-----+-----+-----+-----+--------|
 * |        | Left| Down|Right| PgDn|     |------|           |------|     |  4  |  5  |  6  |  +  |        |
 * |--------+-----+-----+-----+-----+-----|      |           |      |-----+-----+-----+-----+-----+--------|
 * |VERSION |  /  |  *  |  -  |  +  |ENTER|      |           |      |     |  1  |  2  |  3  |ENTER|        |
 * `--------+-----+-----+-----+-----+------------'           `------------+-----+-----+-----+-----+--------'
 *   |      |     |     |     |     |                                     |  0  |  0  |  .  |  ,  |   =  |
 *   `------------------------------'                                     `------------------------------'
 *                                   ,------------.          ,------------.
 *                                   |     |      |          |      |     |
 *                              ,----|-----|------|          |------+-----+-----.
 *                              |    |     |      |          |      |     |     |
 *                              |    |     |------|          |------|     |     |
 *                              |    |     |      |          |      |     |     |
 *                              `-----------------'          `------------------'
 */
[_NUM] = LAYOUT_ergodox(
  // left hand
   RESET, _______, _______, _______, _______, _______,   DEBUG,
 _______, KC_HOME,   KC_UP,  KC_END, KC_PGUP, _______, _______,
 _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______,
	VRSN, KC_PSLS, KC_PAST, KC_PMNS, KC_PPLS, KC_PENT, _______,
 _______, _______, _______, _______, _______,

                                               _______, _______,
                                                        _______,
                                      _______, _______, _______,

  // right hand
  KC_NLCK, KC_NO, KC_NO, KC_PSLS, KC_PAST, KC_PMNS, _______,
  _______, KC_NO, KC_P7, KC_P8,   KC_P9,   KC_PPLS, _______,
           KC_NO, KC_P4, KC_P5,   KC_P6,   KC_PPLS, _______,
  _______, KC_NO, KC_P1, KC_P2,   KC_P3,   KC_PENT, _______,
			      KC_P0, KC_P0,   KC_PDOT, KC_PCMM, KC_PEQL,

  _______, _______,
  _______,
  _______, _______,  _______
)

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      break;
    case 1:
      if (record->event.pressed) { // For resetting EEPROM
        eeconfig_init();
      }
      break;
  }
  return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
	case PLACEHOLDER:
		return false;
	case EPRM:
		if (record->event.pressed) {
			eeconfig_init();
		}
		return false;
	case VRSN:
		if (record->event.pressed) {
			SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
		}
		return false;
  }
  return true;
}

/**
 * Runs just one time when the keyboard initializes.
 */
void matrix_init_user(void) {

};

/**
 * Runs constantly in the background, in a loop.
 */
void matrix_scan_user(void) {
  uint8_t layer = biton32(layer_state);

  ergodox_board_led_off();
  ergodox_led_func_off();
  ergodox_led_num_off();
  ergodox_led_adjust_off();
  ergodox_led_caps_off();

  switch (layer) {
    case _FUNC:
      ergodox_led_func_on();
      break;
    case _NUM:
      ergodox_led_num_on();
      break;
  }
};
