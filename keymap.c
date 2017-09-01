// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include "atreus62.h"
#include <stdlib.h>

enum emoticons {
	DISFACE  = SAFE_RANGE,
	SHRUG,
	TFLIP,
	ADD,
	COMMIT,
	STATUS,
	AMEND,
	PUSH,
	PULL,
	VI_SAVE,
	VI_EXIT,
};

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

#define _DEFAULT 0
#define _NAV 1
#define _SERVER 2
#define _MACROS 3
#define _RESET 4

//Tap Dance Declarations
enum {
	TD_NEXT_PV = 0,
	TD_VOLD_MT = 1,
	TD_BRACES = 2,
	TD_CAPS = 3
};



void tap(uint16_t keycode){
	register_code(keycode);
	unregister_code(keycode);
};


//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
	//Tap once for Next Track, twice for Previous
	[TD_NEXT_PV]  = ACTION_TAP_DANCE_DOUBLE(KC_MNXT, KC_MPRV),
	//Tap once for Volume Down, twice for Mute
	[TD_VOLD_MT]  = ACTION_TAP_DANCE_DOUBLE(KC_VOLD, KC_MUTE),
	//Tap once for Left Brace, twice for Right Brace
	[TD_BRACES]  = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),
	[TD_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_RSFT, KC_CAPS)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_DEFAULT] = { /* qwerty */
		{ KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,     KC_5,    KC_TRNS,     KC_6,    KC_7,         KC_8,    KC_9,    KC_0,    KC_MINS },
		{ KC_BSLS,  KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,    KC_TRNS,     KC_Y,    KC_U,         KC_I,    KC_O,    KC_P,    TD(TD_BRACES) },
		{ KC_TAB,   KC_A,    KC_S,    KC_D,    KC_F,     KC_G,    KC_TRNS,     KC_H,    KC_J,         KC_K,    KC_L,    KC_SCLN, KC_QUOT },
		{ KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,    KC_ENT,      KC_N,    KC_M,         KC_COMM, KC_DOT,  KC_SLSH, TD(TD_CAPS) },
		{ KC_LCTL,  KC_LALT, KC_GRV,  KC_LGUI, TT(_NAV), KC_BSPC, KC_ENT,      KC_SPC,  LT(_SERVER, KC_NO),  KC_MINS, KC_EQL,  LGUI(KC_Z),  LSFT(LGUI(KC_Z)) }
	},

	[_NAV] = {
		{ TO(_DEFAULT),     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,  KC_F6,   KC_F7,      KC_F8,         KC_F9,         KC_F10,     KC_F11     },
		{ TD(TD_VOLD_MT),   KC_F12,  KC_UP,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,    KC_TRNS,       KC_MS_U,       KC_RBRC,    KC_VOLU    },
		{ KC_MPLY,          KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_MS_BTN1, KC_MS_L,       KC_MS_D,       KC_MS_R,    TD(TD_NEXT_PV)    },
		{ KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_MS_BTN2, LGUI(KC_LBRC), LGUI(KC_RBRC), KC_TRNS,    KC_TRNS    },
		{ KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, MO(_MACROS) ,KC_TRNS,       KC_TRNS,       TO(_RESET), LALT(LGUI(KC_POWER))   }
	},

	[_SERVER] = {
		{ TO(_DEFAULT),  M(1),    M(2),                M(3),          M(4),    KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
		{ KC_TRNS,       KC_TRNS, LSFT(LALT(KC_UP)),   LALT(KC_UP),   KC_TRNS, KC_TRNS, KC_TRNS,  KC_7,    KC_8,    KC_9,    KC_TRNS, KC_TRNS, KC_TRNS },
		{ KC_TRNS,       KC_TRNS, LSFT(LALT(KC_DOWN)), LALT(KC_DOWN), KC_TRNS, KC_TRNS, KC_TRNS,  KC_4,    KC_5,    KC_6,    KC_TRNS, KC_TRNS, KC_TRNS },
		{ KC_TRNS,       KC_TRNS, KC_TRNS,             KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS,  KC_1,    KC_2,    KC_3,    KC_TRNS, KC_TRNS, KC_TRNS },
		{ KC_TRNS,       KC_TRNS, KC_TRNS,             KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS,  KC_0,    KC_DOT,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS }
	},

	[_MACROS] = {
		{ TO(_DEFAULT),  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
		{ KC_TRNS,  VI_EXIT, VI_SAVE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
		{ STATUS,   ADD,     COMMIT,  AMEND,   PULL, PUSH, KC_TRNS,  KC_TRNS, DISFACE, SHRUG,   TFLIP,   KC_TRNS, KC_TRNS },
		{ KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
		{ KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS }
	},

	[_RESET] = {
		{ TO(_DEFAULT),  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   },
		{ KC_NO  ,       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   },
		{ KC_NO  ,       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   },
		{ KC_NO  ,       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   },
		{ KC_NO  ,       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , RESET }
	}
	/*
	[_TRNS] = {
		{ KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
		{ KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
		{ KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
		{ KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
		{ KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS }
	},
	*/
};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
	// MACRODOWN only works in this function
	switch (id) {
		case 0:
		if (record->event.pressed) {
			register_code(KC_RSFT);
		}
		else {
			unregister_code(KC_RSFT);
		}
		break;
		case 1:
		if (record->event.pressed) {
			SEND_STRING("cd ~/Projects/workforce/workforce_umbrella");
			return MACRO(T(ENT), END);
		}
		else {
			return false;
		}
		break;
		case 2:
		if (record->event.pressed) {
			SEND_STRING("mix phx.server");
			return MACRO(T(ENT), END);
		}
		else {
			return false;
		}
		break;
		case 3:
		if (record->event.pressed) {
			SEND_STRING("iex -S mix");
			return MACRO(T(ENT), END);
		}
		else {
			return false;
		}
		break;
		case 4:
		if (record->event.pressed) {
			SEND_STRING("mix test");
			return MACRO(T(ENT), END);
		}
		else {
			return false;
		}
		break;
	}
	return MACRO_NONE;
};

void matrix_scan_user(void) {
  static uint32_t prev_layer_state;
  uint8_t layer = biton32(layer_state);
  static char *layer_lookup[] = {"Default", "Nav/Media", "Server/Editor/Numpad", "vi/Git/Emojis", "Reset"};

  if (layer_state != prev_layer_state) {
    prev_layer_state = layer_state;
		if (layer_lookup[layer])
      xprintf("LAYER: %s\n", layer_lookup[layer]);
  }
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case DISFACE:       // ಠ_ಠ
		if(record->event.pressed){
			set_unicode_input_mode(UC_OSX);
			process_unicode((0x0CA0|QK_UNICODE), record);   // Eye
			register_code(KC_RSFT);
			tap(KC_MINS);
			unregister_code(KC_RSFT);
			process_unicode((0x0CA0|QK_UNICODE), record);   // Eye
		}
		return false;
		break;

		case TFLIP:         // (╯°□°)╯ ︵ ┻━┻
		if(record->event.pressed){
				register_code(KC_RSFT);
				tap(KC_9);
				unregister_code(KC_RSFT);
				process_unicode((0x256F|QK_UNICODE), record);   // Arm
				process_unicode((0x00B0|QK_UNICODE), record);   // Eye
				process_unicode((0x25A1|QK_UNICODE), record);   // Mouth
				process_unicode((0x00B0|QK_UNICODE), record);   // Eye
				register_code(KC_RSFT);
				tap(KC_0);
				unregister_code(KC_RSFT);
				process_unicode((0x256F|QK_UNICODE), record);   // Arm
				tap(KC_SPC);
				process_unicode((0x0361|QK_UNICODE), record);   // Flippy
				tap(KC_SPC);
				process_unicode((0x253B|QK_UNICODE), record);   // Table
				process_unicode((0x2501|QK_UNICODE), record);   // Table
				process_unicode((0x253B|QK_UNICODE), record);   // Table
		}
		return false;
		break;

		case SHRUG:			// ¯\_(ツ)_/¯
		if(record->event.pressed){
			set_unicode_input_mode(UC_OSX);
			process_unicode((0x00AF|QK_UNICODE), record);	// Hand
			tap(KC_BSLS);									// Arm
			register_code(KC_LSFT);
			tap(KC_UNDS);									// Arm
			tap(KC_LPRN);									// Head
			unregister_code(KC_LSFT);
			process_unicode((0x30C4|QK_UNICODE), record);	// Face
			register_code(KC_LSFT);
			tap(KC_RPRN);									// Head
			tap(KC_UNDS);									// Arm
			unregister_code(KC_LSFT);
			tap(KC_SLSH);									// Arm
			process_unicode((0x00AF|QK_UNICODE), record);	// Hand
		}
		return false;
		break;

		case ADD:
		if(record->event.pressed){
			SEND_STRING("git add .\n");
		}
		return false;
		break;

		case COMMIT:
		if(record->event.pressed){
			SEND_STRING("git commit -m ''");
			tap(KC_LEFT);
			layer_on(_DEFAULT);
			layer_off(_MACROS);
		}
		return false;
		break;

		case STATUS:
		if(record->event.pressed){
			SEND_STRING("git status \n");
		}
		return false;
		break;
		case AMEND:
		if(record->event.pressed){
			SEND_STRING("git commit --amend \n");
			layer_on(_DEFAULT);
			layer_off(_MACROS);
		}
		return false;
		break;
		case VI_SAVE:
		if(record->event.pressed){
			SEND_STRING(":wq \n");
			layer_on(_DEFAULT);
			layer_off(_MACROS);
		}
		return false;
		break;
		case VI_EXIT:
		if(record->event.pressed){
			SEND_STRING(":q! \n");
			layer_on(_DEFAULT);
			layer_off(_MACROS);
		}
		return false;
		break;
		case PULL:
		if(record->event.pressed){
			SEND_STRING("git name-rev --name-only HEAD | git pull origin $arg \n");
		}
		return false;
		break;
		case PUSH:
		if(record->event.pressed){
			SEND_STRING("git name-rev --name-only HEAD | git push origin $arg \n");
			layer_on(_DEFAULT);
			layer_off(_MACROS);
		}
		return false;
		break;
	}
	return true;
};
