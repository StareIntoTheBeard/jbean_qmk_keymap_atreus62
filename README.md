# jbean_qmk_keymap_atreus62

personal qmk keymap for an atreus62 board setup to be used as a git submodule.

### Setup
* Pull [QMK](https://github.com/qmk/qmk_firmware)
* Follow the [quick start](https://github.com/technomancy/tmk_keyboard/blob/atreus/keyboard/atreus/README.md#quick-start) guide 
* in `keyboards/atreus62/keymaps` run `git submodule add https://github.com/StareIntoTheBeard/jbean_qmk_keymap_atreus62.git`
* run `git submodule init`

### Building
* From firmware base dir, run `make atreus62`
* Put board into DFU mode and run `avrdude -p atmega32u4 -c avr109 -U flash:w:atreus62_jbean_qmk_keymap_atreus62.hex -P /dev/cu.usbmodem1411`

### Figuring out what dev port your board is on
* https://github.com/technomancy/tmk_keyboard/blob/atreus/keyboard/atreus/README.md#uploading-on-debianmac

### Updating
* Make changes in this repo, push and on the local QMK repo, run `git pull --recurse-submodules`
