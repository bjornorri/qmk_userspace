#include QMK_KEYBOARD_H
#include "bjornorri.h"
#include "actions.h"
#include "tap_dance.h"
#include "tap_hold_modkey.h"

#ifdef KEYCHRON_COMMON
#    include "keychron_common.h"
#endif

// clang-format off
#ifdef NEW_SAFE_RANGE
#define MY_SAFE_RANGE NEW_SAFE_RANGE
#else
#define MY_SAFE_RANGE SAFE_RANGE
#endif
// clang-format on

// Custom keycodes for complex functionality.
enum custom_keycodes { MY_ESC = MY_SAFE_RANGE, MY_TAB, MY_SCLN, MY_MPLY };

// Hyper modifier mask.
#define MOD_MASK_HYPR MOD_MASK_CTRL | MOD_MASK_SHIFT | MOD_MASK_ALT | MOD_MASK_GUI

// Layer 0 customizations.
// ========================
#define L0_CAPS LT(1, KC_ESC)
#define L0_ENT MT(MOD_LSFT, KC_ENT)
#define L0_SLSH MT(MOD_RCTL, KC_SLSH)

// Custom keycodes.
#define L0_ESC MY_ESC
#define L0_TAB MY_TAB
#define L0_SCLN MY_SCLN
#define L0_MPLY MY_MPLY

// Layer 1 customizations.
// ========================
// Function row.
#define L1_ESC HYPR(KC_ESC)
#define L1_F1 HYPR(KC_F1)
#define L1_F2 HYPR(KC_F2)
#define L1_F3 HYPR(KC_F3)
#define L1_F4 HYPR(KC_F4)
#define L1_F5 HYPR(KC_F5)
#define L1_F6 HYPR(KC_F6)
#define L1_F7 HYPR(KC_F7)
#define L1_F8 HYPR(KC_F8)
#define L1_F9 HYPR(KC_F9)
#define L1_F10 HYPR(KC_F10)
#define L1_F11 HYPR(KC_F11)
#define L1_F12 HYPR(KC_F12)
// Number row.
#define L1_GRV HYPR(KC_GRV)
#define L1_1 HYPR(KC_1)
#define L1_2 HYPR(KC_2)
#define L1_3 HYPR(KC_3)
#define L1_4 HYPR(KC_4)
#define L1_5 HYPR(KC_5)
#define L1_6 HYPR(KC_6)
#define L1_7 HYPR(KC_7)
#define L1_8 HYPR(KC_8)
#define L1_9 HYPR(KC_9)
#define L1_0 HYPR(KC_0)
#define L1_MINS HYPR(KC_MINS)
#define L1_EQL HYPR(KC_EQL)
#define L1_BSPC HYPR(KC_BSPC)
// Q row.
#define L1_TAB HYPR(KC_TAB)
#define L1_Q HYPR(KC_Q)
#define L1_W HYPR(KC_W)
#define L1_E HYPR(KC_E)
#define L1_R HYPR(KC_R)
#define L1_T HYPR(KC_T)
#define L1_Y HYPR(KC_Y)
#define L1_U HYPR(KC_U)
#define L1_I HYPR(KC_I)
#define L1_O HYPR(KC_O)
#define L1_P HYPR(KC_P)
#define L1_LBRC LSG(KC_LBRC)
#define L1_RBRC LSG(KC_RBRC)
#define L1_BSLS LSG(KC_T)
// A row.
#define L1_A HYPR(KC_A)
#define L1_S HYPR(KC_S)
#define L1_D HYPR(KC_D)
#define L1_F HYPR(KC_F)
#define L1_G HYPR(KC_G)
#define L1_H KC_LEFT
#define L1_J KC_DOWN
#define L1_K KC_UP
#define L1_L KC_RGHT
#define L1_SCLN HYPR(KC_SCLN)
#define L1_QUOT HYPR(KC_QUOT)
#define L1_ENT HYPR(KC_ENT)
// Z row.
#define L1_Z HYPR(KC_Z)
#define L1_X HYPR(KC_X)
#define L1_C HYPR(KC_C)
#define L1_V HYPR(KC_V)
#define L1_B HYPR(KC_B)
#define L1_N HYPR(KC_N)
#define L1_M HYPR(KC_M)
#define L1_COMM C(S(KC_PGUP))
#define L1_DOT C(S(KC_PGDN))
#define L1_SLSH HYPR(KC_SLSH)
// Space row.
#define L1_SPC HYPR(KC_SPC)
// Navigation cluster.
#define L1_PGUP HYPR(KC_PGUP)
#define L1_PGDN HYPR(KC_PGDN)
// Arrow keys.
#define L1_LEFT HYPR(KC_LEFT)
#define L1_DOWN HYPR(KC_DOWN)
#define L1_UP HYPR(KC_UP)
#define L1_RGHT HYPR(KC_RGHT)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ansi_82(
        L0_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   L0_MPLY,            KC_MUTE,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            L0_MPLY,
        L0_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGUP,
        L0_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     L0_SCLN,  KC_QUOT,            L0_ENT,             KC_PGDN,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   L0_SLSH,            KC_RSFT,  KC_UP,
        KC_LCTL,  KC_LOPTN, KC_LCMMD,                               KC_SPC,                                 KC_RCMMD,KC_ROPTN,    MO(3),  KC_LEFT,  KC_DOWN,  KC_RGHT),
    [1] = LAYOUT_ansi_82(
        L1_ESC,   L1_F1,    L1_F2,    L1_F3,    L1_F4,    L1_F5,    L1_F6,    L1_F7,    L1_F8,    L1_F9,    L1_F10,   L1_F11,   L1_F12,   KC_TRNS,            KC_TRNS,
        L1_GRV,   L1_1,     L1_2,     L1_3,     L1_4,     L1_5,     L1_6,     L1_7,     L1_8,     L1_9,     L1_0,     L1_MINS,  L1_EQL,   L1_BSPC,            KC_TRNS,
        L1_TAB,   L1_Q,     L1_W,     L1_E,     L1_R,     L1_T,     L1_Y,     L1_U,     L1_I,     L1_O,     L1_P,     L1_LBRC,  L1_RBRC,  L1_BSLS,            L1_PGUP,
        KC_TRNS,  L1_A,     L1_S,     L1_D,     L1_F,     L1_G,     L1_H,     L1_J,     L1_K,     L1_L,     L1_SCLN,  L1_QUOT,            L1_ENT,             L1_PGDN,
        KC_TRNS,            L1_Z,     L1_X,     L1_C,     L1_V,     L1_B,     L1_N,     L1_M,     L1_COMM,  L1_DOT,   L1_SLSH,            KC_TRNS,  L1_UP,
        KC_TRNS,  KC_TRNS,  KC_TRNS,                                L1_SPC,                                 KC_TRNS,  KC_TRNS,  KC_TRNS,  L1_LEFT,  L1_DOWN,  L1_RGHT),
    [2] = LAYOUT_ansi_82(
        KC_TRNS,  KC_BRID,  KC_BRIU,  KC_MCTL,  KC_LPAD,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_TRNS,            KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,            KC_TRNS,
        KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                                KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS),

    [3] = LAYOUT_ansi_82(
        KC_TRNS,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_TRNS,            RGB_TOG,
        KC_TRNS,  BT_HST1,  BT_HST2,  BT_HST3,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
        KC_TRNS,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,            KC_END,
        KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  BAT_LVL,  NK_TOGG,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                                KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS),
};
// clang-format on

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [1] = {ENCODER_CCW_CW(KC_BRID, KC_BRIU)},
    [2] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [3] = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
};
#endif // ENCODER_MAP_ENABLE

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case L0_CAPS:
            return true;
    }
    return false;
}

void keyboard_post_init_user(void) {
    tap_hold_modkey_register(MY_SCLN, KC_SCLN, MOD_MASK_HYPR);
    tap_hold_modkey_register(MY_TAB, KC_TAB, MOD_MASK_CTRL);
    tap_dance_register_key(MY_ESC, action_tap_esc, NULL, NULL, action_lock_mac);
    tap_dance_register_key(MY_MPLY, action_media_play, action_media_next, action_media_prev, action_media_play);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef KEYCHRON_COMMON
    if (!process_record_keychron_common(keycode, record)) {
        return false;
    }
#endif
    if (!tap_hold_modkey_process_record(keycode, record)) {
        return false;
    }
    if (!tap_dance_process_record(keycode, record)) {
        return false;
    }
    return true;
}

void matrix_scan_user(void) {
    tap_hold_modkey_matrix_scan();
    tap_dance_matrix_scan();
}
