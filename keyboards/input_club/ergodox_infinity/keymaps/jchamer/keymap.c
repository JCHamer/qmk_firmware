#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"
//#include "visualizer.h"
#include "ergodox_infinity.h"

// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_R LCTL_T(KC_R)
#define HOME_S LSFT_T(KC_S)
//#define HOME_S KC_S
#define HOME_T LALT_T(KC_T)

// Right-hand home row mods
#define HOME_N LALT_T(KC_N)
#define HOME_E RSFT_T(KC_E)
//#define HOME_E KC_E
#define HOME_I RCTL_T(KC_I)
#define HOME_O RGUI_T(KC_O)

enum custom_layers {
  _COLEMAKDH,
  _MVMT,
  _MODS,
  _NUMPAD,
  _NUMROW//,
  //_QWERTY
};

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*[_BLANK] = LAYOUT_ergodox(
	// left hand
   _______, _______, _______, _______, _______, _______, _______,
   _______, _______, _______, _______, _______, _______, _______,
   _______, _______, _______, _______, _______, _______,
   _______, _______, _______, _______, _______, _______, _______,
   _______, _______, _______, _______, _______,
												  _______, _______,
														   _______,
										 _______, _______, _______,

	// right hand
   _______, _______, _______, _______, _______, _______, _______,
   _______, _______, _______, _______, _______, _______, _______,
			_______, _______, _______, _______, _______, _______,
   _______, _______, _______, _______, _______, _______, _______,
					 _______, _______, _______, _______, _______,
   _______, _______,
   _______,
   _______, _______, _______
),
*/

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
[_COLEMAKDH] = LAYOUT_ergodox(
  // left hand
          KC_EQL,    KC_1,    KC_2,    KC_3,                KC_4,             KC_5, _______,
          KC_TAB,    KC_Q,    KC_W,    KC_F,                KC_P,             KC_B, _______,
          KC_GRV,  HOME_A,  HOME_R,  HOME_S,              HOME_T,             KC_G,
 LSFT_T(KC_LBRC),    KC_Z,    KC_X,    KC_C,                KC_D,  LT(_MODS, KC_V), _______,
         _______, _______, _______, _______, LT(_NUMROW, KC_ESC),

                                                           _______,              _______,
                                                                                 _______,
                                      LT(_MVMT, KC_SPACE), KC_LSFT,  LT(_NUMROW, KC_ESC),

  // right hand
      _______,  KC_6,    KC_7,     KC_8,    KC_9,    KC_0,            KC_MINS,
      _______,	KC_J,	 KC_L,     KC_U,    KC_Y, KC_SCLN, LT(_MODS, KC_BSLS),
				KC_M,  HOME_N,   HOME_E,  HOME_I,  HOME_O,           KC_QUOTE,
      _______,	KC_K,    KC_H,  KC_COMM,  KC_DOT, KC_SLSH, LT(_MVMT, KC_RBRC),
                                _______,  _______, _______, _______,  _______,

             _______,        _______,
	         _______,
 LT(_NUMROW, KC_DEL), RSFT_T(KC_ENT), KC_BSPC
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
   KC_LSFT,   KC_Z,    KC_X,    KC_C,    KC_V,  KC_B, LT(_MODS, KC_HOME),
	KC_GRV,KC_BSLS, KC_LCTL, KC_LGUI, KC_LALT,

                                              KC_HOME,  KC_END,
                                                       KC_LGUI,
                                    KC_SPACE,  KC_ESC,TG(_NUM),

  // right hand
      KC_PGDN,			KC_6,    KC_7,     KC_8,   KC_9,      KC_0,    KC_MINS,
  KC_RBRACKET,			KC_Y,	 KC_U,     KC_I,   KC_O,      KC_P,    KC_BSLS,
						KC_H,    KC_J,     KC_K,   KC_L, KC_SCOLON,   KC_QUOTE,
	 LT(_MODS, KC_END),	KC_N,    KC_M,  KC_COMM, KC_DOT,   KC_SLSH,    KC_RSFT,
                     KC_LEFT,  KC_DOWN, KC_UP,   KC_RIGHT,    KC_RALT,

  KC_PGUP, KC_RCTL,
  KC_PGDN,
  KC_DEL,  KC_ENT,  KC_BSPC
),
*/

/* Keymap 1: Movement
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
[_MVMT] = LAYOUT_ergodox(
	// left hand
   _______, _______, _______, _______, _______, _______, _______,
   _______, _______, _______, _______, _______, _______, _______,
   _______, KC_LGUI, KC_LCTL, KC_LSFT, KC_LALT, _______,
   _______, _______, _______, _______, _______, _______, _______,
   _______, _______, _______, _______, _______,
												  _______, _______,
														   _______,
										 _______, _______, _______,

	// right hand
   _______, _______, _______, _______, _______, _______, _______,
   _______, KC_DOWN,KC_RIGHT, KC_PGUP, _______, _______, _______,
			_______, KC_HOME,  KC_END,  KC_TAB, _______, _______,
   _______,   KC_UP, KC_LEFT, KC_PGDN, _______, _______, _______,
					 _______, _______, _______, _______, _______,
   _______, _______,
   _______,
   _______, _______, _______
),

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
[_MODS] = LAYOUT_ergodox(
	// left hand
    KC_F11,   KC_F1,   KC_F2,   KC_F3,      KC_F4,   KC_F5, _______,
   _______, _______, _______, BL_DOWN,    BL_TOGG,   BL_UP, _______,
   _______, KC_CAPS, KC_EJCT, KC_PSCR,    KC_CALC, _______,
   _______, _______, _______, _______,TG(_NUMPAD), _______, _______,
   _______, _______, _______, _______,    _______,
												  _______, _______,
														   _______,
										 _______, _______, _______,

	// right hand
   _______,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F12,
   _______, _______, KC_VOLU, _______, _______, _______, _______,
			KC_MUTE, KC_MPLY, KC_MPRV, KC_MNXT, _______, _______,
   _______, _______, KC_VOLD, KC_RALT, KC_RGUI, KC_RCTL, _______,
					 _______, _______, _______, _______, _______,
   _______, _______,
   _______,
   _______, _______, _______
),

/* Keymap 2: NumPad
 *
 * ,---------------------------------------------.           ,---------------------------------------------.
 * | FLASH  |     |     |     |     |     |DEBUG |           | NUMLK|  ✗  |  ✗  |  /  |  *  |  -  |        |
 * |--------+-----+-----+-----+-----+------------|           |------+-----+-----+-----+-----+-----+--------|
 * |        | Home|  Up | End | PgUp|     |      |           |      |  ✗  |  7  |  8  |  9  |  +  |        |
 * |--------+-----+-----+-----+-----+-----|      |           |      |-----+-----+-----+-----+-----+--------|
 * |        | Left| Down|Right| PgDn|     |------|           |------|  ✗  |  4  |  5  |  6  |  +  |        |
 * |--------+-----+-----+-----+-----+-----|      |           |      |-----+-----+-----+-----+-----+--------|
 * |VERSION |  /  |  *  |  -  |  +  |ENTER|      |           |      |  ✗  |  1  |  2  |  3  |ENTER|        |
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
[_NUMPAD] = LAYOUT_ergodox(
  // left hand
 _______, _______, _______, _______, _______, _______, _______,
 _______, _______, _______, _______, _______, _______, _______,
 _______, _______, _______, _______, _______, _______,
 _______, _______, _______, _______, _______, _______, _______,
 _______, _______, _______, _______, _______,

                                               _______, _______,
                                                        _______,
                                      _______, _______, _______,

  // right hand
  _______, _______, _______, _______, _______, _______, _______,
  _______, KC_PCMM,   KC_P7,   KC_P8,   KC_P9, KC_PENT,  KC_NUM,
             KC_P0,   KC_P4,   KC_P5,   KC_P6, KC_PPLS, KC_PAST,
  _______, KC_PDOT,   KC_P1,   KC_P2,   KC_P3, KC_PMNS, KC_PSLS,
                    _______, _______, _______, _______, _______,

  _______, _______,
  _______,
  _______, _______,  _______
),

/* Keymap 2: NumRow
 *
 * ,---------------------------------------------.           ,---------------------------------------------.
 * | FLASH  |     |     |     |     |     |DEBUG |           | NUMLK|  ✗  |  ✗  |  /  |  *  |  -  |        |
 * |--------+-----+-----+-----+-----+------------|           |------+-----+-----+-----+-----+-----+--------|
 * |        | Home|  Up | End | PgUp|     |      |           |      |  ✗  |  7  |  8  |  9  |  +  |        |
 * |--------+-----+-----+-----+-----+-----|      |           |      |-----+-----+-----+-----+-----+--------|
 * |        | Left| Down|Right| PgDn|     |------|           |------|  ✗  |  4  |  5  |  6  |  +  |        |
 * |--------+-----+-----+-----+-----+-----|      |           |      |-----+-----+-----+-----+-----+--------|
 * |VERSION |  /  |  *  |  -  |  +  |ENTER|      |           |      |  ✗  |  1  |  2  |  3  |ENTER|        |
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
[_NUMROW] = LAYOUT_ergodox(
  // left hand
 _______, _______, _______, _______, _______, _______, _______,
  KC_EQL,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5, _______,
  KC_F11, _______, _______, _______, _______, KC_LPRN,
 _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, _______,
 _______, _______, _______, _______, _______,

                                               _______, _______,
                                                        _______,
                                      _______, _______, _______,

  // right hand
  _______, _______, _______, _______, _______, _______, _______,
  _______,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,
           KC_RPRN, _______, _______, _______, _______,  KC_F12,
  _______,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, _______,
                    _______, _______, _______, _______, _______,

  _______, _______,
  _______,
  _______, _______,  _______
)

};

/*
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
*/

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

uint16_t get_tapping_term(uint16_t keycode, keyrecord *record) {
	switch (keycode) {
		case LT(_MVMT, KC_SPACE):
		case LT(_NUMROW, KC_ESC):
		case LT(_NUMROW, KC_DEL):
			return 200;
		default:
			return TAPPING_TERM;
	}
}
