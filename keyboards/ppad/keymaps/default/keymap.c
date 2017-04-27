#include "ppad.h"

#define _____ KC_TRANS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = KEYMAP(
        KC_NLCK,    KC_PSLS,    KC_PAST,    KC_PMNS, \
        KC_P7,      KC_P8,      KC_P9,      KC_PPLS, \
        KC_P4,      KC_P5,      KC_P8,               \
        KC_P1,      KC_P2,      KC_P3,      KC_PENT, \
        KC_P0,                  KC_PDOT
    ),
    [1] = KEYMAP(
        KC_NLCK,    KC_PSLS,    KC_PAST,    KC_PMNS, \
        _____,      _____,      _____,      KC_PPLS, \
        _____,      _____,      _____,               \
        _____,      _____,      _____,      KC_PENT, \
        _____,                  KC_PDOT
    ),
};

const uint16_t PROGMEM fn_actions[] = {
};
