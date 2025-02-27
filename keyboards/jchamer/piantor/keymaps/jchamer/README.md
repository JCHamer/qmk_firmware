# Jonathan's Piantor Layout

A minimized Piantor layout with a Colemak-ModDH base as well as movement, numrow, numpad, and function layers.

## Features

- Base Layers
    - Colemak-ModDH
- Movement layer
- Function layer
- Numrow layer
- Numpad layer

## Building and flashing

1. Put your board in bootloader mode by holding the BOOTSEL button while connecting or while pressing the NRST button, or with a software key in your current firmware
1. Flash left half from the keymap directory:
    ```bash
    $ qmk flash -bl uf2-split-left
    ```
1. Flash right half:
    ```bash
    $ qmk flash -bl uf2-split-right
    ```

