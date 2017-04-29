#include "ppad.h"

#define _____ KC_TRNS

#define _NUM 0
#define _MED 1

enum reset_state {
    PPSTART,
    PPDIV,
    PPENT,
    PPMULT,
    PPPLUS,
    PPMINUS,
    PPZERO
};

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
    [PPDIV] = ACTION_FUNCTION(PPDIV),
    [PPENT] = ACTION_FUNCTION(PPENT),
    [PPMULT] = ACTION_FUNCTION(PPMULT),
    [PPPLUS] = ACTION_FUNCTION(PPPLUS),
    [PPMINUS] = ACTION_FUNCTION(PPMINUS),
    [PPZERO] = ACTION_FUNCTION(PPZERO),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  static enum reset_state currentState;

  switch (id) {
    case 0:
      /* Handle the combined Grave/Esc key
       */
      mods_pressed = get_mods()&GRAVE_MODS; // Check to see what mods are pressed

      if (record->event.pressed) {
        /* The key is being pressed.
         */
        if (mods_pressed) {
          mod_flag = true;
          add_key(KC_GRV);
          send_keyboard_report();
        } else {
          add_key(KC_ESC);
          send_keyboard_report();
        }
      } else {
        /* The key is being released.
         */
        if (mod_flag) {
          mod_flag = false;
          del_key(KC_GRV);
          send_keyboard_report();
        } else {
          del_key(KC_ESC);
          send_keyboard_report();
        }
      }
      break;
  }
}
