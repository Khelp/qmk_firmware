#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ortho_4x4( /* Base */
    KC_P7,    KC_P8,    KC_P9,    KC_PMNS,
    KC_P4,    KC_P5,    KC_P6,    KC_PPLS,
    KC_P1,    KC_P2,    KC_P3,    KC_PSLS,
    MO(2),    MO(1),    DF(3),  KC_PENT
  ),

  [1] = LAYOUT_ortho_4x4( /* Fn Layer 1*/
    RGB_TOG,   RGB_HUI,    RGB_SAI,    RGB_VAI,
    RGB_MOD,   RGB_HUD,    RGB_SAD,    RGB_VAD,
    RGB_SPD,   RGB_SPI,    KC_TRNS,    KC_TRNS,
    KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_PENT
  ),
  
   [2] = LAYOUT_ortho_4x4( /* Fn Layer 2*/
    RGB_TOG,   QK_MACRO_9,    QK_MACRO_10,    RGB_VAI,
    QK_MACRO_5,   QK_MACRO_6,    QK_MACRO_7,    QK_MACRO_3,
    QK_MACRO_1,   QK_MACRO_2,    QK_MACRO_3,    QK_MACRO_4,
    KC_TRNS,   QK_MACRO_0,    KC_TRNS,    QK_MACRO_11
  ),
  
   [3] = LAYOUT_ortho_4x4( /* Fn Layer 3*/
    MI_OCTD,   DF(0),    MI_OC1,    MI_OCTU,
    MI_As1,   MI_B1,    MI_C2,    MI_Cs2,
    MI_E1,   MI_F1,    MI_Fs1,    MI_A1,
    MI_C1,   MI_Cs1,    MI_D1,    MI_Ds1
  ),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] =   { ENCODER_CCW_CW(KC_PGUP, KC_PGDN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [1] =  { ENCODER_CCW_CW(RGB_HUD, RGB_HUI), ENCODER_CCW_CW(RGB_SAD, RGB_SAI)},
    [2] =  { ENCODER_CCW_CW(KC_PGUP, KC_PGDN), ENCODER_CCW_CW(KC_LEFT, KC_RIGHT) },
    [3] = { ENCODER_CCW_CW(MI_MODU, MI_MODD), ENCODER_CCW_CW(MI_BNDU, MI_BNDD) },
};
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case QK_MACRO_0:
                SEND_STRING("No Data");
                return false;
            case QK_MACRO_1:
                SEND_STRING("No Data");
                return false;
            case QK_MACRO_2:
                SEND_STRING("No Data");
                return false;
            case QK_MACRO_3:
                SEND_STRING("No Data");
                return false;
            case QK_MACRO_4:
                SEND_STRING("No Data");
                return false;
            case QK_MACRO_5:
                SEND_STRING("No Data");
                return false;
            case QK_MACRO_6:
                SEND_STRING("No Data");
                return false;
            case QK_MACRO_7:
                SEND_STRING("No Data");
                return false;
            case QK_MACRO_8:
                SEND_STRING("No Data");
                return false;
            case QK_MACRO_9:
                SEND_STRING("No Data");
                return false;
            case QK_MACRO_10:
                SEND_STRING("No Data");
                return false;
            case QK_MACRO_11:
                SEND_STRING("No Data");
                return false;
        }
    }
    return true;
};
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    for (uint8_t i = led_min; i < led_max; i++) {
        switch(get_highest_layer(layer_state|default_layer_state)) {
            case 0:
                
                break;
            case 1:
                
                break;
			 case 2:
                rgb_matrix_sethsv(255, 255, 120);
                break;	
			case 3:
                rgb_matrix_sethsv(127, 255, 120);
                break;
            default:
                break;
        }
    }
    return false;
}

