#include QMK_KEYBOARD_H
#include "print.h"

#define ALT_F9 MT(MOD_LALT, KC_F9)
#define LT1_A LT(1,KC_A)
#define LT2_S LT(2,KC_S)
#define LT3_D LT(3,KC_D)
#define LT4_F LT(4,KC_F)
#define LT4_F LT(4,KC_F)
#define LT4_CLN LT(4,KC_SCLN)

#define _MAIN     0
#define _ARROWS   1
#define _F_KEYS   2
#define _NUMPAD   3
#define _SYMBOLS  4
#define _GAME     5

const rgblight_segment_t PROGMEM layer_rgb_0[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_RED}     // Layer 0: Red
);
const rgblight_segment_t PROGMEM layer_rgb_1[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_GREEN}   // Layer 1: Green
);
const rgblight_segment_t PROGMEM layer_rgb_2[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_BLUE}    // Layer 2: Blue
);
const rgblight_segment_t PROGMEM layer_rgb_3[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_PURPLE}  // Layer 3: Purple
);
const rgblight_segment_t PROGMEM layer_rgb_4[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_YELLOW}  // Layer 4: Yellow
);
const rgblight_segment_t PROGMEM layer_rgb_5[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_ORANGE}  // Layer 5: Orange
);

// Now define the layers array pointing to each individual layer
const rgblight_segment_t* const PROGMEM layer_rgb[] = {
    layer_rgb_0,
    layer_rgb_1,
    layer_rgb_2,
    layer_rgb_3,
    layer_rgb_4,
    layer_rgb_5
};


layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t layer = get_highest_layer(state);

    // Activate the RGB lighting for the current layer
    rgblight_set_layer_state(0, layer == _MAIN);
    rgblight_set_layer_state(1, layer == _ARROWS);
    rgblight_set_layer_state(2, layer == _F_KEYS);
    rgblight_set_layer_state(3, layer == _NUMPAD);
    rgblight_set_layer_state(4, layer == _SYMBOLS);
    rgblight_set_layer_state(5, layer == _GAME);

    return state;
}

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  rgblight_layers = layer_rgb;
  
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // [_MAIN] = LAYOUT_ergodox(
  //   // left hand
  //   KC_EQL,          KC_1,        KC_2,          KC_3,    KC_4,    KC_5,    KC_LEFT,              KC_RGHT,      KC_6,    KC_7,    KC_8,    KC_9,              KC_0,           KC_MINS,
  //   KC_DEL,          KC_Q,        KC_W,          KC_E,    KC_R,    KC_T,    TG(SYMB),             TG(SYMB),     KC_Y,    KC_U,    KC_I,    KC_O,              KC_P,           KC_BSLS,
  //   KC_BSPC,         KC_A,        KC_S,          KC_D,    KC_F,    KC_G,                                        KC_H,    KC_J,    KC_K,    KC_L,    LT(MDIA, KC_SCLN), GUI_T(KC_QUOT),
  //   KC_LSFT,         CTL_T(KC_Z), KC_X,          KC_C,    KC_V,    KC_B,    ALL_T(KC_NO),                  MEH_T(KC_NO), KC_N,    KC_M,    KC_COMM, KC_DOT,           CTL_T(KC_SLSH), KC_RSFT,
  //   LT(SYMB,KC_GRV), KC_QUOT,     LALT(KC_LSFT), KC_LEFT, KC_RGHT,                                              KC_UP,   KC_DOWN, KC_LBRC, KC_RBRC, TT(SYMB),
  //                                                           ALT_T(KC_APP), KC_LGUI,                KC_LALT, CTL_T(KC_ESC),
  //                                                                           KC_HOME,                 KC_PGUP,
  //                                                         KC_SPC, KC_BSPC, KC_END,                  KC_PGDN, KC_TAB, KC_ENT
  // ),

  [_MAIN] = LAYOUT_7x5(
    KC_EQUAL,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,       _______,                    _______,        KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,       
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,       _______,                    _______,        KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLS,        
    ALT_F9,         LT1_A,          LT2_S,          LT3_D,          LT4_F,          KC_G,       _______,                    _______,        KC_H,           KC_J,           KC_K,           KC_L,           LT4_CLN,        KC_QUOTE,       
    KC_LSFT,        KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                                   KC_N,           KC_M,           KC_COMM,        KC_DOT,         KC_SLASH,       KC_RALT,   
    _______,        _______,        _______,        _______,        _______,                                                                                _______,        _______,        _______,        _______,        _______,   
                                                                    KC_SPACE,       KC_LSFT,                                                KC_BSPC,        KC_ENTER,
                                                                    _______,        KC_LCTL,                                                KC_LGUI,        _______,
                                                                    _______,        _______,                                                _______,        _______  
  ),
  // [_ARROWS] = LAYOUT_5x6(
  //   _______,        _______,        _______,        _______,        _______,        QK_BOOT,                _______,        _______,        _______,        _______,        _______,        _______, 
  //   _______,        _______,        _______,        KC_ESC,         _______,        _______,                _______,        KC_HOME,        KC_UP,          KC_END,         _______,        _______, 
  //   _______,        _______,        _______,        KC_LSFT,        KC_LCTL,        KC_DEL,                 _______,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       _______,        _______, 
  //   _______,        _______,        _______,        _______,        _______,        _______,                _______,        _______,        _______,        _______,        _______,        _______, 
  //                                   _______,        _______,                                                                                _______,        _______, 
  //                                                                   _______,        _______,                _______,        _______,
  //                                                                   _______,        _______,                _______,        _______,
  //                                                                   _______,        _______,                _______,        _______  
  // ),
  // [_F_KEYS] = LAYOUT_5x6(
  //   _______,        _______,        _______,        _______,        _______,        _______,                _______,        KC_F10,         KC_F11,         KC_F12,         _______,        _______, 
  //   _______,        _______,        _______,        _______,        _______,        _______,                _______,        KC_F7,          KC_F8,          KC_F9,          _______,        _______, 
  //   _______,        _______,        _______,        _______,        _______,        _______,                _______,        KC_F4,          KC_F5,          KC_F6,          _______,        _______,
  //   _______,        _______,        _______,        _______,        _______,        _______,                _______,        KC_F1,          KC_F2,          KC_F3,          _______,        _______, 
  //                                   _______,        _______,                                                                                _______,        _______, 
  //                                                                   _______,        _______,                _______,        _______,
  //                                                                   _______,        _______,                _______,        _______,
  //                                                                   _______,        _______,                _______,        _______  
  // ),
  // [_NUMPAD] = LAYOUT_5x6(
  //   _______,        _______,        _______,        _______,        _______,        _______,                _______,        _______,        _______,        _______,        _______,        _______, 
  //   _______,        _______,        _______,        _______,        _______,        _______,                KC_NUM,         KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_NO,          _______, 
  //   _______,        _______,        _______,        _______,        _______,        _______,                KC_KP_0,        KC_KP_4,        KC_KP_5,        KC_KP_6,        KC_NO,          _______, 
  //   _______,        _______,        _______,        _______,        _______,        _______,                KC_KP_DOT,      KC_KP_1,        KC_KP_2,        KC_KP_3,        KC_NO,          _______,
  //                                   _______,        _______,                                                                                _______,        _______, 
  //                                                                   _______,        _______,                _______,        _______,
  //                                                                   _______,        _______,                _______,        _______,
  //                                                                   _______,        _______,                _______,        _______  
  // ),
  // [_SYMBOLS] = LAYOUT_5x6(
  //   _______,        _______,        _______,        _______,        _______,        _______,                _______,        _______,        _______,        _______,        _______,        _______,
  //   _______,        KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,                KC_TILD,        KC_LCBR,        KC_RCBR,        _______,        _______,        _______,
  //   _______,        KC_CIRC,        KC_AMPR,        KC_ASTR,        _______,        _______,                KC_GRV,         KC_LPRN,        KC_RPRN,        KC_UNDS,        _______,        _______,
  //   _______,        _______,        _______,        _______,        _______,        _______,                _______,        KC_LBRC,        KC_RBRC,        _______,        _______,        _______,
  //                                   _______,        _______,                                                                                _______,        _______, 
  //                                                                   _______,        _______,                _______,        _______,
  //                                                                   _______,        _______,                _______,        _______,
  //                                                                   _______,        _______,                _______,        _______  
  // ),
  // [_GAME] = LAYOUT_5x6(
  //   KC_ESC,         _______,        _______,        _______,        _______,        _______,                _______,        _______,        _______,        _______,        _______,        _______,  
  //   _______,        _______,        _______,        _______,        _______,        _______,                _______,        _______,        _______,        _______,        _______,        _______,  
  //   KC_LCTL,        KC_A,           KC_S,           KC_D,           KC_F,           _______,                _______,        _______,        _______,        _______,        KC_SCLN,        _______, 
  //   KC_LSFT,        _______,        _______,        _______,        _______,        _______,                _______,        _______,        _______,        _______,        _______,        _______, 
  //                                   _______,        _______,                                                                                _______,        _______, 
  //                                                                   _______,        _______,                _______,        _______,
  //                                                                   _______,        _______,                _______,        _______,
  //                                                                   _______,        _______,                _______,        _______  
    
  // )


  
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
// If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, row,col:[%2u, %2u], pressed: %u, time: %5u, int: %u, count: %u", keycode, record->event.key.row, record->event.key.col, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif 
  return true;
}

