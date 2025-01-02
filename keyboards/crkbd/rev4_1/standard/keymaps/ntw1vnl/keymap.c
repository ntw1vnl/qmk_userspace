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
#define LAYER_BASE_COLOR     HSV_OFF
#define LAYER_NAV_COLOR      HSV_AZURE
#define LAYER_NUM_COLOR      HSV_RED
#define LAYER_SYM_COLOR      HSV_GREEN
#define LAYER_FUN_COLOR      HSV_ORANGE
#define LAYER_CONTROL_COLOR  HSV_GOLD
// clang-format on

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
