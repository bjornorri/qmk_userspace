#include QMK_KEYBOARD_H
#include "bjornorri.h"
#include "actions.h"
#include "tap_hold.h"

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
enum custom_keycodes {
    MY_ESC = MY_SAFE_RANGE,
    MY_MPLY // Media play/pause.
};

// Layer 0 customizations.
// ========================
#define L0_CAPS LT(1, KC_ESC)
#define L0_ENT MT(MOD_LSFT, KC_ENT)
#define L0_SCLN MT(MOD_HYPR, KC_SCLN)
#define L0_SLSH MT(MOD_RCTL, KC_SLSH)
#define L0_TAB MT(MOD_LCTL, KC_TAB)
#define L0_TRGR G(KC_BSLS)

// Custom keycodes.
#define L0_ESC MY_ESC
#define L0_MPLY MY_MPLY

// Layer 1 customizations.
// ========================
#define L1_LBRC LSG(KC_LBRC)
#define L1_RBRC LSG(KC_RBRC)
#define L1_BSLS LSG(KC_T)
#define L1_COMM C(S(KC_PGUP))
#define L1_DOT C(S(KC_PGDN))

// Hyper on layer 1.
#define L1_ENT HYPR(KC_ENT)
#define L1_SPC HYPR(KC_SPC)
#define L1_LEFT HYPR(KC_LEFT)
#define L1_RGHT HYPR(KC_RGHT)
#define L1_UP HYPR(KC_UP)
#define L1_DOWN HYPR(KC_DOWN)
#define L1_M HYPR(KC_M)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ansi_82(
        L0_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   L0_MPLY,            KC_MUTE,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
        L0_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
        L0_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     L0_SCLN,  KC_QUOT,            L0_ENT,             L0_TRGR,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   L0_SLSH,            KC_RSFT,  KC_UP,
        KC_LCTL,  KC_LOPTN, KC_LCMMD,                               KC_SPC,                                 KC_RCMMD,KC_ROPTN,    MO(3),  KC_LEFT,  KC_DOWN,  KC_RGHT),
    [1] = LAYOUT_ansi_82(
        KC_CAPS,  KC_BRID,  KC_BRIU,  KC_MCTL,  KC_LPAD,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_TRNS,            KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  L1_LBRC,  L1_RBRC,  L1_BSLS,            KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_TRNS,  KC_TRNS,            L1_ENT,             KC_TRNS,
        KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  L1_M,     L1_COMM,  L1_DOT,   KC_TRNS,            KC_TRNS,  L1_UP,
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
        case L0_ENT:
            return true;
        case L0_TAB:
            return true;
        case L0_SCLN:
            return true;
        case L0_SLSH:
            return true;
    }
    return false;
}

void keyboard_post_init_user(void) {
    tap_hold_register_key(MY_ESC, action_tap_esc, action_lock_mac);
    tap_hold_register_key(MY_MPLY, action_none, action_play_pause);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef KEYCHRON_COMMON
    if (!process_record_keychron_common(keycode, record)) {
        return false;
    }
#endif
    if (!tap_hold_process_record(keycode, record)) {
        return false;
    }
    return true;
}

void matrix_scan_user(void) {
    tap_hold_matrix_scan();
}
