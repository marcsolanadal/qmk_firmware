#include QMK_KEYBOARD_H

enum ferris_layers {
    _COLEMAK_DH,
    _EXTEND,
    _SYMBOLS,
};

// Tap dance keycodes
enum {
    TD_CBR,
    TD_PRN,
    TD_BRC,
};

// Special keys
#define SHSP LSFT_T(KC_SPC) // Shift on hold, space on tap

// Layer transition functions
#define EXT MO(_EXTEND)
#define SYM MO(_SYMBOLS)

tap_dance_action_t tap_dance_actions[] = {
    [TD_CBR] = ACTION_TAP_DANCE_DOUBLE(KC_LCBR, KC_RCBR),
    [TD_PRN] = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_RPRN),
    [TD_BRC] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Colemak-DH
     * .----------------------------------.          .----------------------------------.
     * |  q   |  w   |  f   |  p   |  b   |          |  j   |  l   |  u   |  y   |  '   |
     * |------+------+------+------+------|          |------+------+------+------+------|
     * |  a   |  r   |  s   |  t   |  g   |          |  m   |  n   |  e   |  i   |  o   |
     * |------+------+------+------+------|          |------+------+------+------+------|
     * |  z   |  x   |  c   |  d   |  v   |          |  k   |  h   |  ,   |  .   |  /   |
     * `--------------------.------+------|          |------+------.--------------------'
     *                      | Ext  | SHSP |          | SHSP | Sym  |
     *                      `-------------'          `-------------'
     */
    [_COLEMAK_DH] = LAYOUT(
        KC_Q,      KC_W,    KC_F,    KC_P,    KC_B,            KC_J,    KC_L,  KC_U,    KC_Y,   KC_QUOT,
        KC_A,      KC_R,    KC_S,    KC_T,    KC_G,            KC_M,    KC_N,  KC_E,    KC_I,   KC_O,
        KC_Z,      KC_X,    KC_C,    KC_D,    KC_V,            KC_K,    KC_H,  KC_COMM, KC_DOT, KC_SLSH,
                                     EXT,     SHSP,            SHSP,    SYM
    ),

    /* Extend
     * .----------------------------------.          .----------------------------------.
     * | Esc  |  Up  | Find | Down | Ins  |          | Pgup | Home | End  | Prnt | Caps |
     * |------+------+------+------+------|          |------+------+------+------+------|
     * | Alt  | GUI  | LCtl | Shft | Tab  |          | Left | Down |  Up  | Rght | Del  |
     * |------+------+------+------+------|          |------+------+------+------+------|
     * | Undo | Cut  | Copy | Pste | MEH  |          | Pgdn | Bspc | Shft | App  | Pscr |
     * `--------------------.------+------|          |------+------.--------------------'
     *                      |      |      |          | Ent  | Rep  |
     *                      `-------------'          `-------------'
     */
    [_EXTEND] = LAYOUT(
        KC_ESC,         DT_UP,          LCMD(KC_F),     DT_DOWN,         KC_INS,            KC_PGUP,  KC_HOME,  KC_END,         DT_PRNT,   CW_TOGG,
        OSM(MOD_LALT),  OSM(MOD_LCTL),  OSM(MOD_LGUI),  OSM(MOD_LSFT),   KC_TAB,            KC_LEFT,  KC_DOWN,  KC_UP,          KC_RGHT,   KC_DEL,
        LCMD(KC_Z),     LCMD(KC_X),     LCMD(KC_C),     LCMD(KC_V),      OSM(MOD_MEH),      KC_PGDN,  KC_BSPC,  OSM(MOD_RSFT),  KC_APP,    KC_PSCR,
                                                        XXXXXXX,         XXXXXXX,           KC_ENT,   QK_REP
    ),

    /* Symbols
     * .----------------------------------.          .----------------------------------.
     * |  !   |  @   |  #   |  :   |  []  |          |  =   |  7   |  8   |  9   |  +   |
     * |------+------+------+------+------|          |------+------+------+------+------|
     * |  \   |  &   |  {}  |  ()  |  ;   |          |  *   |  4   |  5   |  6   |  -   |
     * |------+------+------+------+------|          |------+------+------+------+------|
     * |  ^   |  _   |  %   |  $   |  ~   |          |  0   |  1   |  2   |  3   |  /   |
     * `--------------------.------+------|          |------+------.--------------------'
     *                      |  |   |  `   |          |      |      |
     *                      `-------------'          `-------------'
     */
    [_SYMBOLS] = LAYOUT(
        KC_EXLM,       KC_AT,    KC_HASH,      KC_COLN,      TD(TD_BRC),     KC_EQL,    KC_7,   KC_8,    KC_9,   KC_PLUS,
        KC_BSLS,       KC_AMPR,  TD(TD_CBR),   TD(TD_PRN),   KC_SCLN,        KC_PAST,   KC_4,   KC_5,    KC_6,   KC_PMNS,
        KC_CIRC,       KC_UNDS,  KC_PERC,      KC_DLR,       KC_TILD,        KC_0,      KC_1,   KC_2,    KC_3,   KC_PSLS,
                                               KC_PIPE,      KC_GRV,         XXXXXXX,   XXXXXXX
    ),

};
