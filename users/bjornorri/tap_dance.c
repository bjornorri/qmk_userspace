#include "tap_dance.h"
#define MAX_TAP_DANCE_KEYS 8 // Up to 8 custom keys

static tap_dance_key_t keys[MAX_TAP_DANCE_KEYS];
static uint8_t         key_count = 0;

static void finalize_tap_dance(tap_dance_key_t *k);

void tap_dance_register_key(uint16_t keycode, action_fn_t on_tap, action_fn_t on_double_tap, action_fn_t on_triple_tap, action_fn_t on_hold) {
    if (key_count < MAX_TAP_DANCE_KEYS) {
        keys[key_count++] = (tap_dance_key_t){
            .keycode       = keycode,
            .on_tap        = on_tap,
            .on_double_tap = on_double_tap,
            .on_triple_tap = on_triple_tap,
            .on_hold       = on_hold,
            .active        = false,
            .pressed       = false,
            .hold_sent     = false,
            .tap_count     = 0,
            .timer         = 0,
        };
    }
}

bool tap_dance_process_record(uint16_t keycode, keyrecord_t *record) {
    for (uint8_t i = 0; i < key_count; i++) {
        tap_dance_key_t *k = &keys[i];
        if (k->keycode == keycode) {
            if (record->event.pressed) {
                if (!k->active) {
                    k->active    = true;
                    k->tap_count = 0;
                }
                k->pressed   = true;
                k->hold_sent = false;
                k->timer     = timer_read();
            } else { // released
                if (k->hold_sent) {
                    k->active  = false;
                    k->pressed = false;
                } else {
                    k->tap_count++;
                    k->pressed = false;
                    k->timer   = timer_read();
                    if (!k->on_double_tap && !k->on_triple_tap) {
                        // Immediate action when no multi-tap actions defined
                        finalize_tap_dance(k);
                    } else if (!k->on_triple_tap && k->tap_count == 2) {
                        // No triple-tap action configured, finalize after double-tap
                        finalize_tap_dance(k);
                    } else if (k->tap_count >= 3) {
                        finalize_tap_dance(k);
                    }
                }
            }
            return false; // handled
        }
    }
    return true; // Let QMK handle other keys
}

static void finalize_tap_dance(tap_dance_key_t *k) {
    switch (k->tap_count) {
        case 1:
            if (k->on_tap) {
                k->on_tap();
            }
            break;
        case 2:
            if (k->on_double_tap) {
                k->on_double_tap();
            }
            break;
        case 3:
        default:
            if (k->on_triple_tap) {
                k->on_triple_tap();
            }
            break;
    }
    k->active = false;
}

void tap_dance_matrix_scan(void) {
    for (uint8_t i = 0; i < key_count; i++) {
        tap_dance_key_t *k = &keys[i];
        if (!k->active) {
            continue;
        }

        if (k->pressed && !k->hold_sent && timer_elapsed(k->timer) > TAPPING_TERM) {
            if (k->on_hold) {
                k->on_hold();
            }
            k->hold_sent = true;
        }

        if (!k->pressed && !k->hold_sent && timer_elapsed(k->timer) > TAPPING_TERM) {
            finalize_tap_dance(k);
        }

        if (k->hold_sent && !k->pressed) {
            // hold action already sent and key released
            k->active = false;
        }
    }
}
