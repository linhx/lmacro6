# lmacro6

A simple 6-keys macropad with two rotary encoders.

* Keyboard Maintainer: [Linhx](https://github.com/linhx)
* Hardware Supported: atmega32u4
* Hardware Availability: https://github.com/linhx/lmacro6

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Default layout

```plaintext
| F20            |            | Mute        |
| Ctrl + F12     | Alt + Left | Alt + Right |
| Ctrl + Alt + T |            |             |

* Left rotary encoder: Switch layer
* Right rotary encoder: Volume up/down
```

### useful macros (config via VIA)

* Open terminal in a directory (Nautilus Ubuntu): {KC_F10}{500}{KC_LALT,KC_E}
