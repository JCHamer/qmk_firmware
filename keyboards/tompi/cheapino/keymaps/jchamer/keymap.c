#include QMK_KEYBOARD_H

enum custom_layers {
  _COLEMAKDH,
  _NUMSYM,
  _MVMT,
  _OSCTRL,
  _KBCTRL
};

enum custom_keycodes {
	SMTD_KEYCODES_BEGIN = SAFE_RANGE,
	// HRM - Left Hand
	CKC_A, // Reads as C(ustom) + KC_A
	CKC_R,
	CKC_S,
	CKC_T,

	// HRM - Right Hand
	CKC_N,
	CKC_E,
	CKC_I,
	CKC_O,

	// Tap-Hold Backup Layer Control
	CKC_SPC,
	CKC_ENT,

	CKC_SFT, // Left-Hand Shift
	CKC_RR, // Right-Hand R-Ctrl

	SMTD_KEYCODES_END
};
#include "sm_td/sm_td.h"

#define LAYER0 TO(_COLEMAKDH)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_COLEMAKDH] = LAYOUT_split_3x5_3(
  KC_Q,  KC_W,    KC_F,    KC_P,      KC_B,           KC_J,    KC_L,        KC_U,   KC_Y, KC_SCLN,
 CKC_A, CKC_R,   CKC_S,   CKC_T,      KC_G,           KC_M,   CKC_N,       CKC_E,  CKC_I,   CKC_O,
  KC_Z,  KC_X,    KC_C,    KC_D,      KC_V,           KC_K,    KC_H,     KC_COMM, KC_DOT, KC_SLSH,
               CKC_SPC, CKC_SFT, MO(_MVMT),        CKC_ENT, KC_BSPC, MO(_NUMSYM)
),

[_NUMSYM] = LAYOUT_split_3x5_3(
 KC_PSLS, KC_7,    KC_8,    KC_9,    KC_0,        _______, _______, _______, KC_RCTL,      KC_SCLN,
 KC_PPLS, KC_4,    KC_5,    KC_6, KC_MINS,         LAYER0, KC_RALT, KC_RSFT,  CKC_RR,      KC_RGUI,
  KC_DOT, KC_1,    KC_2,    KC_3, KC_PAST,        _______, _______, KC_COMM,    KC_X, OSL(_OSCTRL),
                _______, _______, _______,        _______, _______, _______
),

[_MVMT] = LAYOUT_split_3x5_3(
       KC_GRV,  KC_EQL,  KC_TAB, KC_LBRC,     KC_RBRC,        KC_DOWN, KC_RGHT, KC_PGUP, _______, TO(_NUMSYM),
      KC_LGUI, KC_LCTL, KC_LSFT, KC_LALT,     KC_MINS,         LAYER0, KC_HOME,  KC_END,  KC_DEL,     KC_QUOT,
 OSL(_KBCTRL),  LAYER0, _______,  KC_ESC, TO(_NUMSYM),          KC_UP, KC_LEFT, KC_PGDN, _______,     KC_BSLS,
                        _______, _______,     _______,        _______, _______, _______
),

[_OSCTRL] = LAYOUT_split_3x5_3(
 KC_F10, KC_F7,   KC_F8,   KC_F9, _______,        KC_MPRV, KC_MNXT, KC_VOLU, KC_EJCT,       KC_NUM,
 KC_F11, KC_F4,   KC_F5,   KC_F6, _______,         LAYER0, KC_CALC, KC_MUTE, CW_TOGG,      KC_CAPS,
 KC_F12, KC_F1,   KC_F2,   KC_F3, _______,        _______, KC_PSCR, KC_VOLD, KC_MPLY, OSL(_KBCTRL),
                _______, _______, _______,        _______, _______, _______
),

[_KBCTRL] = LAYOUT_split_3x5_3(
 QK_BOOT, _______, _______, _______, _______,        _______, RGB_HUI, RGB_SAI, RGB_VAI, QK_BOOT,
  QK_RBT, _______, _______, _______, _______,         LAYER0, _______, _______, _______, _______,
 _______, _______, _______, _______, _______,        _______, RGB_HUD, RGB_SAD, RGB_VAD, _______,
                   _______, _______, _______,        _______, _______, _______
)

};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	if (!process_smtd(keycode, record)) {
		return false;
	}
	// your code here
	
	return true;
}

void on_smtd_action(uint16_t keycode, smtd_action action, uint8_t tap_count) {
	switch (keycode) {
		// HRM - Left Hand
		SMTD_MT(CKC_A, KC_A, KC_LEFT_GUI, 1, true)
		SMTD_MT(CKC_R, KC_R, KC_LEFT_CTRL, 1, true)
		SMTD_MT(CKC_S, KC_S, KC_LEFT_SHIFT, 1, true)
		SMTD_MT(CKC_T, KC_T, KC_LEFT_ALT, 1, true)

		// HRM - Right Hand
		SMTD_MT(CKC_N, KC_N, KC_LEFT_ALT, 1, true)
		SMTD_MT(CKC_E, KC_E, KC_LEFT_SHIFT, 1, true)
		SMTD_MT(CKC_I, KC_I, KC_LEFT_CTRL, 1, true)
		SMTD_MT(CKC_O, KC_O, KC_LEFT_GUI, 1, true)

		// Tap-Hold Backup Layer Control
		SMTD_LT(CKC_SPC, KC_SPC, _NUMSYM, 1, false)
		SMTD_LT(CKC_ENT, KC_ENT, _MVMT, 1, false)

		// Right-Hand R-Ctrl
		SMTD_MT(CKC_RR, KC_R, KC_RIGHT_CTRL, 1, true)

		// Left-Hand Shift
		SMTD_MT(CKC_SFT, KC_LSFT, KC_LSFT)
	}
}

