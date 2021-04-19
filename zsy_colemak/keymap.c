/* Copyright 2017 Zhao Shuyang
 *
 ** This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * M,ERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
 

#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "keymap_swedish.h"

#define BASE 0 // default layer'
#define GAME 1 

#define MV 3 // Funtion and movement
#define NUM 2 // Num pad

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | ESC    |  !   |  "   |  #   |  #   |  %   | &    |           |Light |  /   |  (   |  )   |  =   |  ?   |  _     |
 * |        |  1   |  2 @ |  3 £ |  4 $ |  5 € | 6    |           |      |  7 { |  8 [ |  9 ] |  0 } |  + \ |  - –   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    | Q    | W    | F    | P    | G    |  MO  |           |  MO  | J    | L    | U    | Y    | ^    | `      |
 * |        |      |      |      |      |      |      |           |      |      |      |      |      | ¨ ~  | ´ ¸    |
 * |--------+------+------+------+------+------| (L1) |           | (L1) |------+------+------+------+------+--------|
 * | LShift | A    | R    | S    | T    | D    |------|           |------| H    |  N   | E    | I    | O    | RShift |
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------| LGUI |           | Num  |------+------+------+------+------+--------|
 * | <>|    | Z    | X    | C    | V    | B    |      |           |      | K    | M    | ;    | :    | _    | '*ˇ    |
 * | LShift |      |      |      |      |      |      |           |      |      |      | ,    | .    | - –  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LCRTL| LCtrl| Left | Right | LAlt |                                       | AltGr| Down| Up   | RCrtl| RCrtl |
 *   |      |      |      |       |      |                                       |      |     |      |      |       |
 *   `----------------------------------'                                        `----------------------------------'
 *                                        ,-------------.       ,--------------.
 *                                        |  WB  | WF   |       | Home |  End  |
 *                                 ,------|------|------|       |------+-------+------.
 *                                 |      |      | QWERT|       | PgUp |       |      |
 *                                 |Space | Del  |------|       |------| Enter |Back  |
 *                                 |      |      | MV   |       | PgDn |       |Space |
 *                                 `--------------------'       `---------------------'
 */
  
[BASE] = LAYOUT_ergodox(  // layer 0 : default
    // left hand
    KC_ESC,          KC_1,     KC_2,     KC_3,    KC_4,    KC_5,   KC_6,
    KC_TAB,          KC_Q,     KC_W,     KC_F,    KC_P,    KC_G,   MO(MV),
    KC_LSFT,    KC_A,     KC_R,     KC_S,    KC_T,    KC_D,
    SFT_T(NO_LESS),  KC_Z,     KC_X,     KC_C,    KC_V,    KC_B,   KC_LGUI,
    KC_LCTRL, KC_LCTRL,  KC_LEFT, KC_RIGHT, KC_LALT, 
    KC_WBAK,  KC_WFWD,
    TO(QWERT),
    KC_SPC, KC_DEL, TO(MV),

    // right hand
    RGB_TOG, KC_7,   KC_8,    KC_9,    KC_0,    NO_PLUS,  KC_PSCREEN,
    MO(MV),   KC_J,   KC_L,    KC_U,    KC_Y,     NO_QUOT,  NO_ACUT,
        KC_H,   KC_N,    KC_E,    KC_I,    KC_O,     KC_RSFT,
    TO(NUM), KC_K,   KC_M,    KC_COMM, KC_DOT,     NO_MINS,  SFT_T(NO_APOS),
                      KC_ALGR,  KC_DOWN, KC_UP,    KC_RCTRL, KC_RCTRL,
    KC_HOME,   KC_END, 
    KC_PGUP,
    KC_PGDN,   KC_ENTER, KC_BSPC
),

/* Keymap 1: QWERT
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | ESC    |  !   |  "   |  #   |  #   |  %   | &    |           | Prt  |  /   |  (   |  )   |  =   |  ?   |  _     |
 * |        |  1   |  2 @ |  3 £ |  4 $ |  5 € | 6    |           | Scr  |  7 { |  8 [ |  9 ] |  0 } |  + \ |  - –   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    | Q    | W    | E    | R    | T    |  TG  |           | NUM  | Y    | U    | I    | O    | P    | ^      |
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      | ¨ ~    |
 * |--------+------+------+------+------+------| (L1) |           |      |------+------+------+------+------+--------|
 * | LShift | A    | S    | D    | F    | G    |------|           |------| H    |  J   | K    | L    | *    | RShift |
 * |        |      |      |      | LT(1)|      |      |           |      |      | LT(1)|      |      | ' ˇ  |        |
 * |--------+------+------+------+------+------| LGUI |           | LGUI |------+------+------+------+------+--------|
 * | <>|    | Z    | X    | C    | V    | B    |      |           |      | N    | M    | ;    | :    | _    | ´`¸    |
 * | LShift |      |      |      |      |      |      |           |      |      |      | ,    | .    | - –  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LCRTL| LCtrl| Left | Right | LAlt |                                       | AltGr| Down| Up   | RCrtl| RCrtl |
 *   |      |      |      |       |      |                                       |      |     |      |      |       |
 *   `----------------------------------'                                        `----------------------------------'
 *                                        ,-------------.       ,--------------.
 *                                        |  WB  | WF   |       | Home |  End  |
 *                                 ,------|------|------|       |------+-------+------.
 *                                 |      |      | QWERT|       | PgUp |       |      |
 *                                 |Space | Del  |------|       |------| Enter |Back  |
 *                                 |      |      | Undo |       | PgDn |       |Space |
 *                                 `--------------------'       `---------------------'
 */
/*  
[QWERT] = LAYOUT_ergodox(  // layer 1: QWERT
    // left hand
    KC_ESC,          KC_1,     KC_2,     KC_3,    KC_4,    KC_5,   KC_6,
    KC_TAB,          KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,   TT(MV),
    KC_LSFT,    KC_A,     KC_S,     KC_D,    LT(MV, KC_F),    KC_G,
    SFT_T(NO_LESS),  KC_Z,     KC_X,     KC_C,    KC_V,    KC_B,   KC_LGUI,
    KC_LCTRL, KC_LCTRL,  KC_LEFT, KC_RIGHT, KC_LALT, 
    KC_WBAK,  KC_WFWD,
    TO(BASE),
    KC_SPC, KC_DEL, KC_UNDO,

    // right hand
    RGB_TOG, KC_7,   KC_8,    KC_9,    KC_0,    NO_PLUS,  KC_PSCREEN,
    TO(NUM),   KC_Y,   KC_U,    KC_I,    KC_O,  KC_P,   NO_QUOT,
        KC_H,   LT(MV, KC_J),    KC_K,    KC_L,   NO_APOS,     KC_RSFT,
    KC_LGUI, KC_N,   KC_M,    KC_COMM, KC_DOT,  NO_MINS,  SFT_T(NO_ACUT),
                      NO_ALGR,  KC_DOWN, KC_UP,   KC_RCTRL, KC_RCTRL,
    KC_HOME,   KC_END, 
    KC_PGUP,
    KC_PGDN,   KC_ENTER, KC_BSPC
),
*/

[GAME] = LAYOUT_ergodox(
       KC_ESC,  KC_1,     KC_2,     KC_3,    KC_4,    KC_5,   KC_6,   
       KC_TRNS, KC_TRNS, KC_TRNS, KC_UP, KC_PGUP, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_7,   KC_8,    KC_9,    KC_0,    NO_PLUS,  KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_J, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),

/* Keymap 2: Funtion and movement
 *
  ,--------------------------------------------------.            ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |      |  F7  |  F8  |  F9  |  F10 |  F11 | F12    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | Up   | PgUp |      |      |           |      |      | WhUp | MsUp |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | Home | Left | Down | Rght | End  |------|           |------| LClk | MsLf | MsDn | MsRt |RClk  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      | Down | PgDn |      |      |           |      |      | WhDn | MsDn |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      | Lclk |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */

[MV] = LAYOUT_ergodox(
       KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_UP, KC_PGUP, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_DOWN, KC_PGDN, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_F7,  KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, 
       KC_TRNS,  KC_TRNS, KC_MS_WH_UP, KC_MS_UP, KC_BTN2, KC_TRNS, KC_TRNS,
                 KC_BTN1, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_BTN2, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_MS_WH_DOWN, KC_MS_DOWN, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_BTN1
),



/* Keymap 3: Funtion and movement
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |   1  |   2  |   3  |   4  |   5  |   6  |           |      |  7   |  8   |  9   |  0   |  +   |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | Up   | PgUp |      |      |           |  Num |  4   |  5   |  6   |  +   |  -   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | Home | Left | Down | Rght | End  |------|           |------|  1   |  2   |  3   |  *   |  /   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      | PgDn |      |      |           |      |  0   |  0   |  ,   |  .   |  =   |        |
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

[NUM] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_PEQL, KC_PSLS, KC_PAST, NO_MINS, KC_TRNS,
       TO(BASE), KC_TRNS, KC_7, KC_8, KC_9, KC_PLUS, KC_TRNS,
                 KC_TRNS, KC_4, KC_5, KC_6, KC_DOT, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_1, KC_2, KC_3, KC_COMMA, KC_TRNS,
       KC_0, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, 
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS       
),
};



// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
  rgblight_enable();

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
        case 1:
	  ergodox_right_led_2_on();
	  break;
        case 2:
	  ergodox_right_led_1_on();
	 
	  break;
        case 3:
	  ergodox_right_led_3_on();
	  
	  break;
        default:
	  
	  break;
    }
    /*
    if (keyboard_report->mods & (MOD_BIT(KC_LCTL)|MOD_BIT(KC_RCTRL))) {
      ergodox_right_led_1_on();
    }
    if (keyboard_report->mods & (MOD_BIT(KC_LALT)|MOD_BIT(KC_RALT))) {
      ergodox_right_led_2_on();
    }
    if (keyboard_report->mods & (MOD_BIT(KC_LSFT)|MOD_BIT(KC_RSFT))) {
      ergodox_right_led_3_on();
    }
    */
};
