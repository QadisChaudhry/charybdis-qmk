#include QMK_KEYBOARD_H
#include <stdio.h>
#include "os_detection.h"

enum charybdis_keymap_layers {
    _Layer1,
    _Layer2,
    _Layer3,
};

enum custom_keycodes {
    UNDO = SAFE_RANGE,
    REDO,
    COPY,
    PASTE,
    BACK,
    FORWARD,
    NEWTAB,
    CLOSETAB
};

#define L2_DEL LT(_Layer2, KC_DEL)
#define L3_TAB LT(_Layer3, KC_TAB)

#define TABLEFT S(C(KC_TAB))
#define TABRIGHT C(KC_TAB)

#define DLEFT C(KC_LEFT)
#define DRIGHT C(KC_RIGHT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_Layer1] = LAYOUT(
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       REDO,    KC_BTN2, COPY,    PASTE,   NEWTAB,  CLOSETAB,
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       UNDO,    KC_BTN1, KC_BTN3, KC_LSFT, KC_LCTL, XXXXXXX,
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, DRGSCRL, KC_ESC,  KC_ENT,  SNP_TOG, XXXXXXX,
                                  XXXXXXX, XXXXXXX, XXXXXXX,       L3_TAB,  L2_DEL
    ),

    [_Layer2] = LAYOUT(
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       DPI_MOD, BACK,     TABLEFT,    TABRIGHT, FORWARD, XXXXXXX,
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       KC_LEFT, KC_DOWN,  KC_UP,      KC_RIGHT, DLEFT,   DRIGHT,
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, C(KC_UP), C(KC_DOWN), XXXXXXX,  XXXXXXX, XXXXXXX,
                                  XXXXXXX, XXXXXXX, XXXXXXX,       _______, _______
    ),

    [_Layer3] = LAYOUT(
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       QK_BOOT, KC_7, KC_8, KC_9, KC_0,    KC_PEQL,
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       KC_DOT,  KC_4, KC_5, KC_6, KC_PPLS, KC_MINS,
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       KC_COMM, KC_1, KC_2, KC_3, KC_PSLS, KC_PAST,
                                  XXXXXXX, XXXXXXX, XXXXXXX,       _______, _______
    ),

};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case L2_DEL:
            return TAPPING_TERM - 110;
        case L3_TAB:
            return TAPPING_TERM - 110;
        default:
            return TAPPING_TERM;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    os_variant_t host_os = detected_host_os();
    switch (keycode) {
        case UNDO:
            if (record->event.pressed) {
                if (host_os == OS_MACOS || host_os == OS_IOS) {
                    register_code(KC_LGUI);
                    tap_code(KC_Z);
                    unregister_code(KC_LGUI);
                } else {
                    register_code(KC_LCTL);
                    tap_code(KC_Z);
                    unregister_code(KC_LCTL);
                }
            }
            return false;
        case REDO:
            if (record->event.pressed) {
                if (host_os == OS_MACOS || host_os == OS_IOS) {
                    register_code(KC_LGUI);
                    register_code(KC_LSFT);
                    tap_code(KC_Z);
                    unregister_code(KC_LSFT);
                    unregister_code(KC_LGUI);
                } else {
                    register_code(KC_LCTL);
                    tap_code(KC_Y);
                    unregister_code(KC_LCTL);
                }
            }
            return false;
        case COPY:
            if (record->event.pressed) {
                if (host_os == OS_MACOS || host_os == OS_IOS) {
                    register_code(KC_LGUI);
                    tap_code(KC_C);
                    unregister_code(KC_LGUI);
                } else {
                    register_code(KC_LCTL);
                    tap_code(KC_C);
                    unregister_code(KC_LCTL);
                }
            }
            return false;
        case PASTE:
            if (record->event.pressed) {
                if (host_os == OS_MACOS || host_os == OS_IOS) {
                    register_code(KC_LGUI);
                    tap_code(KC_V);
                    unregister_code(KC_LGUI);
                } else {
                    register_code(KC_LCTL);
                    tap_code(KC_V);
                    unregister_code(KC_LCTL);
                }
            }
            return false;
        case BACK:
            if (record->event.pressed) {
                if (host_os == OS_MACOS || host_os == OS_IOS) {
                    register_code(KC_LGUI);
                    tap_code(KC_LBRC);
                    unregister_code(KC_LGUI);
                } else {
                    register_code(KC_LALT);
                    tap_code(KC_LEFT);
                    unregister_code(KC_LALT);
                }
            }
            return false;
        case FORWARD:
            if (record->event.pressed) {
                if (host_os == OS_MACOS || host_os == OS_IOS) {
                    register_code(KC_LGUI);
                    tap_code(KC_RBRC);
                    unregister_code(KC_LGUI);
                } else {
                    register_code(KC_LALT);
                    tap_code(KC_RIGHT);
                    unregister_code(KC_LALT);
                }
            }
            return false;
        case NEWTAB:
            if (record->event.pressed) {
                if (host_os == OS_MACOS || host_os == OS_IOS) {
                    register_code(KC_LGUI);
                    tap_code(KC_T);
                    unregister_code(KC_LGUI);
                } else {
                    register_code(KC_LCTL);
                    tap_code(KC_T);
                    unregister_code(KC_LCTL);
                }
            }
            return false;
        case CLOSETAB:
            if (record->event.pressed) {
                if (host_os == OS_MACOS || host_os == OS_IOS) {
                    register_code(KC_LGUI);
                    tap_code(KC_W);
                    unregister_code(KC_LGUI);
                } else {
                    register_code(KC_LCTL);
                    tap_code(KC_W);
                    unregister_code(KC_LCTL);
                }
            }
            return false;
    }
    return true;
}
