// This is MJT's bastardization of the planck and minivan defaults

#pragma message "You may need to add LAYOUT_planck_grid to your keymap layers - see default for an example"
#include "planck.h"
#include "action_layer.h"
#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _PLOVER,
  _ADJUST,
  _FN
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  PLOVER,
  LOWER,
  RAISE,
  BACKLIT,
  EXT_PLV,
  MACSLEEP,
  DYNAMIC_MACRO_RANGE,
};

#include "dynamic_macro.h"

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  GUI |  Fn  | Alt  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFT_T(KC_ENT) },
  {KC_LCTL, KC_LGUI, MO(_FN), KC_LALT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |   *  |   4  |   5  |   6  |   -  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |   /  |   1  |   2  |   3  |   +  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |    Space    |      |   0  |   .  |   =  |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    XXXXXXX, KC_1,    KC_2,    KC_3,    		KC_4,    		KC_5,    		KC_6,     KC_7,     KC_8,    KC_9,     KC_0,     KC_BSPC, 
    XXXXXXX, XXXXXXX, XXXXXXX, DYN_MACRO_PLAY2, DYN_MACRO_PLAY1,DYN_REC_STOP, 	KC_ASTR,  KC_4,     KC_5,    KC_6,     KC_MINS,  XXXXXXX, 
    _______, XXXXXXX, XXXXXXX, DYN_REC_START2, 	DYN_REC_START1, XXXXXXX, 		KC_SLSH,  KC_1,     KC_2,    KC_3,     KC_PLUS,  MT(MOD_LSFT, KC_ENT), 
    _______, _______, _______, _______, 		_______, 		KC_SPC,  		KC_SPC,   _______,  KC_0,    KC_DOT,   KC_EQL,   XXXXXXX
),


/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   `  |      |      |   /  |   {  |   [  |   ]  |   }  |   \  |   -  |   =  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |   _  |   +  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |MENU  |      |      |      |    Space    |      | Home | PgDn | PgUp | End  |            
 * `-----------------------------------------------------------------------------------'
 */

[_RAISE] = LAYOUT_planck_grid(
    KC_TILD,   KC_EXLM, KC_AT, KC_HASH, KC_DLR,   KC_PERC,  KC_CIRC,  KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, 
    KC_GRV,  XXXXXXX, XXXXXXX, KC_SLSH,    KC_LCBR,  KC_LBRC,  KC_RBRC,  KC_RCBR, KC_BSLS, KC_MINS, KC_EQL,  KC_PIPE, 
    XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, KC_UNDS, KC_PLUS, MT(MOD_LSFT, KC_ENT), 
    _______,  KC_APP, _______, _______,    _______,  KC_SPC,   KC_SPC,   _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END
),


/* Plover layer (http://opensteno.org)
 * ,-----------------------------------------------------------------------------------.
 * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Exit |      |      |   A  |   O  |             |   E  |   U  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

[_PLOVER] = {
  {KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1   },
  {XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC},
  {XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {EXT_PLV, XXXXXXX, XXXXXXX, KC_C,    KC_V,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    XXXXXXX, XXXXXXX, XXXXXXX}
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |Reset |Macro1|Macro2|Macro3|Macro4|Macro5|Macro6|Macro7|Macro8|Macro9|Macro0|C-A-D |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Caps |      |      |Aud on|Audoff|      |AGswap|AGnorm| PrtSc|ScrLck| Break|      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |PLOVER|Voice-|Voice+|Mus on|Musoff| Prev | Next | Mute |Insert|VolDn |VolUp |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite|      |      |      |      | Play/Pause  |      | BL_T |BL_DEC|BL_INC|BL_ST |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_ortho_4x12( \
  RESET,	M(1), 	M(2), 	M(3), 	M(4), 	M(5), 	M(6), 	M(7), 	M(8), 	M(9), 	M(0), 	LALT(LCTL(KC_DEL)), \
  KC_CAPS, 	_______, _______, AU_ON,   AU_OFF, _______, AG_SWAP, AG_NORM,  KC_PSCR, KC_SLCK,  KC_PAUS,  _______, \
  PLOVER, 	MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  KC_MPRV, KC_MNXT,  KC_MUTE, KC_INS, KC_VOLD, KC_VOLU, _______, \
  BACKLIT, 	_______, _______, _______, _______, KC_MPLY, KC_MPLY, _______, BL_TOGG, BL_DEC , BL_INC , BL_STEP \
),

/* fn
 * ,-----------------------------------------------------------------------------------.
 * |DelWrd|  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |Wh Up |      | F11  | F12  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |Wh Dn |Lclick|Rclick| Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |    Space    |      |M-Left| M-Dn | M-Up | M-Rt |
 * `-----------------------------------------------------------------------------------'
 */
[_FN] = LAYOUT_planck_grid(
    LALT(KC_BSPC),  KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,    KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL, 
    XXXXXXX,        XXXXXXX, XXXXXXX, DYN_MACRO_PLAY2, DYN_MACRO_PLAY1,  XXXXXXX,  XXXXXXX,  XXXXXXX, KC_WH_U, XXXXXXX, KC_F11, KC_F12, 
    _______,        XXXXXXX, XXXXXXX, DYN_REC_START2, 	DYN_REC_START1,  XXXXXXX,  XXXXXXX,  XXXXXXX, KC_WH_D, KC_BTN1, KC_BTN2, MT(MOD_LSFT, KC_ENT), 
    _______,        _______, _______, _______, _______,  KC_SPC,   KC_SPC,   _______,  KC_MS_L, KC_MS_D,KC_MS_U, KC_MS_R
),


};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) // this is the function signature -- just copy/paste it into your keymap file as it is.
{
  switch(id) {
    case 0: 
      if (record->event.pressed) {
        return MACRO( D(LSFT), T(LEFT), U(LSFT), D(LCTL), T(X), U(LCTL), T(RIGHT), D(LCTL), T(V), U(LCTL), T(LEFT),  END  ); // this swaps the characters on either side of the cursor when the macro executes
      }
      break;
    case 1: 
      if (record->event.pressed) {
        SEND_STRING("shaozhen.song@gmail.com");
      }
      break;
	case 2: 
      if (record->event.pressed) {
        SEND_STRING("@pp1etree");
      }
      break;
	case 3: 
      if (record->event.pressed) {
        SEND_STRING("##Zz5522");
      }
      break;
	case 4: 
      if (record->event.pressed) {
        SEND_STRING("Sszz5522");
      }
      break;
	case 5: 
      if (record->event.pressed) {
        SEND_STRING("B@i1LORL");
      }
      break;
	case 6: 
      if (record->event.pressed) {
        SEND_STRING("B@i1nasjulythere");
      }
      break;
	case 7: 
      if (record->event.pressed) {
        SEND_STRING("julythere");
      }
      break;
	case 8: 
      if (record->event.pressed) {
        SEND_STRING("Julythere52");
      }
      break;
	case 9: 
      if (record->event.pressed) {
        SEND_STRING("szsong@uw.edu");
      }
      break;
  }
  return MACRO_NONE;
};


#ifdef AUDIO_ENABLE

float tone_startup[][2]    = SONG(STARTUP_SOUND);
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dyn_macro_rec[][2]     = SONG(DVORAK_SOUND);
float tone_dyn_macro_play[][2]    = SONG(COLEMAK_SOUND);
float tone_plover[][2]     = SONG(PLOVER_SOUND);
float tone_plover_gb[][2]  = SONG(PLOVER_GOODBYE_SOUND);
float music_scale[][2]     = SONG(MUSIC_SCALE_SOUND);

float tone_goodbye[][2] = SONG(GOODBYE_SOUND);
#endif

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  uint16_t macro_kc = (keycode == MO(_FN) ? DYN_REC_STOP : keycode);
  if (!process_record_dynamic_macro(macro_kc, record)) {
    return false;
  }
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistant_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
      } else {
        unregister_code(KC_RSFT);
      }
      return false;
      break;
    case PLOVER:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(tone_plover);
        #endif
        layer_off(_RAISE);
        layer_off(_LOWER);
        layer_off(_ADJUST);
        layer_on(_PLOVER);
        if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      return false;
      break;
    case EXT_PLV:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_plover_gb);
        #endif
        layer_off(_PLOVER);
      }
      return false;
      break;
    case MACSLEEP:
      if (record->event.pressed) {
          // ACTION_MODS_KEY(MOD_LCTL | MOD_LSFT, KC_POWER);
          register_code(KC_RSFT);
          register_code(KC_RCTL);
          register_code(KC_POWER);
          unregister_code(KC_POWER);
          unregister_code(KC_RCTL);
          unregister_code(KC_RSFT);
      }
      return false;
      break;
  }
  return true;
}

void matrix_init_user(void) {
    #ifdef AUDIO_ENABLE
        startup_user();
    #endif
}

#ifdef AUDIO_ENABLE

void startup_user()
{
    _delay_ms(20); // gets rid of tick
    PLAY_SONG(tone_startup);
}

void shutdown_user()
{
    PLAY_SONG(tone_goodbye);
    _delay_ms(150);
    stop_all_notes();
}

void music_on_user(void)
{
    music_scale_user();
}

void music_scale_user(void)
{
    PLAY_SONG(music_scale);
}

#endif
