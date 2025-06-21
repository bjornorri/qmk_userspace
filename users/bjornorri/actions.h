#pragma once
#include QMK_KEYBOARD_H

static void action_tap_esc(void) {
    tap_code(KC_ESC);
}

static void action_lock_mac(void) {
    tap_code16(G(C(KC_Q)));
}

static void action_media_play(void) {
    tap_code(KC_MPLY);
}

static void action_media_next(void) {
    tap_code(KC_MNXT);
}

static void action_media_prev(void) {
    tap_code(KC_MPRV);
}
