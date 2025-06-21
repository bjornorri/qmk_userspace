#pragma once
#include QMK_KEYBOARD_H
#define NUM_LAYERS 4

extern const uint16_t PROGMEM keymaps[NUM_LAYERS][MATRIX_ROWS][MATRIX_COLS];

#if defined(ENCODER_MAP_ENABLE)
extern const uint16_t PROGMEM encoder_map[NUM_LAYERS][NUM_ENCODERS][2];
#endif

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record);
void keyboard_post_init_user(void);
bool process_record_user(uint16_t keycode, keyrecord_t *record);
void matrix_scan_user(void);
