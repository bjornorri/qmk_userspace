#pragma once
#include "quantum.h"

void tap_hold_modkey_register(uint16_t keycode, uint16_t tap_key, uint8_t mod);
bool tap_hold_modkey_process_record(uint16_t keycode, keyrecord_t *record);
void tap_hold_modkey_matrix_scan(void);
