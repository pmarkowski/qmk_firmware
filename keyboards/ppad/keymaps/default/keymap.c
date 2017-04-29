#include "ppad.h"

#define _____ KC_TRNS

#define _NUM 0
#define _MED 1

enum reset_state {
    PP_START,
    PP_DIV,
    PP_ENT,
    PP_MULT,
    PP_PLUS,
    PP_MINUS,
    PP_ZERO
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_NUM] = KEYMAP(
        LT(_MED, KC_NLCK),    PP_DIV,     PP_MULT,    PP_MINUS, \
        KC_P7,                KC_P8,      KC_P9,      PP_PLUS, \
        KC_P4,                KC_P5,      KC_P8,               \
        KC_P1,                KC_P2,      KC_P3,      PP_ENT, \
        PP_ZERO,                          KC_PDOT
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
    [PP_DIV] = ACTION_FUNCTION(PP_DIV),
    [PP_ENT] = ACTION_FUNCTION(PP_ENT),
    [PP_MULT] = ACTION_FUNCTION(PP_MULT),
    [PP_PLUS] = ACTION_FUNCTION(PP_PLUS),
    [PP_MINUS] = ACTION_FUNCTION(PP_MINUS),
    [PP_ZERO] = ACTION_FUNCTION(PP_ZERO),
};

static enum reset_state current_state = PP_START;

void advance_or_reset_state(keyrecord_t *record, uint8_t id) {
  if (record->event.pressed && current_state == (id - 1)) {
    current_state = id;
  }
  else {
    current_state = PP_START;
  }
}

void add_or_remove_key(keyrecord_t *record, uint8_t key_value) {
  if (record->event.pressed) {
    add_key(key_value);
  }
  else {
    del_key(key_value);
  }

  send_keyboard_report();
}

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  advance_or_reset_state(record, id);

  uint16_t key_value = 0;
  switch (id) {
    case PP_DIV:
      key_value = KC_PSLS;
      break;
    case PP_ENT:
      key_value = KC_PENT;
      break;
    case PP_MULT:
      key_value = KC_PAST;
      break;
    case PP_PLUS:
      key_value = KC_PPLS;
      break;
    case PP_MINUS:
      key_value = KC_PMNS;
      break;
    case PP_ZERO:
      if (current_state == PP_ZERO) {
        key_value = RESET;
      }
      else {
        key_value = KC_P0;
      }
      break;
  }

  add_or_remove_key(record, key_value);
}
