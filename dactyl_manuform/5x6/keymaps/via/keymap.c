#include QMK_KEYBOARD_H
#include "print.h"

#define ALT_F9 MT(MOD_LALT, KC_F9)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_5x6(
    KC_EQUAL,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                   KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,       
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                   KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLS,        
    ALT_F9,         LT(1,KC_A),     LT(2,KC_S),     LT(3,KC_D),     LT(4,KC_F),     KC_G,                   KC_H,           KC_J,           KC_K,           KC_L,           LT(4,KC_SCLN),  KC_QUOTE,       
    KC_LEFT_SHIFT,  KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                   KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_RIGHT_ALT,   
                                    _______,        _______,                                                                                _______,        _______, 
                                                                    KC_SPACE,       KC_LEFT_SHIFT,          KC_BSPC,        KC_ENTER,
                                                                    _______,        KC_LEFT_CTRL,           KC_LEFT_GUI,    _______,
                                                                    _______,        _______,                _______,        _______  
  ),
  [1] = LAYOUT_5x6(
    _______,        _______,        _______,        _______,        _______,        QK_BOOT,                _______,        _______,        _______,        _______,        _______,        _______, 
    _______,        _______,        _______,        KC_ESCAPE,      _______,        _______,                _______,        KC_HOME,        KC_UP,          KC_END,         _______,        _______, 
    _______,        _______,        _______,        KC_LEFT_SHIFT,  KC_LEFT_CTRL,   KC_DELETE,              _______,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       _______,        _______, 
    _______,        _______,        _______,        _______,        _______,        _______,                _______,        _______,        _______,        _______,        _______,        _______, 
                                    _______,        _______,                                                                                _______,        _______, 
                                                                    _______,        _______,                _______,        _______,
                                                                    _______,        _______,                _______,        _______,
                                                                    _______,        _______,                _______,        _______  
  ),
  [2] = LAYOUT_5x6(
    _______,        _______,        _______,        _______,        _______,        _______,                _______,        KC_F10,         KC_F11,         KC_F12,         _______,        _______, 
    _______,        _______,        _______,        _______,        _______,        _______,                _______,        KC_F7,          KC_F8,          KC_F9,          _______,        _______, 
    _______,        _______,        _______,        _______,        _______,        _______,                _______,        KC_F4,          KC_F5,          KC_F6,          _______,        _______,
    _______,        _______,        _______,        _______,        _______,        _______,                _______,        KC_F1,          KC_F2,          KC_F3,          _______,        _______, 
                                    _______,        _______,                                                                                _______,        _______, 
                                                                    _______,        _______,                _______,        _______,
                                                                    _______,        _______,                _______,        _______,
                                                                    _______,        _______,                _______,        _______  
  ),
  [3] = LAYOUT_5x6(
    _______,        _______,        _______,        _______,        _______,        _______,                _______,        _______,        _______,        _______,        _______,        _______, 
    _______,        _______,        _______,        _______,        _______,        _______,                KC_NUM,         KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_NO,          _______, 
    _______,        _______,        _______,        _______,        _______,        _______,                KC_KP_0,        KC_KP_4,        KC_KP_5,        KC_KP_6,        KC_NO,          _______, 
    _______,        _______,        _______,        _______,        _______,        _______,                KC_KP_DOT,      KC_KP_1,        KC_KP_2,        KC_KP_3,        KC_NO,          _______,
                                    _______,        _______,                                                                                _______,        _______, 
                                                                    _______,        _______,                _______,        _______,
                                                                    _______,        _______,                _______,        _______,
                                                                    _______,        _______,                _______,        _______  
  )
};

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=false;
  debug_matrix=false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
// If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, row,col:[%2u, %2u], pressed: %u, time: %5u, int: %u, count: %u", keycode, record->event.key.row, record->event.key.col, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif 
  return true;
}
