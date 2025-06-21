#pragma once
#include "quantum.h"

typedef void (*action_fn_t)(void);

typedef struct {
    uint16_t    keycode;
    action_fn_t on_tap;
    action_fn_t on_double_tap;
    action_fn_t on_triple_tap;
    action_fn_t on_hold;
    bool        active;
    bool        pressed;
    bool        hold_sent;
    uint8_t     tap_count;
    uint16_t    timer;
} tap_dance_key_t;

void tap_dance_register_key(uint16_t keycode, action_fn_t on_tap, action_fn_t on_double_tap, action_fn_t on_triple_tap, action_fn_t on_hold);
bool tap_dance_process_record(uint16_t keycode, keyrecord_t *record);
void tap_dance_matrix_scan(void);
