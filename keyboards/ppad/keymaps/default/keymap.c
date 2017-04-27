#include "ppad.h"

#define _____ KC_TRNS

#define _NUM 0
#define _MED 1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_NUM] = KEYMAP(
        LT(_MED, KC_NLCK),    KC_PSLS,    KC_PAST,    KC_PMNS, \
        KC_P7,                KC_P8,      KC_P9,      KC_PPLS, \
        KC_P4,                KC_P5,      KC_P8,               \
        KC_P1,                KC_P2,      KC_P3,      KC_PENT, \
        KC_P0,                            KC_PDOT
    ),
    [_MED] = KEYMAP(
        _____,                _____,      _____,      KC_VOLD, \
        _____,                _____,      _____,      KC_VOLU, \
        _____,                _____,      _____,               \
        _____,                _____,      _____,      KC_MUTE, \
        _____,                            _____
    ),
};

const uint16_t PROGMEM fn_actions[] = {
};
