/* Copyright 2021 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

// clang-format off

enum layers {
    BASE,
    _SYM,
    _NUM,
    _NAV,
    _HUN
};
#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LCTL_T(KC_D)
#define HOME_F LSFT_T(KC_F)

// Right-hand home row mods
#define HOME_J RSFT_T(KC_J)
#define HOME_K RCTL_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_SCLN RGUI_T(KC_SCLN)

enum unicode_names {
    A_ACUTE_CAP,
    A_ACUTE,
    E_ACUTE_CAP,
    E_ACUTE,
    I_ACUTE_CAP,
    I_ACUTE,
    O_ACUTE_CAP,
    O_ACUTE,
    O_DIAER_CAP,
    O_DIAER,
    U_DIAER_CAP,
    U_DIAER,
    U_ACUTE_CAP,
    U_ACUTE,
    U_DOUB_ACUTE_CAP,
    U_DOUB_ACUTE,
    O_DOUB_ACUTE_CAP,
    O_DOUB_ACUTE,
};

const uint32_t unicode_map[] PROGMEM = {
    [A_ACUTE_CAP]  		= 0x00C1,	// Á
    [A_ACUTE] 			= 0x00E1,	// á
    [E_ACUTE_CAP]  		= 0x00C9,	// É
    [E_ACUTE] 			= 0x00E9,	// é
    [I_ACUTE_CAP]  		= 0x00CD,	// í
    [I_ACUTE] 			= 0x00ED,	// Í
    [O_ACUTE_CAP] 		= 0x00D3,	// Ó
    [O_ACUTE] 			= 0x00F3,	// ó
    [O_DIAER_CAP] 		= 0x00D6,	// Ö
    [O_DIAER] 			= 0x00F6,	// ö
    [U_DIAER_CAP] 		= 0x00DC,	// Ü
    [U_DIAER] 			= 0x00FC,	// ü
    [U_ACUTE_CAP] 		= 0x00DA,	// Ú
    [U_ACUTE] 			= 0x00FA,	// ú
    [U_DOUB_ACUTE_CAP] 	= 0x0170,	// Ű
    [U_DOUB_ACUTE] 		= 0x0171,	// ű
    [O_DOUB_ACUTE_CAP] 	= 0x0150,	// Ő
    [O_DOUB_ACUTE] 		= 0x0151,	// ő
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_ansi_69(
        KC_ESC,  KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,     KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,          KC_INS,
        KC_TAB,  KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,    KC_Z,     KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,          KC_DEL,
        KC_CAPS, HOME_A,     HOME_S,     HOME_D,    HOME_F,    KC_G,              KC_H,    HOME_J,    HOME_K,    HOME_L,     HOME_SCLN,  KC_QUOT,  KC_ENT,           KC_HOME,
        KC_LSFT,           KC_Y,     KC_X,    KC_C,    KC_V,    KC_B,     KC_B,    KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT, KC_UP,
        KC_LCTL, KC_LWIN,  KC_ESC,           LT(_SYM, KC_SPACE),  LT(_NUM, KC_TAB), LT(_NAV, KC_ENT),         LT(_HUN, KC_BSPC),        KC_DEL,      KC_LEFT, KC_DOWN, KC_RGHT),

    [_SYM] = LAYOUT_ansi_69(
        KC_GRV,  KC_BRID,  KC_BRIU,  KC_NO,   KC_NO,   RGB_VAD, RGB_VAI,  KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,          _______,
        RGB_TOG, KC_QUOT, KC_LABK, KC_RABK, KC_DQUO, KC_DOT,            KC_AMPR,  KC_GRV  , KC_LBRC, KC_RBRC, KC_PERC,_______,  _______,  _______,          _______,
        _______,KC_EXLM, KC_MINS, KC_PLUS, KC_EQL , KC_HASH,               KC_PIPE, KC_COLN, KC_LPRN, KC_RPRN, KC_QUES,  _______,  _______,          _______,
        _______,           KC_CIRC, KC_SLSH, KC_ASTR, KC_BSLS, KC_UNDS,      _______, KC_TILD, KC_DLR , KC_LCBR, KC_RCBR, KC_AT, _______, _______,
        _______, _______,  _______,           _______,          _______,  _______,          _______,           _______,            _______, _______, _______),

    [_NUM] = LAYOUT_ansi_69(
        QK_BOOT, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______, _______, 
        _______, _______, _______, _______, _______, _______,                           KC_BSLS,  KC_7, KC_8, KC_9, _______, _______, _______, _______, _______, 
        QK_REP, LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G,               KC_COLN,  KC_4, KC_5, KC_6,_______, _______, _______, _______, 
        _______, _______, _______, _______, _______, _______,                 _______, KC_SLSH,  KC_1, KC_2, KC_3, KC_0, _______, _______,  
        _______,  _______,   _______,            _______,           _______,   KC_ENT,           _______,            _______,             _______,  _______,  _______), 

    [_NAV] = LAYOUT_ansi_69(
        _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, _______, 
        _______, KC_HOME,  KC_UP,  KC_END, KC_BSPC, KC_PGUP,                 KC_F12, KC_F7, KC_F8, KC_F9, _______, _______, _______, _______, _______, 
        _______, KC_LEFT, KC_DOWN,  KC_RIGHT, KC_DEL, KC_PGDN,                 KC_F11, RSFT_T(KC_F4), RCTL_T(KC_F5), LALT_T(KC_F6),  KC_RGUI, _______, _______,_______, 
         
        _______, _______, _______, _______, _______, _______,                 KC_F10, KC_F1, KC_F2, KC_F3, _______, _______, _______, _______, 
        _______,  _______,   _______,            KC_SPACE,           _______,   _______,           _______,            _______,             _______,  _______,  _______), 

    [_HUN] = LAYOUT_ansi_69(
        _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, _______, 
        _______, _______, _______, _______, _______, _______,                 _______, _______, _______, _______, _______, _______, _______, _______, _______, 
        _______,XP(A_ACUTE, A_ACUTE_CAP ), XP(O_DIAER, O_DIAER_CAP), XP(U_DIAER, U_DIAER_CAP), XP(U_ACUTE, U_ACUTE_CAP), _______,                 _______,XP(O_ACUTE, O_ACUTE_CAP), XP(U_DOUB_ACUTE, U_DOUB_ACUTE_CAP), XP(O_DOUB_ACUTE, O_DOUB_ACUTE_CAP), XP(E_ACUTE, E_ACUTE_CAP), _______, _______, _______, 
        _______,XP(I_ACUTE, I_ACUTE_CAP), _______, _______, _______, _______,                 _______, _______, _______, _______, _______, _______, _______, _______, 
        _______,  _______,   _______,            KC_LSFT,           _______,   _______,           _______,            _______,             _______,  _______,  _______)
};

//         [_HUN] = LAYOUT_ansi_69(
//        _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, _______, 
//        _______, _______, _______, _______, _______, _______,                 _______, _______, _______, _______, _______, _______, _______, _______, _______, 
//        _______, _______, _______, _______, _______, _______,                 _______, _______, _______, _______, _______, _______, _______, _______, 
//        _______, _______, _______, _______, _______, _______,                 _______, _______, _______, _______, _______, _______, _______, _______, 
//        _______,  _______,   _______,            _______,           _______,   _______,           _______,            _______,             _______,  _______,  _______)
