#include "tap_hold_modkey.h"

#define MAX_tap_hold_modkey_KEYS 8

typedef struct {
    uint16_t keycode;
    uint16_t tap_key;
    uint8_t  mod;
    bool     active;
    bool     mod_sent;
    bool     force_tap;
    uint16_t timer;
} tap_hold_modkey_key_t;

static tap_hold_modkey_key_t tap_hold_modkey_keys[MAX_tap_hold_modkey_KEYS];
static uint8_t               tap_hold_modkey_count = 0;

void tap_hold_modkey_register(uint16_t keycode, uint16_t tap_key, uint8_t mod) {
    if (tap_hold_modkey_count < MAX_tap_hold_modkey_KEYS) {
        tap_hold_modkey_keys[tap_hold_modkey_count++] = (tap_hold_modkey_key_t){.keycode = keycode, .tap_key = tap_key, .mod = mod, .active = false, .mod_sent = false, .force_tap = false, .timer = 0};
    }
}

bool tap_hold_modkey_process_record(uint16_t keycode, keyrecord_t *record) {
    for (uint8_t i = 0; i < tap_hold_modkey_count; i++) {
        tap_hold_modkey_key_t *k = &tap_hold_modkey_keys[i];

        // Match the registered key
        if (keycode == k->keycode) {
            if (record->event.pressed) {
                k->active    = true;
                k->mod_sent  = false;
                k->force_tap = (get_mods() || get_weak_mods());
                k->timer     = timer_read();

                if (k->force_tap) {
                    tap_code(k->tap_key);
                    k->active = false;
                }
            } else {
                if (k->mod_sent) {
                    unregister_mods(MOD_BIT(k->mod));
                } else if (!k->force_tap) {
                    tap_code(k->tap_key);
                }
                k->active = false;
            }
            return false;
        }

        // If this key is active and another key is pressed, register mod immediately
        if (k->active && record->event.pressed && keycode != k->keycode && !k->mod_sent) {
            register_mods(MOD_BIT(k->mod));
            k->mod_sent = true;
        }
    }

    return true;
}

void tap_hold_modkey_matrix_scan(void) {
    for (uint8_t i = 0; i < tap_hold_modkey_count; i++) {
        tap_hold_modkey_key_t *k = &tap_hold_modkey_keys[i];
        if (k->active && !k->mod_sent && !k->force_tap && timer_elapsed(k->timer) > TAPPING_TERM) {
            register_mods(MOD_BIT(k->mod));
            k->mod_sent = true;
        }
    }
}
