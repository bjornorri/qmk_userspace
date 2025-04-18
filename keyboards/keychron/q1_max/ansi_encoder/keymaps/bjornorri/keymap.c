/* Copyright 2023 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "keychron_common.h"
#include "bjornorri.h"


// clang-format off


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYER_0_ANSI_82,
    [1] = LAYER_1_ANSI_82,
    [2] = LAYER_2_ANSI_82,
    [3] = LAYER_3_ANSI_82,
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = LAYER_0_ENCODER,
    [1] = LAYER_1_ENCODER,
    [2] = LAYER_2_ENCODER,
    [3] = LAYER_3_ENCODER
};
#endif // ENCODER_MAP_ENABLE

// clang-format on
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    return get_hold_on_other_key_press_bjornorri(keycode, record);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_keychron_common(keycode, record)) {
        return false;
    }
    return process_record_bjornorri(keycode, record);
}
