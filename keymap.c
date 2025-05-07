/* qmk flash -c -kb bastardkb/charybdis/3x6/v2/splinky_3 -km qadis */

#include QMK_KEYBOARD_H
#include <stdio.h>
#include "os_detection.h"
#include "timer.h"

enum charybdis_keymap_layers {
    _QWERTY,
    _COLEMAK,
    _GRAPHITE,
    _Layer1,
    _Layer2,
    _Layer3,
    _Layer4,
    _Layer5
};

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    COLEMAK,
    GRAPHITE,
    PSSWD, PSSWD2,
    UNDO, REDO,
    COPY, PASTE,
    BACK, FORWARD,
    NEWTAB, CLOSETAB,
    CTRL_GUI,
    LB, LF, WB, WF,
    MS_JGL
    /* MOUSE, MO_LAYER2 */
};

#define L1_ENT LT(_Layer1, KC_ENT)
#define L1_SPC LT(_Layer1, KC_SPC)
#define L2_ENT LT(_Layer2, KC_ENT)
#define L3_ESC LT(_Layer3, KC_ESC)

#define L4_L LT(_Layer4, KC_L)
#define L4_I LT(_Layer4, KC_I)
#define L4_E LT(_Layer4, KC_E)
#define L4_DEL LT(_Layer4, KC_DEL)

#define C_Z LCTL_T(KC_Z)
#define A_X LALT_T(KC_X)
#define G_C LGUI_T(KC_C)
#define S_V LSFT_T(KC_V)
#define S_M LSFT_T(KC_M)
#define G_COMM LGUI_T(KC_COMM)
#define A_DOT LALT_T(KC_DOT)
#define C_SLSH LCTL_T(KC_SLSH)

#define S_D LSFT_T(KC_D)
#define S_H LSFT_T(KC_H)

#define C_Q LCTL_T(KC_Q)
#define G_M LGUI_T(KC_M)
#define S_C LSFT_T(KC_C)
#define S_P LSFT_T(KC_P)
#define G_DOT LGUI_T(KC_DOT)
#define A_MINS LALT_T(KC_MINS)

#define A_PIPE LALT_T(KC_PIPE)
#define G_LBRC LGUI_T(KC_LBRC)
#define S_RBRC LSFT_T(KC_RBRC)

#define TABLEFT S(C(KC_TAB))
#define TABRIGHT C(KC_TAB)

#define SS1 SGUI(KC_4)
#define SS2 SGUI(KC_5)

#define DLEFT C(KC_LEFT)
#define DRIGHT C(KC_RIGHT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT(
     KC_TAB,        KC_Q, KC_W, KC_E,   KC_R,    KC_T,            KC_Y,   KC_U,  KC_I,   KC_O,  KC_P,    KC_EQL,
     L3_ESC,        KC_A, KC_S, KC_D,   KC_F,    KC_G,            KC_H,   KC_J,  KC_K,   L4_L,  KC_SCLN, KC_QUOT,
     OSM(MOD_LSFT), C_Z,  A_X,  G_C,    S_V,     KC_B,            KC_N,   S_M,   G_COMM, A_DOT, C_SLSH,  OSM(MOD_LSFT),
                                L4_DEL, KC_BSPC, L1_ENT,          L2_ENT,  L1_SPC
    ),

    [_COLEMAK] = LAYOUT(
     KC_TAB,        KC_Q, KC_W, KC_F,   KC_P,    KC_B,            KC_J,   KC_L,  KC_U,   KC_Y,  KC_SCLN, KC_EQL,
     L3_ESC,        KC_A, KC_R, KC_S,   KC_T,    KC_G,            KC_M,   KC_N,  KC_E,   L4_I,  KC_O,    KC_QUOT,
     OSM(MOD_LSFT), C_Z,  A_X,  G_C,    S_D,     KC_V,            KC_K,   S_H,   G_COMM, A_DOT, C_SLSH,  OSM(MOD_LSFT),
                                L4_DEL, KC_BSPC, L1_ENT,          L2_ENT,  L1_SPC
    ),

    [_GRAPHITE] = LAYOUT(
     KC_TAB,        KC_B, KC_L, KC_D,   KC_W,    KC_Z,            KC_MINS, KC_F,  KC_O,   KC_U,  KC_J,   KC_SCLN,
     L3_ESC,        KC_N, KC_R, KC_T,   KC_S,    KC_G,            KC_Y,    KC_H,  KC_A,   L4_E,  KC_I,   KC_QUOT,
     OSM(MOD_LSFT), C_Q,  A_X,  G_M,    S_C,     KC_V,            KC_K,    S_P,   G_COMM, A_DOT, C_SLSH, OSM(MOD_LSFT),
                                L4_DEL, KC_BSPC, L1_ENT,          L2_ENT,  L1_SPC
    ),

    [_Layer1] = LAYOUT(
     PSSWD,   PSSWD2,  _______, KC_LCBR, KC_RCBR, _______,       _______, KC_7, KC_8, KC_9, KC_PAST, KC_EQL,
     KC_CAPS, _______, KC_BSLS, KC_LPRN, KC_RPRN, _______,       KC_DOT,  KC_4, KC_5, KC_6, KC_PPLS, KC_MINS,
     _______, KC_LCTL, A_PIPE,  G_LBRC,  S_RBRC,  _______,       KC_COMM, KC_1, KC_2, KC_3, KC_PSLS, _______,
                                _______, _______, _______,       KC_0, _______
    ),

    [_Layer2] = LAYOUT(
     _______, _______, _______, _______, _______, _______,       _______, BACK,    TABLEFT, TABRIGHT, FORWARD,  _______,
     _______, _______, _______, _______, _______, _______,       KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, DLEFT,    DRIGHT,
     _______, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, _______,       LB,      WB,      WF,      LF,       C(KC_UP), KC_F10,
                                _______, _______, _______,       _______, _______
    ),

    [_Layer3] = LAYOUT(
     _______, SS1,     KC_F7, KC_F8,   KC_F9,  _______,         _______, KC_AMPR, KC_ASTR, KC_LPRN, _______, _______,
     _______, SS2,     KC_F4, KC_F5,   KC_F6,  HYPR(KC_G),      _______, KC_DLR,  KC_PERC, KC_CIRC, KC_TILD, KC_UNDS,
     _______, KC_LCTL, KC_F1, KC_F2,   KC_F3,  _______,         _______, KC_EXLM, KC_AT,   KC_HASH, KC_GRV,  _______,
                              _______, KC_F10, C(KC_UP),        _______, _______
    ),

    [_Layer4] = LAYOUT(
     _______, _______, _______, _______, _______, _______,       UNDO,    REDO,    COPY,    PASTE,   KC_DEL,   KC_BSPC,
     _______, _______, _______, _______, _______, _______,       KC_BTN2, KC_BTN1, DRGSCRL, _______, KC_LSFT,  NEWTAB,
     _______, _______, _______, _______, _______, _______,       XXXXXXX, KC_BTN3, KC_ESC,  KC_ENT,  CTRL_GUI, CLOSETAB,
                                _______, _______, _______,       _______, _______
    ),

    [_Layer5] = LAYOUT(
     QK_BOOT, _______, _______, _______, _______, _______,       _______, _______, _______, _______,  _______, _______,
     _______, _______, _______, _______, _______, _______,       MS_JGL,  QWERTY,  COLEMAK, GRAPHITE, _______, _______,
     _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______,  _______, _______,
                                _______, _______, _______,       _______, _______
    ),

};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _Layer1, _Layer2, _Layer5);
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case L2_ENT || L1_ENT:
            return TAPPING_TERM - 106;
        case L3_ESC:
            return TAPPING_TERM - 100;
        default:
            return TAPPING_TERM;
    }
}

bool is_mouse_jiggle_active = false;
bool mouse_jiggle_direction = false;
uint16_t mouse_jiggle_frequency = 1500;
uint16_t mouse_jiggle_timer = 0;
void matrix_scan_user(void) {
    if (is_keyboard_master()) {
        if (mouse_jiggle_timer == 0) mouse_jiggle_timer = timer_read();
    }
    if (is_mouse_jiggle_active) {
        if (timer_elapsed(mouse_jiggle_timer) > mouse_jiggle_frequency) {
            mouse_jiggle_timer = timer_read();
            mouse_jiggle_direction ? tap_code(KC_MS_LEFT) : tap_code(KC_MS_RIGHT);
            mouse_jiggle_direction = !mouse_jiggle_direction;
        }
    }
}

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

static uint16_t auto_pointer_layer_timer = 0;
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (abs(mouse_report.x) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD || abs(mouse_report.y) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD) {
        if (auto_pointer_layer_timer == 0) {
            layer_on(_Layer4);
        }
        auto_pointer_layer_timer = timer_read();
    }
    return mouse_report;
}

void matrix_scan_user(void) {
    if (auto_pointer_layer_timer != 0 && TIMER_DIFF_16(timer_read(), auto_pointer_layer_timer) >= CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS) {
        auto_pointer_layer_timer = 0;
        layer_off(_Layer4);
    }
}

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    os_variant_t host_os = detected_host_os();
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
        case GRAPHITE:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_GRAPHITE);
            }
            return false;
        case PSSWD:
            if (record->event.pressed) {
                SEND_STRING("Zaibun786\n");
            }
            return false;
        case PSSWD2:
            if (record->event.pressed) {
                SEND_STRING("QadCha1@\n");
            }
            return false;
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
        case CTRL_GUI:
            if (record->event.pressed) {
                if (host_os == OS_MACOS || host_os == OS_IOS) {
                    register_code(KC_LGUI);
                } else {
                    register_code(KC_LCTL);
                }
            } else {
                if (host_os == OS_MACOS || host_os == OS_IOS) {
                    unregister_code(KC_LGUI);
                } else {
                    unregister_code(KC_LCTL);
                }
            }
            return false;
        case LB:
            if (record->event.pressed) {
                if (host_os == OS_MACOS || host_os == OS_IOS) {
                    register_code(KC_LGUI);
                    tap_code(KC_LEFT);
                    unregister_code(KC_LGUI);
                } else {
                    tap_code(KC_HOME);
                }
            }
            return false;
        case LF:
            if (record->event.pressed) {
                if (host_os == OS_MACOS || host_os == OS_IOS) {
                    register_code(KC_LGUI);
                    tap_code(KC_RIGHT);
                    unregister_code(KC_LGUI);
                } else {
                    tap_code(KC_END);
                }
            }
            return false;
        case WB:
            if (record->event.pressed) {
                if (host_os == OS_MACOS || host_os == OS_IOS) {
                    register_code(KC_LALT);
                    tap_code(KC_LEFT);
                    unregister_code(KC_LALT);
                } else {
                    register_code(KC_LCTL);
                    tap_code(KC_LEFT);
                    unregister_code(KC_LCTL);
                }
            }
            return false;
        case WF:
            if (record->event.pressed) {
                if (host_os == OS_MACOS || host_os == OS_IOS) {
                    register_code(KC_LALT);
                    tap_code(KC_RIGHT);
                    unregister_code(KC_LALT);
                } else {
                    register_code(KC_LCTL);
                    tap_code(KC_RIGHT);
                    unregister_code(KC_LCTL);
                }
            }
            return false;
        case MS_JGL:
            if (record->event.pressed) {
                is_mouse_jiggle_active = !is_mouse_jiggle_active;
            }
            return false;
        /* case MOUSE: */
        /*     auto_pointer_layer_timer = 0; */
        /*     layer_off(_Layer4); */
        /*     return false; */
        /* case MO_LAYER2: */
        /*     if (record->event.pressed) { */
        /*         layer_off(_Layer4); */
        /*         layer_on(_Layer2); */
        /*     } else { */
        /*         layer_off(_Layer2); */
        /*         layer_on(_Layer4); */
        /*     } */
        /*     return false; */
    }
    return true;
}
