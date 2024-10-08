#include QMK_KEYBOARD_H


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(	KC_ESC , KC_1, KC_2   , KC_3   , KC_4   , KC_5,						  KC_6 , KC_7   , KC_8   , KC_9   , KC_0   , KC_GRV,
					KC_TAB , KC_Q, KC_W   , KC_E   , KC_R   , KC_T, 					  KC_Y , KC_U   , KC_I   , KC_O   , KC_P   , KC_MINS,
					KC_LSFT, KC_A, KC_S   , KC_D   , KC_F   , KC_G,						  KC_H , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
					KC_LCTL, KC_Z, KC_X   , KC_C   , KC_V   , KC_B,  KC_MUTE, LGUI(KC_L), KC_N , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_BSLS,
								   KC_LGUI, KC_LALT, KC_LCTL, MO(1), KC_SPC , KC_ENT    , MO(2), KC_BSPC, KC_RALT, KC_RGUI),

	[1] = LAYOUT(	_______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5, 					KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11,
	                KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5, 						KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_F12,
					_______, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC, 					KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
					_______, KC_EQL , KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, _______, _______, KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, _______,
									  _______, _______, _______, _______, _______, _______, MO(3)  , KC_DEL , _______, _______),

	[2] = LAYOUT(	_______, _______, _______, _______, _______, _______, 					_______, _______, _______, _______, _______, _______,
					_______, KC_INS , KC_PSCR, KC_APP , XXXXXXX, XXXXXXX, 					KC_PGUP, C(KC_LEFT), KC_UP, C(KC_RGHT), C(KC_BSPC), KC_BSPC,
					_______, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, KC_CAPS, 					KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL, KC_BSPC, 
					_______, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), XXXXXXX, _______, _______, XXXXXXX, KC_HOME, XXXXXXX, KC_END, XXXXXXX, _______, 
									  _______, _______, _______, MO(3),   _______, _______, _______, KC_DEL , _______, _______),

	[3] = LAYOUT(	XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 				    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
					XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 					XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
					XXXXXXX, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, 					XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX, 
					XXXXXXX, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,
									  _______, _______, _______, _______, _______, _______, _______, KC_DEL , _______, _______)
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
};

#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)

#ifdef ENCODER_ENABLE
// Override default settings for the rotary encoders
bool encoder_update_user(uint8_t index, bool clockwise) {
    // 0: left encoder
    // 1: right encoder
    if (index == 0) {
		if (clockwise) {
			tap_code(KC_BTN5); // Mouse Forward 
		} else {
			tap_code(KC_BTN4); // Mouse Back
		}
    }

	if (index == 1) {
		if (clockwise) {
			tap_code(KC_WH_D); // Mousewheel down
		} else {
			tap_code(KC_WH_U); // Mousewheel up
		}
    }

    return false;
}
#endif

// Pre init settings for the keyboard.
// Currently, this disables the power LEDs for the controllers
void keyboard_pre_init_user(void) {
	// Set our Litaris LED pin as output
	setPinOutput(24);
	// Turn the LED off
	writePinHigh(24);
}
