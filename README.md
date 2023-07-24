# isodrive (configfs)

## Building

* `sudo apt install build-essential`

* `git clone https://github.com/nitanmarcel/isodrive`

* `cd isodrive`

* `make`

* `sudo make install` (optional)

## Usage

```bash
isodrive [FILE]... [OPTION]...
Mounts the given FILE as a bootable device using configfs.
Run without any arguments to unmount any mounted files and to display this help message.

Optional arguments:
-rw	 Mounts the file in read write mode.
-cdrom	 Mounts the file as a cdrom.
```

### Examples

mount iso as rw
```bash
isodrive /path/to/file.iso -rw
```

mount iso as cdrom
```bash
isodrive /path/to/file.iso -cdrom
```

## Linux
* Has been only tested on Halium based mobile linux, but should work on mainline devices too.

## Android

* On Android can be compiled in termux, using clang++
* On Android you might manually need to mount configfs by running: `mount -t configfs configfs /sys/kernel/config`
* A magisk module is also available for download [HERE](https://github.com/nitanmarcel/isodrive-magisk/releases/latest)

## Os Support
* Should support almost every bootable OS images, but for those who don't work or need extra steps, are documented in the [WIKI](https://github.com/nitanmarcel/isodrive/wiki)

## Credits

Inspired by https://github.com/fredldotme/ISODriveUT
