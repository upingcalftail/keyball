/*
This is the c configuration file for the keymap

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

#pragma once

#ifdef RGBLIGHT_ENABLE
//#    define RGBLIGHT_EFFECT_BREATHING
//#    define RGBLIGHT_EFFECT_RAINBOW_MOOD
//#    define RGBLIGHT_EFFECT_RAINBOW_SWIRL
//#    define RGBLIGHT_EFFECT_SNAKE
//#    define RGBLIGHT_EFFECT_KNIGHT
//#    define RGBLIGHT_EFFECT_CHRISTMAS
#    define RGBLIGHT_EFFECT_STATIC_GRADIENT
//#    define RGBLIGHT_EFFECT_RGB_TEST
//#    define RGBLIGHT_EFFECT_ALTERNATING
//#    define RGBLIGHT_EFFECT_TWINKLE
#endif

#define TAP_CODE_DELAY 5
//2025/05/02～ takashicompanyのAMLファームウェアを流用させてもらう
//https://github.com/takashicompany/qmk_firmware/blob/keyball/keyboards/keyball/keyball44/keymaps/takashicompany/config.h

#define DYNAMIC_KEYMAP_LAYER_COUNT 7
#define AUTO_MOUSE_DEFAULT_LAYER 7


//#define POINTING_DEVICE_AUTO_MOUSE_ENABLE

//コンボキー、CAPS_WORDなどの参考は mameさん
//https://note.com/mamelog0103/n/n5a51fcd24f26
#define CAPS_WORD_IDLE_TIMEOUT 5000  // 5 seconds.
