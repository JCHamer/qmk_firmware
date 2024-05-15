# Jonathan's Mod of DudeOfAwesome's ErgoDox Infinity Layout

Tapping used from the Gordon ErgoDoxInfinity Layout.

A basic ErgoDox layout with a Colemak base as well as numpad and function layers.

## Features

- Base Layers
    - Colemak
- Function layer
- Numpad layer
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
