#pragma once
#include QMK_KEYBOARD_H

static void action_tap_esc(void) {
    tap_code(KC_ESC);
}

static void action_lock_mac(void) {
    tap_code16(G(C(KC_Q)));
}
