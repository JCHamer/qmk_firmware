# Jonathan's ErgoDox Infinity Layout

A partially minimized ErgoDox layout with a Colemak-ModDH base as well as movement, numpad, and function layers.

## Features

- Base Layers
    - Colemak-ModDH
- Movement layer
- Function layer
- Numpad layer

## Building and flashing

1. Put your board in DFU mode with either the button on the bottom, or with a software key in your current firmware
1. Flash left half from the keymap directory:
    ```bash
    $ qmk flash -bl dfu-util-split-left
    ```
1. Flash right half:
    ```bash
    $ qmk flash -bl dfu-util-split-right
    ```
