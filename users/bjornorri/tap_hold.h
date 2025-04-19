#pragma once
#include "quantum.h"

typedef void (*action_fn_t)(void);

typedef struct {
    uint16_t    keycode;
    action_fn_t on_tap;
    action_fn_t on_hold;
    bool        active;
    bool        hold_sent;
    uint16_t    timer;
} tap_hold_key_t;

void tap_hold_register_key(uint16_t keycode, action_fn_t on_tap, action_fn_t on_hold);
bool tap_hold_process_record(uint16_t keycode, keyrecord_t *record);
void tap_hold_matrix_scan(void);