    /*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#ifdef HAPTIC_ENABLE
#include "drivers/haptic/DRV2605L.h"
#endif
// Layers
#define _BASE 0
#define _RAISE 1
#define _LOWER 2
#define _TRI 3 
#define _GAME 4

enum unicode_names {
    ALLAH,
    SKULL,
    EACGMA,
    EACGMI,
    EACAMA,
    EACAMI,
    AACMA,
    AACMI,
    UACMA,
    UACMI,
    CCEDMA,
    CCEDMI,
    SHARPS,
    AUMLMA,
    AUMLMI,
    OUMLMA,
    OUMLMI,
    UUMLMA,
    UUMLMI
    
};

const uint32_t unicode_map[] PROGMEM = {
    [ALLAH]  = 0xFDF2,  // ﷲ
    [SKULL] = 0x1F480,  //💀
    [EACGMA]  = 0x00C9, // É
    [EACGMI]  = 0x00E9,  // é
    [EACAMA] = 0x00C8,  // È
    [EACAMI]  = 0x00E8, // è
    [AACMA]  = 0x00C0,  // À
    [AACMI] = 0x00E0,  // à
    [UACMA]  = 0x00D9, // Ù
    [UACMI]  = 0x00F9,  // ù
    [CCEDMA] = 0x00C7,  // Ç
    [CCEDMI]  = 0x00E7, // ç
    [SHARPS] = 0x00DF,  // ß	
    [AUMLMA]  = 0x00C4, // Ä
    [AUMLMI]  = 0x00E4,  // ä
    [OUMLMA] = 0x00D6,  // Ö
    [OUMLMI]  = 0x00F6, // ö	
    [UUMLMA] = 0x00DC,  // Ü
    [UUMLMI]  = 0x00FC, // ü
};

enum custom_keycodes {
    DRAG_SCROLL = SAFE_RANGE,
};

bool set_scrolling = false;

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (set_scrolling) {
        mouse_report.h = mouse_report.x;
        mouse_report.v = mouse_report.y;
        mouse_report.x = 0;
        mouse_report.y = 0;
    }
    return mouse_report;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode == DRAG_SCROLL && record->event.pressed) {
        set_scrolling = !set_scrolling;
    }
    return true;

    
}
    
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(1), LALT_T(KC_SPC),    KC_ENT,   MO(2), KC_MUTE
                                      //`--------------------------'  `--------------------------'

  ),

    [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, KC_BTN3, KC_BTN1, KC_BTN2, KC_WH_U,                      KC_PSCR,  KC_UP,  KC_DEL, KC_MPRV, KC_MPLY, KC_MNXT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, KC_BTN4, KC_BTN5, DRAG_SCROLL, KC_WH_D,                  KC_LEFT, KC_DOWN, KC_RIGHT, KC_MUTE, KC_VOLD, KC_VOLU,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,LALT_T(KC_SPC),   KC_ENT,   MO(3), KC_MPLY
                                      //`--------------------------'  `--------------------------'
  ),

    [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_F11,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, KC_F1,     KC_F2, KC_F3,    KC_F4,  KC_F5,                        KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, KC_F6,     KC_F7, KC_F8,    KC_F9,  KC_F10,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,  MO(3), LALT_T(KC_SPC),   KC_ENT, _______, KC_MPLY
                                      //`--------------------------'  `--------------------------'
  ),

    [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, X(ALLAH), X(SKULL), XXXXXXX,  XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XP(EACGMI, EACGMA), XP(EACAMI, EACAMA), XP(AACMI, AACMA), XP(UACMI, UACMA), XP(CCEDMI, CCEDMA),                      XP(UUMLMI, UUMLMA),  XP(OUMLMI, OUMLMA), XP(AUMLMI, AUMLMA), X(SHARPS), XXXXXXX,  XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TG(4),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,LALT_T(KC_SPC),     KC_ENT, _______, KC_PWR
                                      //`--------------------------'  `--------------------------'
  ),

    [4] = LAYOUT_split_3x6_3(
   //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, KC_LALT, KC_SPC,    KC_ENT,   TG(4), KC_MUTE
                                      //`--------------------------'  `--------------------------'
  )
};

#ifdef PIMORONI_TRACKBALL_ENABLE
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case 1:
        pimoroni_trackball_set_rgbw(RGB_CYAN, 0x00);
        DRV_pulse(7);
        break;
    case 2:
        pimoroni_trackball_set_rgbw(RGB_MAGENTA, 0x88);
        DRV_pulse(7);
        break;
    case 3:
        pimoroni_trackball_set_rgbw(RGB_YELLOW, 0x00);
        DRV_pulse(14);
        break;
    case 4:
        pimoroni_trackball_set_rgbw(RGB_ORANGE, 0x00);
        DRV_pulse(119);
        break;
    default:
        pimoroni_trackball_set_rgbw(RGB_WHITE, 0x00);
        DRV_pulse(24);
        break;
    }
    return state;
}
#endif

void pointing_device_init_user(void) {
    set_auto_mouse_layer(1); // only required if AUTO_MOUSE_DEFAULT_LAYER is not set to index of <mouse_layer>
    set_auto_mouse_enable(true);         // always required before the auto mouse feature will work
}

#ifdef OLED_ENABLE

// Rotate OLED
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270; 
}
// Draw to OLED
bool oled_task_user() {
    // Set cursor position
    oled_set_cursor(0, 1);

    // Define image array
    static const char image [] PROGMEM = {
       0xfe, 0xfe, 0xfc, 0xf8, 0xf0, 0xf0, 0xe0, 0xc0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0xc0, 0xc0, 0xc0, 0xe0, 
0x07, 0x0f, 0x0f, 0x1f, 0x3f, 0x3f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfc, 0xf8, 0xf8, 0xf8, 
0xf8, 0xfc, 0xfc, 0xfe, 0xfe, 0xfe, 0xff, 0x7f, 0x7f, 0x7f, 0x3f, 0x3f, 0x3f, 0x1f, 0x1f, 0x1f, 
0xf0, 0xf8, 0xf8, 0xfc, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x03, 
0x03, 0xff, 0xff, 0xf9, 0xf1, 0xf0, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x07, 0x0f, 0x1f, 0x3f, 0x3f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 
0xe0, 0xe7, 0xcf, 0xdf, 0xdf, 0x9f, 0x9f, 0x3f, 0x3f, 0x7f, 0x7e, 0x7c, 0xf8, 0xf0, 0xe0, 0xc0, 
0xc0, 0xc0, 0xe0, 0xe0, 0xf0, 0xf8, 0xf8, 0xfd, 0xf9, 0xfb, 0xfb, 0xf3, 0xf7, 0xf7, 0xe7, 0xef, 
0xef, 0xdf, 0xdf, 0x9f, 0xbf, 0x3f, 0x3f, 0x7f, 0x7f, 0xff, 0xfe, 0xfe, 0xfe, 0xfc, 0xfc, 0xfd, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 
0x1f, 0x9f, 0x9f, 0xbf, 0x3f, 0x3f, 0x7e, 0x7e, 0xfc, 0xf8, 0xf8, 0xf0, 0xe1, 0xe1, 0xc1, 0x83, 
0x3f, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 
0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xfc, 0xfc, 0xfd, 0xf9, 0xf9, 0xfb, 0xf3, 
0xff, 0xfe, 0xfe, 0xfc, 0xfd, 0xf9, 0xf3, 0xf3, 0xe7, 0xcf, 0xcf, 0x9f, 0xbf, 0x3f, 0x7f, 0xff, 
0xff, 0xfe, 0xf8, 0xf1, 0xe3, 0xcf, 0x1f, 0x3f, 0x7f, 0xff, 0x7f, 0x3f, 0x3f, 0x9f, 0x9f, 0xcf, 
0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x80, 
0x81, 0xc3, 0xc7, 0xe7, 0xff, 0xff, 0xff, 0xfe, 0xfc, 0xfc, 0xfe, 0xce, 0x8f, 0x07, 0x03, 0x01, 
0xfe, 0xfc, 0xfc, 0xf9, 0xfb, 0xf3, 0xe7, 0xe7, 0xcf, 0x9f, 0x9f, 0x3f, 0x7f, 0x7f, 0xff, 0x7f, 
0x3f, 0x1f, 0x8f, 0xc7, 0xe7, 0xf3, 0xf9, 0xfc, 0xfc, 0xf9, 0xf3, 0xe7, 0xc7, 0x8e, 0x1c, 0x38, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfc, 0x00, 
0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x7f, 0x7f, 0x3f, 0x3f, 0x3f, 0x9f, 
0xf3, 0xf3, 0xe7, 0xe7, 0xcf, 0xdf, 0x9f, 0x3f, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 
0xf0, 0xf3, 0xf3, 0xf9, 0xf9, 0xf9, 0xfc, 0x7c, 0x7c, 0x3e, 0x1e, 0x1e, 0x0f, 0x87, 0x87, 0x83, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfc, 0xfc, 0xf9, 0xf3, 0xe3, 0x07, 
0x07, 0xef, 0xff, 0xfb, 0xf9, 0xfd, 0xfc, 0xfc, 0xfe, 0xfe, 0x7e, 0x3f, 0x1f, 0x0f, 0x07, 0x03, 
0x0f, 0x0f, 0x1f, 0x1f, 0x3f, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 
0xe0, 0xff, 0xff, 0xdf, 0x9f, 0x8f, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0xf0, 0xf0, 0xf8, 0xfc, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x3f, 0x3f, 0x1f, 0x0f, 0x1f, 
0x1f, 0x1f, 0x3f, 0x3f, 0x3f, 0x7f, 0x7f, 0x7f, 0xff, 0xfe, 0xfe, 0xfe, 0xfc, 0xfc, 0xfc, 0xf8, 
0x7f, 0x3f, 0x1f, 0x1f, 0x0f, 0x07, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x03, 0x03, 

    };

    // Draw image to Oled
    oled_write_raw_P(image, sizeof(image));

    return false;
}
#endif 

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [_RAISE] =  { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN)  },
    [_LOWER] =  { ENCODER_CCW_CW(KC_MPRV, KC_MNXT)  },
    [_TRI] = { ENCODER_CCW_CW(KC_BRID, KC_BRIU) },
    [_GAME] =  { ENCODER_CCW_CW(KC_MPRV, KC_MNXT)  },
};
#endif
