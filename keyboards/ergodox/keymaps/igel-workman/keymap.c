#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define QWER 1 // QWERTY
#define SYMB 2 // symbols
#define MDIA 3 // media keys

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |   1  |   2  |   3  |   4  |   5  |  Esc |           |  L1  |   6  |   7  |   8  |   9  |   0  |   L3   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   D  |   R  |   W  |   B  | Hyper|           | Meh  |   J  |   F  |   U  |   P  |   '  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LCtrl  |   A  |   S  |   H  |   T  |   G  |------|           |------|   Y  |   N  |   E  |   O  |   I  | RCtrl  |
 * |--------+------+------+------+------+------| Left |           | Right|------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   M  |   C  |   V  |      |           |      |   K  |   L  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | -L3  |   Ä  |   Ö  | Left | Right|                                       | Down |  Up  |   Ü  |   ß  | ~L3  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Del  | Ins  |       | PgUp | PgDn |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      | LGui | LAlt |       | RAlt |        |      |
 *                                 |Back- |  /   |------|       |------| Enter  |Space |
 *                                 |space | Esc  | ~L2  |       | ~L2  |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default workman
        // left hand
       KC_TRNS,         KC_1,         KC_2,         KC_3,         KC_4,         KC_5,       KC_ESC,
        KC_TAB,         KC_Q,         KC_D,         KC_R,         KC_W,         KC_B,      KC_HYPR,
       KC_LCTL,         KC_A,         KC_S,         KC_H,         KC_T,         KC_G,
       KC_LSFT,         KC_Z,         KC_X,         KC_M,         KC_C,         KC_V,      KC_LEFT,
      MO(MDIA),      KC_TRNS,      KC_TRNS,      KC_LEFT,      KC_RGHT,
                                                                             KC_DELT,       KC_INS,
                                                                                           KC_LALT,
                                                               KC_BSPC,GUI_T(KC_ESC),     MO(SYMB),
        // right hand
      TG(QWER),         KC_6,         KC_7,         KC_8,         KC_9,         KC_0,     TG(MDIA),
        KC_MEH,         KC_J,         KC_F,         KC_U,         KC_P,      KC_QUOT,      KC_BSLS,
                        KC_Y,         KC_N,         KC_E,         KC_O,         KC_I,      KC_RCTL,
       KC_RGHT,         KC_K,         KC_L,      KC_COMM,       KC_DOT,      KC_SLSH,      KC_RSFT,
                                   KC_DOWN,        KC_UP,      KC_TRNS,      KC_TRNS,     MO(MDIA),
       KC_PGUP,      KC_PGDN,
       KC_RALT,
      MO(SYMB),       KC_ENT,       KC_SPC
    ),
/* Keymap 1: QWERTY layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |   1  |   2  |   3  |   4  |   5  |  Esc |           | L1   |   6  |   7  |   8  |   9  |   0  |   L3   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  | Hyper|           | Meh  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LCtrl  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  | RCtrl  |
 * |--------+------+------+------+------+------| Left |           | Right|------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |  ~L3 |   Ä  |   Ö  | Left | Right|                                       | Down |  Up  |   Ü  |   ß  | ~L3  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Del  | Ins  |       | PgUp | PpDn |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      | LGui | LAlt |       | RAlt |        |      |
 *                                 |Back- |  /   |------|       |------| Enter  |Space |
 *                                 |space | Esc  | ~L2  |       | ~L2  |        |      |
 *                                 `--------------------'       `----------------------'
 */
[QWER] = KEYMAP(  // layer 1 : QWERTY
        // left hand
       KC_TRNS,         KC_1,         KC_2,         KC_3,         KC_4,         KC_5,       KC_ESC,
        KC_TAB,         KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,      KC_HYPR,
       KC_LCTL,         KC_A,         KC_S,         KC_D,         KC_F,         KC_G,
       KC_LSFT,         KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,      KC_LEFT,
      MO(MDIA),      KC_TRNS,      KC_TRNS,         KC_LEFT,   KC_RGHT,
                                                                             KC_DELT,       KC_INS,
                                                                                           KC_LALT,
                                                               KC_BSPC,GUI_T(KC_ESC),     MO(SYMB),
        // right hand
      TG(QWER),         KC_6,         KC_7,         KC_8,         KC_9,         KC_0,     TG(MDIA),
        KC_MEH,         KC_Y,         KC_U,         KC_I,         KC_O,         KC_P,      KC_BSLS,
                        KC_H,         KC_J,         KC_K,         KC_L,      KC_SCLN,      KC_RCTL,
       KC_RGHT,         KC_N,         KC_M,      KC_COMM,       KC_DOT,      KC_SLSH,      KC_RSFT,
                                   KC_DOWN,        KC_UP,      KC_TRNS,      KC_TRNS,     MO(MDIA),
       KC_PGUP,      KC_PGDN,
       KC_RALT,
      MO(SYMB),       KC_ENT,       KC_SPC
    ),
/* Keymap 2: Symbol Layer (With right VIM home row)
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |  F11 |           |  F12 |  F6  |  F7  |  F8  |  F9  |  F10 |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   @  |   =  |   {  |   }  |   |  |      |           |      |   `  |   ^  |   ~  |   &  |   /  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   _  |   -  |   (  |   )  |   !  |------|           |------|   H  |   J  |   K  |   L  |   ;  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   +  |   *  |   [  |   ]  |   \  |      |           |      |   €  |   #  |   $  |   %  |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |   1  |   2  |   3  |   4  |   5  |                                       |   6  |   7  |   8  |   9  |   0  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |   :  |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */

// SYMBOLS
[SYMB] = KEYMAP(
       // left hand
       KC_TRNS,        KC_F1,        KC_F2,        KC_F3,        KC_F4,        KC_F5,       KC_F11,
       KC_TRNS,        KC_AT,       KC_EQL,      KC_LCBR,      KC_RCBR,      KC_PIPE,      KC_TRNS,
       KC_TRNS,      KC_UNDS,      KC_MINS,      KC_LPRN,      KC_RPRN,      KC_EXLM,
       KC_TRNS,      KC_PLUS,      KC_ASTR,      KC_LBRC,      KC_RBRC,      KC_BSLS,      KC_TRNS,
          KC_1,         KC_2,         KC_3,         KC_4,         KC_5,
                                                                             KC_TRNS,      KC_TRNS,
                                                                                           KC_TRNS,
                                                               KC_TRNS,      KC_COLN,      KC_TRNS,
       // right hand
        KC_F12,        KC_F6,        KC_F7,        KC_F8,        KC_F9,       KC_F10,      KC_TRNS,
       KC_TRNS,       KC_GRV,      KC_CIRC,      KC_TILD,      KC_AMPR,      KC_SLSH,      KC_TRNS,
                        KC_H,         KC_J,         KC_K,         KC_L,      KC_SCLN,      KC_TRNS,
       KC_TRNS,      KC_TRNS,      KC_HASH,       KC_DLR,      KC_PERC,      KC_TRNS,      KC_TRNS,
                                      KC_6,         KC_7,         KC_8,         KC_9,         KC_0,
       KC_TRNS,      KC_TRNS,
       KC_TRNS,
       KC_TRNS,      KC_TRNS,      KC_TRNS
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      | Lclk | MsUp | Rclk |      |      |           |      |      |   1  |   2  |   3  |      |  VolUp |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |   4  |   5  |   6  |      |  VolDn |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |   7  |   8  |   9  |      |  Mute  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |      |      |   0  |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |MsLeft|MsRght|       | Left | Right|
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | MsUp |       |  Up  |      |Brwser|
 *                                 | Lclk | Rclk |------|       |------|      |Back  |
 *                                 |      |      |MsDown|       | Down |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = KEYMAP(
       KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,
       KC_TRNS,      KC_TRNS,      KC_BTN1,      KC_MS_U,      KC_BTN2,      KC_TRNS,      KC_TRNS,
       KC_TRNS,      KC_TRNS,      KC_MS_L,      KC_MS_D,      KC_MS_R,      KC_TRNS,
       KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,
       KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_BTN1,      KC_BTN2,
                                                                             KC_MS_L,      KC_MS_R,
                                                                                           KC_MS_U,
                                                               KC_BTN1,      KC_BTN2,      KC_MS_D,
    // right hand
       KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,
       KC_TRNS,      KC_TRNS,         KC_1,         KC_2,         KC_3,      KC_TRNS,      KC_VOLU,
                     KC_TRNS,         KC_4,         KC_5,         KC_6,      KC_TRNS,      KC_VOLD,
       KC_TRNS,      KC_TRNS,         KC_7,         KC_8,         KC_9,      KC_TRNS,      KC_MUTE,
                                   KC_TRNS,      KC_TRNS,         KC_0,      KC_TRNS,      KC_TRNS,
       KC_LEFT,      KC_RGHT,
         KC_UP,
       KC_DOWN,      KC_TRNS,      KC_WBAK
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          register_code(KC_RSFT);
        } else {
          unregister_code(KC_RSFT);
        }
        break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
