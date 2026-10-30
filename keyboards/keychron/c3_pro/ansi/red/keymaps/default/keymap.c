#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_tkl_iso(
        KC_ESC,           KC_BRID, KC_BRIU, KC_MCTL, KC_LPAD, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPRV, KC_MPLY, KC_MNXT, KC_M1,   KC_M2,   KC_BSPC,   KC_INS,  KC_HOME, KC_PGUP,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_JYEN, KC_BSLS,   KC_DEL,  KC_END,  KC_PGDN,
        KC_TAB,  KC_Z,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,                     KC_ENT,
        KC_CAPS, KC_A,    KC_S,    KC_D,    M0,      KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,
        KC_LCTL, KC_LOPT, KC_LCMD,                   KC_SPC,                    KC_RCMD, MO(MAC_FN),KC_RCTL,          KC_LEFT, KC_DOWN, KC_RGHT
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case M0:
            if (record->event.pressed) {
                register_code(KC_G);        // Hold G down
                wait_ms(80);                // Wait 80ms
                register_code(KC_MS_BTN1);   // Hold Left Mouse Button down
            } else {
                unregister_code(KC_MS_BTN1); // Release Left Mouse Button
                unregister_code(KC_G);       // Release G
            }
            return false;
    }
    return true;
}

