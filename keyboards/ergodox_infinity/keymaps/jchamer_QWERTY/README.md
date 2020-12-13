# Jonathan's Mod of DudeOfAwesome's ErgoDox Infinity Layout

A basic ErgoDox layout with a Colemak and QWERTY base as well as numpad and function layers.

![ErgoDox Layout](https://i.imgur.com/ae0Phzb.png)

## Features

- Base Layers
    - Colemak
    - QWERTY
- Numpad layer
    ![numpad layer](https://i.imgur.com/oHDYpzf.png)
- LCD colors are linked together, like the default KLL firmware

## Building and flashing

1. Put your board in DFU mode with either the button on the bottom, or with a software key in your current firmware
1. Flash left half:
    ```bash
    $ make ergodox_infinity:mod_dudeofawesome:dfu-util
    ```
1. Flash right half:
    ```bash
    $ make ergodox_infinity:mod_dudeofawesome:dfu-util MASTER=right
    ```
