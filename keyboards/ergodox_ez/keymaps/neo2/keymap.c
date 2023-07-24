#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_german.h"

#define DE_SS KC_MINS
#define DE_AE KC_QUOT
#define DE_UE KC_LBRC
#define DE_OE KC_SCLN


enum layers {
    BASE,  // default layer
    SYMB,
};

enum custom_keycodes {
    VRSN = SAFE_RANGE,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
		/* Keymap 0: Basic layer
		 *
		 * ,--------------------------------------------------.           ,--------------------------------------------------.
		 * |  ESC   |   1  |   2  |   3  |   4  |   5  |  6   |           |  ß   |   7  |   8  |   9  |  10  | DEL  | BSPACE |
		 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
		 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Z  |   U  |   I  |   O  |   P  |   Ü    |
		 * |--------+------+------+------+------+------| Undo |           |      |------+------+------+------+------+--------|
		 * |  Caps  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   Ö  |   Ä/#  |
		 * |--------+------+------+------+------+------| Cut  |           |  CS  |------+------+------+------+------+--------|
		 * | LShift |   Y  |   X  |   C  |   V  |   B  |      |           | MODE |   N  |   M  |   ,  |   .  |   -  | RShift |
		 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
		 *   |Win   |Ctrl | Copy| Paste  | Alt  |                                       | AltGr| Back  | Next | Ctrl | Enter |
		 *   `----------------------------------'                                       `----------------------------------'
		 *                                        ,-------------.       ,-------------.
		 *                                        | F5   | F6   |       | FKEY | Pscrn|
		 *                                 ,------+------+------|       |------+--------+------.
		 *                                 |      |      | F8   |       | Ctrl |        |      |
		 *                                 |LCursor|Shift|------|       |------|  Enter |Space |
		 *                                 |      |      |Space |       | Shift|        |      |
		 *                                 `--------------------'       `----------------------'
		 */
		// If it accepts an argument (i.e, is a function), it doesn't need KC_.
		// Otherwise, it needs KC_*
		[BASE] = LAYOUT_ergodox(  // layer 0 : default
		        // left hand
		        KC_ESC,          KC_1,           KC_2,     KC_3,     KC_4,     KC_5,   KC_6,
				KC_TAB,          KC_Q,           KC_W,     KC_E,     KC_R,     KC_T,   KC_MY_COMPUTER,
		        DE_HASH,         KC_A,           KC_S,     KC_D,     KC_F,     KC_G,
		        KC_LSFT,         DE_Y,           KC_X,     KC_C,     KC_V,     KC_B,   LSFT(KC_DELETE),
				KC_LGUI,  KC_LCTL, LCTL(KC_INSERT),  LSFT(KC_INSERT),  KC_LALT,

		                                               KC_F5, KC_F6,
		                                                      KC_F8,
										      MO(SYMB),KC_LSFT,KC_SPACE,
		        // right hand
				KC_MINUS,    KC_7,   KC_8,    KC_9,    KC_0,   KC_DEL,           KC_BSPC,
				KC_F12,       DE_Z,   KC_U,    KC_I,    KC_O,   KC_P,             DE_UE,
		                     KC_H,   KC_J,    KC_K,    KC_L,   DE_OE,            GUI_T (DE_AE),
				KC_F11,       KC_N,   KC_M,    KC_COMM, KC_DOT, DE_MINS,          KC_RSFT,
		                             KC_RALT, LALT(KC_LEFT), LALT(KC_RIGHT),  KC_RCTL,         KC_ENTER,
				KC_AUDIO_MUTE,	 KC_PSCR,
				KC_AUDIO_VOL_UP,
				KC_AUDIO_VOL_DOWN, KC_ENTER, KC_SPACE
		    ),
			/* Keymap 1: Missing Cursor Layer
			 *
			 * ,--------------------------------------------------.           ,--------------------------------------------------.
			 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
			 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
			 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
			 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
			 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
			 * |--------+------+------+------+------+------| PrtS |           |      |------+------+------+------+------+--------|
			 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
			 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
			 *   |      |      |      |      |      |                                       |      |      |      |      |      |
			 *   `----------------------------------'                                       `----------------------------------'
			 *                                        ,-------------.       ,-------------.
			 *                                        |      |      |       |      |      |
			 *                                 ,------|------|------|       |------+------+------.
			 *                                 |      |      |      |       |      |      |      |
			 *                                 |      |      |------|       |------|      |      |
			 *                                 |      |      |      |       |      |      |      |
			 *                                 `--------------------'       `--------------------'
			 */
			// SYMBOLS
			[SYMB] = LAYOUT_ergodox(
			       // left hand
			//		KC_TRNS,KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
					KC_SYSTEM_SLEEP,KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6,
					KC_TRNS,KC_PGUP,KC_BSPC,  KC_UP,KC_DEL,KC_PGDN,KC_SYSTEM_WAKE,
					KC_TRNS,KC_HOME,KC_LEFT, KC_DOWN, KC_RIGHT,KC_END,
					KC_TRNS,KC_ESCAPE,KC_TAB,KC_INSERT,KC_ENTER,KC_TRNS,KC_PSCR,
					KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
			                                       KC_TRNS,KC_TRNS,
												   	   	   	  KC_F4,
			                               KC_TRNS,KC_TRNS,KC_TRNS,
			       // right hand
				   KC_SYSTEM_SLEEP, KC_F7,   KC_F8,  KC_F9,   KC_F10,   KC_TRNS,  QK_CLEAR_EEPROM,
			       KC_TRNS, KC_TRNS,   KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,
				   KC_TRNS, KC_TRNS,   KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,
			       KC_TRNS, KC_TRNS,   KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,
			                           KC_TRNS,KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,
			       KC_TRNS, KC_TRNS,
			       KC_TRNS,
			       KC_TRNS, KC_TRNS, KC_TRNS
			),
			};
// clang-format on


/** \brief Adds the given physically pressed modifiers and sends a keyboard report immediately.
 *
 * \param mods A bitfield of modifiers to register.
 */
 void register_mods(uint8_t mods) {

	// swap the GUI modifier with the Neo2 MOD3
	if (mods == 8)
	{
		register_code(49);
		return;
	}

    if (mods) {
        add_mods(mods);
        send_keyboard_report();
    }
}

/** \brief Removes the given physically pressed modifiers and sends a keyboard report immediately.
 *
 * \param mods A bitfield of modifiers to unregister.
 */
 void unregister_mods(uint8_t mods) {

	// swap the GUI modifier with the Neo2 MOD3
	if (mods == 8)
	{
		unregister_code(49);
		return;
	}

    if (mods) {
        del_mods(mods);
        send_keyboard_report();
    }
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case VRSN:
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
                return false;
        }
    }
    return true;
}

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    uint8_t layer = get_highest_layer(state);
    switch (layer) {
        case 0:
#ifdef RGBLIGHT_COLOR_LAYER_0
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
            break;
        case 1:
            ergodox_right_led_1_on();
#ifdef RGBLIGHT_COLOR_LAYER_1
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
#endif
            break;
        case 2:
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_2
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
#endif
            break;
        case 3:
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_3
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
#endif
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_4
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
#endif
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_5
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
#endif
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_6
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
#endif
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_7
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
#endif
            break;
        default:
            break;
    }

    return state;
};
