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

#include QMK_KEYBOARD_H
#include "keymap_jp.h"

#include "quantum.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default (VIA)
  [0] = LAYOUT_universal(
    KC_ESC   , KC_Q     , KC_L     , KC_U     , KC_COMM  , KC_DOT   ,                                        KC_F     , KC_W     , KC_R     , KC_Y     , KC_P     , KC_SCLN  ,
    KC_TAB   , LT(6,KC_E), KC_I    , KC_A     , KC_O     , KC_SLSH  ,                                        KC_K     , KC_T     , KC_N     , KC_S     , LT(6,KC_H), KC_ENT  ,
    KC_LCTL  , KC_Z     , KC_X     , KC_C     , KC_V     , LT(3,KC_MINS),                                    LT(3,KC_G), KC_D    , KC_M     , KC_J     , KC_B     , KC_INT1  ,
               KC_LALT  , _______ , _______   ,LT(1,KC_SPC), LT(2,KC_LNG2),		  RSFT_T(KC_TAB), LT(1,KC_ENT), KC_BSPC  , KC_DEL   , KC_LGUI
  ),

  [1] = LAYOUT_universal(
    _______ ,   KC_F1   , KC_F2    , KC_F3   , KC_F4    , KC_F5    ,                                         KC_MINS  , KC_EQL   , KC_7     , KC_8     , KC_9     , KC_SCLN  ,
    _______ ,   _______ , KC_AT    , KC_LBRC , KC_RBRC  , KC_2     ,                                         KC_PPLS  , KC_PMNS  , KC_4     , KC_5     , KC_6     , KC_QUOT  ,
    _______ ,   _______ , _______  , _______ , _______  , KC_INT1  ,                                         KC_PAST  , KC_PSLS  , KC_1     , KC_2     , KC_3     , KC_PENT  ,
                  _______  , _______ , _______  , _______  , _______  ,                          _______   , _______  , _______  , KC_P0    , KC_PDOT
  ),
-
  [2] = LAYOUT_universal(
    _______  ,S(KC_QUOT), KC_7     , KC_8    , KC_9     , S(KC_8)  ,                                         S(KC_9)  , S(KC_1)  , S(KC_6)  , KC_LBRC  , S(KC_4)  , _______  ,
    _______  ,S(KC_SCLN), KC_4     , KC_5    , KC_6     , KC_RBRC  ,                                         KC_NUHS  , KC_MINS  , S(KC_EQL), S(KC_3)  , KC_QUOT  , S(KC_2)  ,
    _______  ,S(KC_MINS), KC_1     , KC_2    , KC_3     ,S(KC_RBRC),                                        S(KC_NUHS),S(KC_INT1), KC_EQL   ,S(KC_LBRC),S(KC_SLSH),S(KC_INT3),
                  KC_0     , KC_DOT  , _______  ,         _______  , _______  ,                   KC_DEL   , _______  , _______       , _______  , _______
  ),

  [3] = LAYOUT_universal(
    RGB_TOG  , AML_TO   , AML_I50  , AML_D50  , _______  , _______  ,                                        RGB_M_P  , RGB_M_B  , RGB_M_R  , RGB_M_SW , RGB_M_SN , RGB_M_K  ,
    RGB_MOD  , RGB_HUI  , RGB_SAI  , RGB_VAI  , _______  , SCRL_DVI ,                                        RGB_M_X  , RGB_M_G  , RGB_M_T  , RGB_M_TW , _______  , _______  ,
    RGB_RMOD , RGB_HUD  , RGB_SAD  , RGB_VAD  , _______  , SCRL_DVD ,                                        CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , _______  , KBC_SAVE ,
                  QK_BOOT  , KBC_RST  , _______  ,        _______  , _______  ,                   _______  , _______  , _______       , KBC_RST  , QK_BOOT
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

/*
2025/04/29 https://note.com/mamelog0103/n/n5a51fcd24f26を参考に追記
*/
#ifdef COMBO_ENABLE
enum combos{
DM_MOUSE_BUTTON_1,
ZX_MOUSE_BUTTON_1,
JB_MOUSE_BUTTON_2,
CV_MOUSE_BUTTON_2,
NS_MOUSE_BUTTON_3,
IA_MOUSE_BUTTON_3,
MJ_MOUSE_BUTTON_4,
XC_MOUSE_BUTTON_4,
};

const uint16_t PROGMEM my_dm[] = {KC_D, KC_M, COMBO_END};
const uint16_t PROGMEM my_zx[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM my_jb[] = {KC_J, KC_B, COMBO_END};
const uint16_t PROGMEM my_cv[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM my_ns[] = {KC_N, KC_S, COMBO_END};
const uint16_t PROGMEM my_ia[] = {KC_I, KC_A, COMBO_END};
const uint16_t PROGMEM my_mj[] = {KC_M, KC_J, COMBO_END};
const uint16_t PROGMEM my_xc[] = {KC_X, KC_C, COMBO_END};

combo_t key_combos[] = {
[DM_MB1]=COMBO(my_dm, QK_MOUSE_BUTTON_1),
[ZX_MB1]=COMBO(my_zx, QK_MOUSE_BUTTON_1),
[JB_MB2]=COMBO(my_jb, QK_MOUSE_BUTTON_2),
[CV_MB2]=COMBO(my_cv, QK_MOUSE_BUTTON_2),
[NS_MB3]=COMBO(my_ns, QK_MOUSE_BUTTON_3),
[IA_MB3]=COMBO(my_ia, QK_MOUSE_BUTTON_3),
[MJ_MB4]=COMBO(my_mj, QK_MOUSE_BUTTON_4),
[XC_MB4]=COMBO(my_xc, QK_MOUSE_BUTTON_4),
};

#endif



