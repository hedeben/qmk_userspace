#pragma once

// Tap Dance keycodes
enum td_keycodes {
    TD_MA
};

// Define a type containing as many tapdance states as you need
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_SINGLE_TAP
} td_state_t;

// Create a global instance of the tapdance state type
static td_state_t td_state;

// Function to determine the current tapdance state
td_state_t cur_dance(tap_dance_state_t *state);

// `finished` and `reset` functions for each tapdance keycode
void modalt_finished(tap_dance_state_t *state, void *user_data);
void modalt_reset(tap_dance_state_t *state, void *user_data);



// Determine the tapdance state to return
td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    }
    if (state->count == 2) return TD_DOUBLE_SINGLE_TAP;
    else return TD_UNKNOWN;
}

void modalt_finished(tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
            set_oneshot_mods(MOD_BIT(KC_LGUI));
            break;
        case TD_SINGLE_HOLD:
            clear_oneshot_mods();
            register_mods(MOD_BIT(KC_LALT));
            break;
        case TD_DOUBLE_SINGLE_TAP:
            set_oneshot_mods(MOD_BIT(KC_RALT));
            break;
        default:
            break;
    }
}

void modalt_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP:
            /* clear_oneshot_mods(); */
            break;
        case TD_SINGLE_HOLD:
            clear_oneshot_mods();
            unregister_mods(MOD_BIT(KC_LALT));
            break;
        case TD_DOUBLE_SINGLE_TAP:
            /* clear_oneshot_mods(); */
            break;
        default:
            break;
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_MA] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, modalt_finished, modalt_reset),
};
