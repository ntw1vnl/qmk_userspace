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

// Left-hand home row mods
#define GUI_A LGUI_T(KC_A)
#define ALT_S LALT_T(KC_S)
#define SFT_D LSFT_T(KC_D)
#define CTL_F LCTL_T(KC_F)

// Right-hand home row mods
#define CTL_J RCTL_T(KC_J)
#define SFT_K RSFT_T(KC_K)
#define ALT_L LALT_T(KC_L)
#define GUI_SCLN RGUI_T(KC_SCLN)

// Define layers
enum Layer { LAYER_BASE, LAYER_NAV, LAYER_NUM, LAYER_SYM, LAYER_FUN, LAYER_CONTROL };

// Left-hand thumb cluster
#define LP_THMB LT(LAYER_NAV, KC_SPC) // Left Primary Thumb
#define LS_THMB LT(LAYER_SYM, KC_TAB) // Left Secondary Thumb
// #define LT_THMB LT(LAYER_BASE, KC_ESC) // Left Tertiary Thumb

// Right-hand thumb cluster
#define RP_THMB LT(LAYER_NUM, KC_BSPC) // Right Primary Thumb
#define RS_THMB LT(LAYER_FUN, KC_ENT)  // Right Secondary Thumb
// #define RT_THMB LT(LAYER_BASE, KC_DEL) // Right Tertiary Thumb

const uint16_t PROGMEM control_layer_combo[] = {KC_ESC, KC_DEL, COMBO_END};
const uint16_t PROGMEM gui_thumb_combo[]     = {LP_THMB, RP_THMB, COMBO_END};
const uint16_t PROGMEM jk_esc_combo[]        = {CTL_J, SFT_K, COMBO_END};

combo_t key_combos[] = {COMBO(control_layer_combo, MO(LAYER_CONTROL)), COMBO(gui_thumb_combo, KC_LGUI), COMBO(jk_esc_combo, KC_ESC)};

// clang-format off
/*
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYER_BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSLS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,   GUI_A,   ALT_S,   SFT_D,   CTL_F,    KC_G,                         KC_H,   CTL_J,   SFT_K,   ALT_L,GUI_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_ESC, LP_THMB, LS_THMB,    RS_THMB, RP_THMB,  KC_DEL
                                      //`--------------------------'  `--------------------------'

  ),

    [LAYER_NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX,  KC_CUT, KC_COPY, KC_PSTE, XXXXXXX,                      KC_HOME, KC_PGDN, KC_PGUP,  KC_END,  KC_INS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, _______, XXXXXXX,     KC_ENT, KC_BSPC, KC_DEL
                                      //`--------------------------'  `--------------------------'
  ),

    [LAYER_NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, KC_PSLS,    KC_9,    KC_8,    KC_7, KC_PMNS,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_PAST,    KC_6,    KC_5,    KC_4, KC_PEQL,                      XXXXXXX, KC_RCTL, KC_RSFT, KC_RALT, KC_RGUI, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_PCMM,    KC_3,    KC_2,    KC_1, KC_PPLS,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_PDOT,    KC_0, KC_PENT,    XXXXXXX, _______, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

    [LAYER_SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_MINS,  KC_EQL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, XXXXXXX,                        KC_AT, KC_LBRC, KC_RBRC, KC_AMPR, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX,  KC_CUT, KC_COPY, KC_PSTE, XXXXXXX,                      KC_EXLM, KC_LPRN, KC_RPRN, KC_ASTR, KC_SLSH, XXXXXXX,

                                          XXXXXXX, XXXXXXX, _______,     KC_ENT, KC_BSPC, KC_DEL
                                      //`--------------------------'  `--------------------------'
  ),

    [LAYER_FUN] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,  KC_F12,   KC_F9,   KC_F8,   KC_F7, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,  KC_F11,   KC_F6,   KC_F5,   KC_F4, XXXXXXX,                      XXXXXXX, KC_RCTL, KC_RSFT, KC_RALT, KC_RGUI, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,  KC_F10,   KC_F3,   KC_F2,   KC_F1, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    _______, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

    [LAYER_CONTROL] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RM_TOGG, RM_HUEU, RM_SATU, RM_VALU, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RM_NEXT, RM_HUED, RM_SATD, RM_VALD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, _______
                                      //`--------------------------'  `--------------------------'
  )
};
// clang-format on
*/

// bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
//     for (uint8_t i = led_min; i < led_max; i++) {
//         switch(get_highest_layer(layer_state|default_layer_state)) {
//             case: LAYER_BASE:
//                 rgb_matrix_set_color(i, RGB_BLUE);
//                 break;
//             case: LAYER_NAV:
//                 rgb_matrix_set_color(i, RGB_BLUE);
//                 break;
//             case: LAYER_NUM:
//                 rgb_matrix_set_color(i, RGB_BLUE);
//                 break;
//             case: LAYER_SYM:
//                 rgb_matrix_set_color(i, RGB_BLUE);
//                 break;
//             case: LAYER_FUN:
//                 rgb_matrix_set_color(i, RGB_BLUE);
//                 break;
//             case: LAYER_CONTROL:
//                 rgb_matrix_set_color(i, RGB_BLUE);
//                 break;
//             default:
//                 break;
//         }
//     }
//     return false;
// }

// clang-format off
#define LAYER_BASE_COLOR     HSV_OFF
#define LAYER_NAV_COLOR      HSV_AZURE
#define LAYER_NUM_COLOR      HSV_RED
#define LAYER_SYM_COLOR      HSV_GREEN
#define LAYER_FUN_COLOR      HSV_ORANGE
#define LAYER_CONTROL_COLOR  HSV_GOLD
// clang-format on

// bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case GUI_A:
//         case ALT_S:
//         case ALT_L:
//         case GUI_SCLN:
//             return true;
//         default:
//             return false;
//     }
// }

hsv_t get_layer_color(uint8_t layer) {
    switch (layer) {
        case LAYER_BASE:
            return (hsv_t){LAYER_BASE_COLOR};
        case LAYER_NAV:
            return (hsv_t){LAYER_NAV_COLOR};
        case LAYER_NUM:
            return (hsv_t){LAYER_NUM_COLOR};
        case LAYER_SYM:
            return (hsv_t){LAYER_SYM_COLOR};
        case LAYER_FUN:
            return (hsv_t){LAYER_FUN_COLOR};
        case LAYER_CONTROL:
            return (hsv_t){LAYER_CONTROL_COLOR};
        default:
            break;
    }
    return (hsv_t){HSV_OFF};
}

void colorize_used_keys(rgb_t color_rgb, uint8_t layer, uint8_t led_min, uint8_t led_max) {
    for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
        for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
            uint8_t index = g_led_config.matrix_co[row][col];
            if (index >= led_min && index < led_max && index != NO_LED && keymap_key_to_keycode(layer, (keypos_t){col, row}) > KC_TRNS) {
                rgb_matrix_set_color(index, color_rgb.r, color_rgb.g, color_rgb.b);
            }
        }
    }
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    uint8_t layer = get_highest_layer(layer_state | default_layer_state);
    hsv_t   hsv   = get_layer_color(layer);
    rgb_t   rgb   = hsv_to_rgb(hsv);
    colorize_used_keys(rgb, layer, led_min, led_max);
    return false;
}

void keyboard_post_init_user(void) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(HSV_OFF);
}

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] =
        {
            ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
            ENCODER_CCW_CW(KC_MPRV, KC_MNXT),
            ENCODER_CCW_CW(RM_VALD, RM_VALU),
            ENCODER_CCW_CW(KC_RGHT, KC_LEFT),
        },
    [1] =
        {
            ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
            ENCODER_CCW_CW(KC_MPRV, KC_MNXT),
            ENCODER_CCW_CW(RM_VALD, RM_VALU),
            ENCODER_CCW_CW(KC_RGHT, KC_LEFT),
        },
    [2] =
        {
            ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
            ENCODER_CCW_CW(KC_MPRV, KC_MNXT),
            ENCODER_CCW_CW(RM_VALD, RM_VALU),
            ENCODER_CCW_CW(KC_RGHT, KC_LEFT),
        },
    [3] =
        {
            ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
            ENCODER_CCW_CW(KC_MPRV, KC_MNXT),
            ENCODER_CCW_CW(RM_VALD, RM_VALU),
            ENCODER_CCW_CW(KC_RGHT, KC_LEFT),
        },
};
#endif
