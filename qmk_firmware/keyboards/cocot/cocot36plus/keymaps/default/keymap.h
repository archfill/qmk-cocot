#pragma once

#include <stdio.h>
#include "quantum.h"

// Layer
#define L1_ENT LT(1, KC_ENT)
#define L2_SPC LT(2, KC_SPC)
#define L6_JA LT(6, KC_LNG1)
// Modifier-Tap
#define MT_S_JA LSFT_T(KC_LNG1)
#define MT_G_EN LGUI_T(KC_LNG2)
#define MT_C_EN LCTL_T(KC_LNG2)
#define MT_A_SH LALT_T(KC_SLSH)
#define MT_A_BS LALT_T(KC_BSPC)
#define MT_A_JA LALT_T(KC_LNG1)
#define MT_S_BS LSFT_T(KC_BSPC)
#define MT_S_SH LSFT_T(KC_SLSH)
// Modifiers
#define M_SG_4 SGUI(KC_4) // ScreenShot for mac
#define M_A_SC LALT(KC_SPC)
#define M_C_UP LCTL(KC_UP)
#define M_CS_T RCS(KC_T)
#define M_CS_SC RCS(KC_SPC)
#define M_A_GRV LALT(KC_GRV)
#define M_S_ENT LSFT(KC_ENT)
#define M_S_TAB LSFT(KC_TAB)

#define MS_BTN1 KC_MS_BTN1
#define MS_BTN2 KC_MS_BTN2
#define MS_BTN3 KC_MS_BTN3
#define MS_BTN4 KC_MS_BTN4
#define MS_BTN5 KC_MS_BTN5

#define LW_LNG2 KC_LANG2//LT(1,KC_LANG2)  // lower
#define RS_LNG1 KC_LANG1//LT(2,KC_LANG1)  // raise
#define DEL_ALT KC_DEL//ALT_T(KC_DEL)
//#define SPC_SFT LSFT_T(KC_SPC)

// Tap Dance
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
  bool is_press_action;
  td_state_t state;
} td_tap_t;

enum {
    X_TAP_DANCE_1,
    // X_TAP_DANCE_2,
};
#define KC_TD_1 TD(X_TAP_DANCE_1)
// #define TD_AB_BS TD(X_TAP_DANCE_2)
