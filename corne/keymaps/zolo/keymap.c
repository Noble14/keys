#include QMK_KEYBOARD_H

enum layers {
    BASE,
    _NAV,
    _SYM,
    _NUM,
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
	[BASE] = LAYOUT_split_3x6_3(
							_______, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T, 		KC_Z, KC_U,   KC_I,   KC_O,   KC_P,      _______, 
							QK_REP, HOME_A, HOME_S, HOME_D, HOME_F, KC_G, 		KC_H, HOME_J, HOME_K, HOME_L, HOME_SCLN, _______, 
							_______, KC_Y,   KC_X,   KC_C,   KC_V,   KC_B, 		KC_N, KC_M,   KC_COMM, KC_DOT, KC_SLSH,  _______, 
									KC_ESC, LT(_SYM,KC_SPC), LT(_NUM, KC_TAB), 	LT(_NAV, KC_ENT), LT(_HUN,KC_BSPC), KC_DEL),
	[_SYM] = LAYOUT_split_3x6_3(
							_______, KC_QUOT, KC_LABK, KC_RABK, KC_DQUO, KC_DOT, 		KC_AMPR,  KC_GRV  , KC_LBRC, KC_RBRC, KC_PERC, _______, 
							QK_REP, KC_EXLM, KC_MINS, KC_PLUS, KC_EQL , KC_HASH, 		KC_PIPE, KC_COLN, KC_LPRN, KC_RPRN, KC_QUES, _______, 
							_______, KC_CIRC, KC_SLSH, KC_ASTR, KC_BSLS, KC_UNDS, 		KC_TILD, KC_DLR , KC_LCBR, KC_RCBR, KC_AT,  _______, 
									_______, _______, _______, 							_______, _______, _______),
	[_NUM] = LAYOUT_split_3x6_3(
							QK_BOOT, _______,   _______,  _______,   _______,  _______, 		            KC_BSLS,  KC_7, KC_8, KC_9,   _______,      _______, 
							QK_REP, LGUI_T(KC_A), LALT_T(KC_S),  LCTL_T(KC_D), LSFT_T(KC_F), KC_G, 		KC_COLN,  KC_4, KC_5, KC_6, _______, _______, 
							_______, _______,   _______,   _______,   _______,   _______, 		            KC_SLSH,  KC_1, KC_2, KC_3, KC_0,  _______, 
													_______, KC_SPC, _______,  							KC_ENT, KC_0, _______),
	[_NAV] = LAYOUT_split_3x6_3(
							_______, KC_HOME,  KC_UP,  KC_END, KC_BSPC, KC_PGUP, 		        KC_F12,  KC_F7, KC_F8, KC_F9,  _______,      _______, 
							QK_REP, KC_LEFT, KC_DOWN,  KC_RIGHT, KC_DEL, KC_PGDN, 		        KC_F11, RSFT_T(KC_F4), RCTL_T(KC_F5), LALT_T(KC_F6),  KC_RGUI, _______, 
							_______, _______,   _______,   _______,   _______,   _______, 		KC_F10, KC_F1, KC_F2, KC_F3,  _______, _______, 
													_______, KC_SPC, _______,  							KC_ENT, KC_ENT, _______),
	[_HUN] = LAYOUT_split_3x6_3(
							_______, _______,   _______,  _______,   _______,  _______, 		            _______,  _______, _______, _______,   _______,      _______, 
							QK_REP, XP(A_ACUTE, A_ACUTE_CAP ), XP(O_DIAER, O_DIAER_CAP), XP(U_DIAER, U_DIAER_CAP), XP(U_ACUTE, U_ACUTE_CAP), _______,        					_______,  XP(O_ACUTE, O_ACUTE_CAP), XP(U_DOUB_ACUTE, U_DOUB_ACUTE_CAP), XP(O_DOUB_ACUTE, O_DOUB_ACUTE_CAP), XP(E_ACUTE, E_ACUTE_CAP), _______, 
							_______, XP(I_ACUTE, I_ACUTE_CAP),   _______,   _______,   _______,   _______, 		            _______,  _______, _______, _______, _______,  _______, 
													_______, KC_LSFT, _______,  							_______, _______, _______),
	
	};



//	[_HUN] = LAYOUT_split_3x6_3(
//							_______, _______,   _______,  _______,   _______,  _______, 		            _______,  _______, _______, _______,   _______,      _______, 
//							QK_REP, _______, _______,  _______, _______, _______,        					_______,  _______, _______, _______, _______, _______, 
//							_______, _______,   _______,   _______,   _______,   _______, 		            _______,  _______, _______, _______, _______,  _______, 
//													_______, _______, _______,  							_______, _______, _______),