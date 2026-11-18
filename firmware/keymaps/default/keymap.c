#include QMK_KEYBOARD_H

enum cust_keycodes{
    M_COMMITCRAFT = SAFE_RANGE,
    M_VSCODE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS]
[MATRIX_COLS] = {
    [0] = LAYOUT(
        LCTL(KC_C), LCTL(KC_V), LGUI(LSFT(KC_S)), M_COMMITCRAFT, M_VSCODE, KC_MUTE
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS]
[NUM_DIRECTIONS] = {
    [0] = {ENCODER_CCW_CW(KC_VOLD,  KC_VOLU)},
};
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record){
    switch (keycode){
        case M_COMMITCRAFT:
            if(record -> event.pressed){
                SEND_STRING("commitcraft push --ai" SS_TAP(X_ENT));
            }
            return false;
        case M_VSCODE:
            if(record->event.pressed){
                SEND_STRING(SS_LGUI("r") SS_DELAY(500) "code" SS_TAP(X_ENT));
            }
            return false;
    }
    return true;
}