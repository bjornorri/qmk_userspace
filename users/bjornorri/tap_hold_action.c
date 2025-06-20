#include "tap_hold_action.h"
#define MAX_TAP_HOLD_ACTION_KEYS 8 // Up to 8 custom keys

static tap_hold_action_key_t keys[MAX_TAP_HOLD_ACTION_KEYS];
static uint8_t               key_count = 0;

void tap_hold_action_register_key(uint16_t keycode, action_fn_t on_tap, action_fn_t on_hold) {
    if (key_count < MAX_TAP_HOLD_ACTION_KEYS) {
        keys[key_count++] = (tap_hold_action_key_t){keycode, on_tap, on_hold, false, false, 0};
    }
}

bool tap_hold_action_process_record(uint16_t keycode, keyrecord_t *record) {
    for (uint8_t i = 0; i < key_count; i++) {
        if (keys[i].keycode == keycode) {
            if (record->event.pressed) {
                keys[i].active    = true;
                keys[i].hold_sent = false;
                keys[i].timer     = timer_read();
            } else {
                if (!keys[i].hold_sent) {
                    keys[i].on_tap();
                }
                keys[i].active = false;
            }
            return false; // We handled it
        }
    }
    return true; // Let QMK handle other keys
}

void tap_hold_action_matrix_scan(void) {
    for (uint8_t i = 0; i < key_count; i++) {
        if (keys[i].active && !keys[i].hold_sent && timer_elapsed(keys[i].timer) > TAPPING_TERM) {
            keys[i].on_hold();
            keys[i].hold_sent = true;
        }
    }
}
