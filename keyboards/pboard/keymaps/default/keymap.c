/* Copyright 2017 REPLACE_WITH_YOUR_NAME
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "pboard.h"

#define ___ KC_TRNS

#define _BASE 0
#define _FN 1
#define _MED 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = KEYMAP( \
    F(0),    KC_1,    KC_2,    KC_3,    KC_4,   KC_5,   KC_6, KC_7,   KC_8,    KC_9,   KC_0,     KC_MINS,  KC_EQL,  KC_BSPC, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,   KC_Y, KC_U,   KC_I,    KC_O,   KC_P,     KC_LBRC,  KC_RBRC, KC_BSLS, \
    MO(_FN), KC_A,    KC_S,    KC_D,    KC_F,   KC_G,   KC_H, KC_J,   KC_K,    KC_L,   KC_SCLN,  KC_QUOTE, KC_ENT, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,   KC_N, KC_M,   KC_COMM, KC_DOT, KC_SLASH, KC_RSFT,  KC_UP,   MO(_MED), \
    KC_LCTL, KC_LGUI, KC_LALT, KC_BSPC, KC_SPC,               KC_SPC, KC_RALT, MO(_FN),  KC_RCTL,  KC_LEFT,  KC_DOWN, KC_RIGHT \
  ),
  [_FN] = KEYMAP( \
    KC_GRAVE, KC_F1,         KC_F2,   KC_F3,          KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11,  KC_F12,  KC_DEL, \
    KC_CAPS,  LCTL(KC_LEFT), KC_UP,   LCTL(KC_RIGHT), ___,     ___,        KC_CALC, KC_PGUP, KC_UP,   KC_PGDN,  KC_PSCR, KC_SLCK, KC_PAUS, ___, \
    ___,      KC_LEFT,       KC_DOWN, KC_RIGHT,       KC_ENT,  ___,        KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, KC_INS,  KC_DEL,  ___, \
    ___,      KC_APP,        KC_VOLD, KC_VOLU,        KC_MUTE, ___,        KC_END,  ___,     ___,     ___,      ___,     ___,     ___,     ___, \
    ___,      ___,           ___,     ___,            ___,                          KC_ENT,  ___,     ___,      ___,     ___,     ___,     ___ \
  ),
  [_MED] = KEYMAP( \
    ___, ___, ___,     ___,     ___,     ___, ___, ___, ___, ___, ___, ___,     ___,     ___, \
    ___, ___, ___,     ___,     ___,     ___, ___, ___, ___, ___, ___, ___,     ___,     ___, \
    ___, ___, ___,     ___,     ___,     ___, ___, ___, ___, ___, ___, ___,     ___, \
    ___, ___, KC_VOLD, KC_VOLU, KC_MUTE, ___, ___, ___, ___, ___, ___, ___,     KC_MSTP, ___, \
    ___, ___, ___,     ___,     ___,               ___, ___, ___, ___, KC_MPRV, KC_MPLY, KC_MNXT \
  ),
};

const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_FUNCTION(0)
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  static uint8_t mods_pressed;

  switch (id) {
    case 0:
      mods_pressed = get_mods() & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT));

      if (record->event.pressed) {
        /* The key is being pressed.
         */
        if (mods_pressed) {
          add_key(KC_GRV);
          send_keyboard_report();
        } else {
          add_key(KC_ESC);
          send_keyboard_report();
        }
      } else {
        /* The key is being released.
         */
        if (mods_pressed) {
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

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};
