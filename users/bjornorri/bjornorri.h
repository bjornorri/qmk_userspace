#pragma once

#define MY_ESC C(G(KC_Q))
#define MY_ESC C(G(KC_Q))
#define MY_CAPS LT(1, KC_ESC)
#define MY_ENT MT(MOD_LSFT, KC_ENT)
#define MY_SCLN MT(MOD_HYPR, KC_SCLN)
#define MY_SLSH MT(MOD_RCTL, KC_SLSH)
#define MY_TAB MT(MOD_LCTL, KC_TAB)
#define MY_TRGR G(KC_BSLS)
#define MY_LBRC LSG(KC_LBRC)
#define MY_RBRC LSG(KC_RBRC)
#define MY_BSLS LSG(KC_T)

// Hyper modified keys.
#define HP_ENT HYPR(KC_ENT)
#define HP_SPC HYPR(KC_SPC)
#define HP_LEFT HYPR(KC_LEFT)
#define HP_RGHT HYPR(KC_RGHT)
#define HP_UP HYPR(KC_UP)
#define HP_DOWN HYPR(KC_DOWN)
#define HP_M HYPR(KC_M)

#define LAYER_0_ANSI_82 LAYOUT_ansi_82( \
    MY_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_MPLY,            KC_MUTE, \
    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP, \
    MY_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN, \
    MY_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     MY_SCLN,  KC_QUOT,            MY_ENT,             MY_TRGR, \
    KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   MY_SLSH,            KC_RSFT,  KC_UP, \
    KC_LCTL,  KC_LOPTN, KC_LCMMD,                               KC_SPC,                                 KC_RCMMD,KC_ROPTN,    MO(3),  KC_LEFT,  KC_DOWN,  KC_RGHT \
)


#define LAYER_1_ANSI_82 LAYOUT_ansi_82( \
    KC_CAPS,  KC_BRID,  KC_BRIU,  KC_MCTL,  KC_LPAD,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_TRNS,            KC_TRNS, \
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS, \
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  MY_LBRC,  MY_RBRC,  MY_BSLS,            KC_TRNS, \
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_TRNS,  KC_TRNS,            HP_ENT,             KC_TRNS, \
    KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  HP_M,     KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  HP_UP, \
    KC_TRNS,  KC_TRNS,  KC_TRNS,                                HP_SPC,                                 KC_TRNS,  KC_TRNS,  KC_TRNS,  HP_LEFT,  HP_DOWN,  HP_RGHT \
) 

#define LAYER_2_ANSI_82 LAYOUT_ansi_82( \
    KC_TRNS,  KC_BRID,  KC_BRIU,  KC_MCTL,  KC_LPAD,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_TRNS,            KC_TRNS, \
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS, \
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS, \
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,            KC_TRNS, \
    KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_TRNS, \
    KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                                KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS \
)

#define LAYER_3_ANSI_82 LAYOUT_ansi_82( \
    KC_TRNS,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_TRNS,            RGB_TOG, \
    KC_TRNS,    BT_HST1,  BT_HST2,  BT_HST3,  KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS, \
    RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS, \
    KC_TRNS,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,            KC_END, \
    KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  BAT_LVL,  NK_TOGG,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_TRNS, \
    KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                                KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS \
)

#define LAYER_0_ENCODER {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)}
#define LAYER_1_ENCODER {ENCODER_CCW_CW(KC_BRID, KC_BRIU)}
#define LAYER_2_ENCODER {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)}
#define LAYER_3_ENCODER {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)}

bool get_hold_on_other_key_press_bjornorri(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MY_CAPS:
            return true;
        case MY_ENT:
            return true;
        case MY_TAB:
            return true;
        case MY_SCLN:
            return true;
        case MY_SLSH:
            return true;
    }
    return false;
}

bool process_record_bjornorri(uint16_t keycode, keyrecord_t *record) {
    return true;
}
