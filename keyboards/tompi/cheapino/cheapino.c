#include "wait.h"
#include "quantum.h"

// This is to keep state between callbacks, when it is 0 the
// initial RGB flash is finished
uint8_t _hue_countdown = 50;

// These are to keep track of user selected color, so we
// can restore it after RGB flash
uint8_t _hue;
uint8_t _saturation;
uint8_t _value;

// Do a little 2.5 seconds display of the different colors
// Use the deferred executor so the LED flash dance does not
// stop us from using the keyboard.
// https://docs.qmk.fm/#/custom_quantum_functions?id=deferred-executor-registration
uint32_t flash_led(uint32_t next_trigger_time, void *cb_arg) {
    rgblight_sethsv(_hue_countdown * 5, 230, 70);
    _hue_countdown--;
    if (_hue_countdown == 0) {
        // Finished, reset to user chosen led color
        rgblight_sethsv(_hue, _saturation, _value);
        return 0;
    } else {
        return 50;
    }
}

void keyboard_post_init_user(void) {
    //debug_enable=true;
    //debug_matrix=true;
    //debug_keyboard=true;
    //debug_mouse=true;

    // Hardcoded default values
    _hue = 0;
    _saturation = 238;
    _value = 80;

    // Flash a little on start
    defer_exec(50, flash_led, NULL);
}

uint8_t get_hue(uint8_t layer, bool *isLayer0) {
	*isLayer0 = false;
    switch (layer) {
        case 4:
            return 85;
        case 3:
            return 120;
        case 2:
            return 180;
        case 1:
            return 220;
        case 0:
        default:
			*isLayer0 = true;
            return 0;
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
	static bool prevLayer0 = false;
	bool isLayer0;

    uint8_t hue = get_hue(get_highest_layer(state), &isLayer0);
    uint8_t sat = rgblight_get_sat();
    uint8_t val = rgblight_get_val();

	if (!prevLayer0 && isLayer0) {
		_saturation = sat;
		_value = val;

		sat = 0;
		val = 0;
	} else if (prevLayer0 && !isLayer0) {
		sat = _saturation;
		val = _value;
	}

	prevLayer0 = isLayer0;

    rgblight_sethsv(hue, sat, val);
    return state;
}

