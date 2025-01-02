# QMK Userspace

This repo contains the different layouts for my keyboard(s).

## Layouts

-   [Corne V4.1](keyboards/crkbd/rev4_1/standard/keymaps/ntw1vnl/README.md)

## Setup

### Prepare QMK environment

Whe are going to install the QMK CLI using a python virtual environment.

#### Create the venv.

```bash
python3 -m venv ~/kbd/qmk_env
```

#### Activate the venv.

```bash
source ~/kbd/qmk_venv/bin/activate
```

#### Install the QMK CLI.

```bash
python3 -m pip install qmk
```

#### Run qmk setup.

```bash
qmk setup -H ~/kbd/qmk_firmware
qmk config user.keyboard=crkbd/rev4_1/standard
```

#### Clone this repository.

```bash
cd ~/bkd
git clone https://github.com/ntw1vnl/qmk_userspace.git
```

#### Enable QMK userspace in QMK config

```bash
qmk config user.overlay_dir="$(realpath qmk_userspace)"
```

### Build and flash firmware

#### Make sure the the venv is activated.

```bash
source ~/kbd/qmk_venv/bin/activate
```

#### Build the firmware.

```bash
qmk compile -kb crkbd/rev4_1/standard -km ntw1vnl
```

or

```bash
qmk userspace-compile

```

#### Flash the firmware

1. Connect the first side while in bootloader mode.
1. Mount the device.
1. Go to userspace directory : `cd ~/kbd/qmk_userspace`
1. Copy the firmware : `cp ./crkbd_rev4_1_standard_keymap.uf2 /run/media/username/RPI-RP2`
1. Repeat for the other side.
