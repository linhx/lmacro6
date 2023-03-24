/* Copyright 2023 Linhx
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

#define _WORK 0
#define _LAYER1 1
#define _LAYER2 2
#define LAST_LAYER 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_WORK] = LAYOUT(
        KC_F20,                KC_MUTE,
        C(KC_F12), A(KC_LEFT), A(KC_RGHT),
        LCA(KC_T), ___,        ___
    ),
    [_LAYER1] = LAYOUT(
        KC_TRNS,          KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [_LAYER2] = LAYOUT(
        KC_TRNS,          KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS
    ),
};

void moveNextLayer(void) {
    int activeLayer = get_highest_layer(layer_state) + 1;
    if (activeLayer > LAST_LAYER) {
        activeLayer = 0;
    }
    layer_move(activeLayer);
}
void movePrevLayer(void) {
    int activeLayer = get_highest_layer(layer_state) - 1;
    if (activeLayer < 0) {
        activeLayer = LAST_LAYER;
    }
    layer_move(activeLayer);
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            moveNextLayer();
        } else {
            movePrevLayer();
        }
    } else if (index == 1) { /* Second encoder */
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return true;
}

void keyboard_pre_init_user(void) {
    setPinOutput(B0);
    setPinOutput(D5);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _WORK:
            writePinHigh(B0);
            writePinHigh(D5);
            break;
        case _LAYER1:
            writePinLow(B0);
            writePinHigh(D5);
            break;
        case _LAYER2:
            writePinHigh(B0);
            writePinLow(D5);
            break;
        default:
            writePinHigh(B0);
            writePinHigh(D5);
            break;
    }
    return state;
}
