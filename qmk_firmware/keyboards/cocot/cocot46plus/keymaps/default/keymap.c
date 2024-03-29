/*
Copyright 2022 aki27

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include <stdio.h>
#include "quantum.h"


// Defines names for use in layer keycodes and the keymap
enum layer_number {
    _BASE = 0,
    _LOWER = 1,
    _RAISE = 2,
    _TRACKBALL = 3,
    _Layer4 = 4,
    _Layer5 = 5
};


#define L1_SPC LT(1, KC_SPC)
#define L2_ENT LT(2, KC_ENT)
#define DEL_ALT LALT_T(KC_DEL)
#define BS_SFT LSFT_T(KC_BSPC)
#define TAB_CTL LCTL_T(KC_TAB)
#define LN2_GUI LGUI_T(KC_LNG2)
#define LN1_SFT LSFT_T(KC_LNG1)

#define M_SG_4 SGUI(KC_4) // ScreenShot for mac
#define M_A_SC LALT(KC_SPC)
#define M_C_UP LCTL(KC_UP)
#define M_CS_T RCS(KC_T)
#define M_S_TAB LSFT(KC_TAB)
#define M_S_ENT LSFT(KC_ENT)

/*
#define CPI_SW USER00
#define SCRL_SW USER01
#define ROT_R15 USER02
#define ROT_L15 USER03
#define SCRL_MO USER04
#define SCRL_TO USER05
#define SCRL_IN USER06
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
      KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_SCLN,
      KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                          KC_H,    KC_J,    KC_K,    KC_L,    KC_MINS, KC_QUOT,
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                          KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,
                        KC_LALT, LN2_GUI, L1_SPC,  KC_LCTL,   KC_MS_BTN1,             KC_MS_BTN2, BS_SFT,  L2_ENT,  LN1_SFT, MO(4),
                                                                          KC_MS_BTN3,             XXXXXXX, XXXXXXX, XXXXXXX
    ),
  [_LOWER] = LAYOUT(
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                         KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
      _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
      _______, KC_F11,  _______, _______, M_S_TAB, KC_TAB,                                        KC_ESC,  KC_DEL,  _______, _______, KC_F12,  _______,
                        _______, _______, _______, _______,   KC_MS_BTN4,             KC_MS_BTN5, KC_DEL,  M_S_ENT, _______, _______,
                                                                          KC_MS_BTN3,             XXXXXXX, XXXXXXX, XXXXXXX
    ),
  [_RAISE] = LAYOUT(
      _______, KC_BSLS, KC_CIRC, KC_EXLM, KC_AMPR, KC_PIPE,                                       KC_AT,   KC_EQL,  KC_PLUS, KC_ASTR, KC_PERC, _______,
      _______, KC_HASH, KC_DLR,  KC_DQUO, KC_QUOT, KC_TILD,                                       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_GRV,  _______,
      KC_PGUP, KC_LSFT, KC_COLN, KC_LPRN, KC_LCBR, KC_LBRC,                                       KC_RBRC, KC_RCBR, KC_RPRN, KC_SCLN, _______, KC_PGDN,
                        _______, KC_LALT, _______, KC_LCTL,   KC_MS_BTN4,             KC_MS_BTN5, _______, _______, _______, _______,
                                                                          KC_MS_BTN3,             XXXXXXX, XXXXXXX, XXXXXXX
    ),
  [_TRACKBALL] = LAYOUT(
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG,                                       SCRL_TO, CPI_SW,  SCRL_SW, ROT_L15, ROT_R15, XXXXXXX,
      XXXXXXX, XXXXXXX, RGB_VAI, RGB_SAI, RGB_HUI, RGB_MOD,                                       SCRL_MO, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      MO(3),   XXXXXXX, RGB_VAD, RGB_SAD, RGB_HUD,RGB_RMOD,                                       SCRL_IN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_MS_BTN1,             KC_MS_BTN2, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                                          KC_MS_BTN3,             XXXXXXX, XXXXXXX, XXXXXXX
    ),
  [_Layer4] = LAYOUT(
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  M_CS_T,                                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, M_SG_4,  XXXXXXX, XXXXXXX, M_A_SC,   M_C_UP,                                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,                                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_INS,  XXXXXXX,
                        QK_BOOT, EE_CLR,  XXXXXXX,  XXXXXXX,  XXXXXXX,                XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                                          KC_MUTE,                XXXXXXX, XXXXXXX, XXXXXXX
    ),
  [_Layer5] = LAYOUT(
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                        XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,                XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                                          XXXXXXX,                XXXXXXX, XXXXXXX, XXXXXXX
    )
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] =   { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [1] =   { ENCODER_CCW_CW(_______, _______) },
    [2] =   { ENCODER_CCW_CW(_______, _______) },
    [3] =   { ENCODER_CCW_CW(_______, _______) },
    [4] =   { ENCODER_CCW_CW(_______, _______) },
    [5] =   { ENCODER_CCW_CW(_______, _______) }
};
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _LOWER:
        // rgblight_sethsv_range(HSV_BLUE, 0, 2);
        cocot_set_scroll_mode(true);
        break;
    case _RAISE:
        // rgblight_sethsv_range(HSV_RED, 0, 2);
        cocot_set_scroll_mode(true);
        break;
    case _TRACKBALL:
        // rgblight_sethsv_range(HSV_GREEN, 0, 2);
        cocot_set_scroll_mode(false);
        break;
    case _Layer4:
        // rgblight_sethsv_range(HSV_YELLOW, 0, 2);
        cocot_set_scroll_mode(false);
        break;
    case _Layer5:
        // rgblight_sethsv_range(HSV_CYAN, 0, 2);
        cocot_set_scroll_mode(false);
        break;
    // case _Layer6:
    //     rgblight_sethsv_range(HSV_ORANGE, 0, 2);
    //     cocot_set_scroll_mode(false);
    //     break;
    default:
        // rgblight_sethsv_range( 0, 0, 0, 0, 2);
        cocot_set_scroll_mode(false);
        break;
    }
    // rgblight_set_effect_range( 2, 10);
    return state;
};


#ifdef OLED_ENABLE
bool oled_task_user(void) {
    render_logo();
    oled_write_layer_state();
    return false;
}
#endif

