# cocot
## How to build

1. Check out this repository.

    ```console
    $ git clone https://github.com/archfill/qmk-cocot.git qmk-cocot
    ```

2. Check out [qmk/qmk_firmware](https://github.com/qmk/qmk_firmware/) repository in another place.

    ```console
    $ git clone https://github.com/qmk/qmk_firmware.git --depth 1 --recurse-submodules --shallow-submodules -b 0.18.17 qmk
    ```
3. Create a symbolic link to this `cocot/` directory from [qmk/qmk_firmware]'s `keyboards/` directory.

    ```console
    $ ls
    qmk-cocot/ qmk/

    $ cd qmk/keyboards
    $ ln -s ../../qmk-cocot/qmk_firmware/keyboards/cocot cocot
    ```

4. `make` your Keyball firmwares.

    ```console
    $ make cocot/cocot46plus:default
    ```

## How to create your keymap

(to be documented)
