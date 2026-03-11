/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

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

// Initial velocity value (avoid using 127 since it is used as a special number in some sound sources.)
#define MIDI_INITIAL_VELOCITY 117

#include QMK_KEYBOARD_H

#include "quantum.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default (VIA)
  [0] = LAYOUT_universal(
    TO(4)          , KC_Q          , KC_W          , KC_E          , KC_R          , KC_T          ,                            KC_Y          , KC_U          , KC_I          , KC_O          , KC_P            , KC_BSLS        ,
    LCTL_T(KC_ESC) , LSA_T(KC_A)   , LSG_T(KC_S)   , LALT_T(KC_D)  , LGUI_T(KC_F)  , LCTL_T(KC_G)  ,                            RCTL_T(KC_H)  , RGUI_T(KC_J)  , RALT_T(KC_K)  , RSG_T(KC_L)    , LT(1, KC_SCLN)  , LT(3, KC_MINS) ,
    KC_LGUI        , LSFT_T(KC_Z)  , KC_X          , KC_C          , KC_V          , KC_B          ,                            KC_N          , KC_M          , KC_COMM       , KC_DOT        , RSFT_T(KC_SLSH) , KC_RGUI        ,
                    LALT_T(KC_LNG2), LSFT_T(KC_TAB), LT(1, KC_ENT) , LT(2, KC_SPC) , LT(3, KC_BSPC),                 KC_BSPC, KC_ENT        , RCTL_T(KC_LNG2), KC_RALT       , HYPR_T(KC_LNG1)
  ),

  [1] = LAYOUT_universal(
    _______  , KC_SLSH  , S(KC_8)   , KC_MINS , S(KC_EQL), S(KC_5)   ,                                       S(KC_7)    , S(KC_BSLS), S(KC_SLSH) , S(KC_1)    , KC_BSLS      , _______     ,
    _______  , S(KC_6)  , S(KC_QUOT), KC_QUOT , KC_GRV   , S(KC_GRV) ,                                       S(KC_3)    , KC_BTN1   , KC_BTN3    , KC_BTN2    , S(KC_4)      , S(KC_MINS)  ,
    _______  , S(KC_2)  , S(KC_COMM), S(KC_LBRC), KC_LBRC, S(KC_9)   ,                                       S(KC_0)    , KC_RBRC   , S(KC_RBRC) , S(KC_DOT)  , S(KC_SCLN)   , _______     ,
                 _______  , _______  , _______   ,        _______   , KC_DEL   ,                  KC_DEL    , _______   , _______       , _______   , _______
  ),

  [2] = LAYOUT_universal(
    _______  , S(KC_5)  , KC_7     , KC_8     , KC_9     , S(KC_8)   ,                                      C(KC_LEFT), C(KC_DOWN), C(KC_UP)  , C(KC_RIGHT), KC_HOME  , _______  ,
    _______  , S(KC_6)  , KC_4     , KC_5     , KC_6     , KC_MINS   ,                                      KC_LEFT   , KC_DOWN   , KC_UP     , KC_RIGHT   , KC_PGUP  , _______  ,
    _______  , KC_SLSH  , KC_1     , KC_2     , KC_3     , S(KC_EQL) ,                                      G(KC_LEFT), G(KC_DOWN), G(KC_UP)  , G(KC_RIGHT), KC_PGDN  , _______  ,
                  KC_0     , KC_EQL   , _______  ,         _______   , _______  ,                 _______   , _______   , _______       , _______   , KC_END
  ),

  [3] = LAYOUT_universal(
    _______  , SCRL_DVD , SCRL_DVI , SSNP_HOR , SSNP_VRT , SSNP_FRE ,                                        KC_F9    , KC_F10   , KC_F11   , KC_F12   , KC_F15   , _______  ,
    _______  , KC_LCTL  , KC_LSFT  , KC_LALT  , KC_LGUI  , AML_TO   ,                                        KC_F5    , KC_F6    , KC_F7    , KC_F8    , KC_F14   , _______  ,
    _______  , CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , _______  ,                                        KC_F1    , KC_F2    , KC_F3    , KC_F4    , KC_F13   , KBC_SAVE ,
                  QK_BOOT  , KBC_RST  , _______  ,        _______  , _______  ,                   _______  , _______  , _______       , KBC_RST  , QK_BOOT
  ),

  [4] = LAYOUT_universal(
    TO(0)    , MI_F3    , MI_Fs3   , MI_G3    , MI_Gs3   , MI_A3    ,                                         MI_E4    , MI_F4    , MI_Fs4   , MI_G4    , MI_Gs4   , _______  ,
    MI_MODU  , MI_C3    , MI_Cs3   , MI_D3    , MI_Ds3   , MI_E3    ,                                         MI_As3   , MI_B3    , MI_C4    , MI_Cs4   , MI_D4    , MI_CHNU  ,
    MI_MODD  , MI_C     , MI_Cs    , MI_D     , MI_Ds    , MI_E     ,                                         MI_F     , MI_Fs    , MI_G     , MI_Gs    , MI_A     , MI_CHND  ,
                  MI_AOFF  , MI_SUST  , MI_VELD  ,         MI_VELU  , MI_VL10  ,                   MI_OCTU  , MI_OCTD  , _______       , _______  , _______
  ),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 3
    keyball_set_scroll_mode(get_highest_layer(state) == 3);
    return state;
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif

void keyboard_post_init_user(void) {
#ifdef MIDI_ADVANCED
    //  Set octave to MI_OC0
    midi_config.octave = MI_OC0 - MIDI_OCTAVE_MIN;
#endif
};
