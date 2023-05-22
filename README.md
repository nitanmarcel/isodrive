# isodrive (configfs)

* `sudo apt install build-essential`

* `git clone https://github.com/nitanmarcel/isodrive`

* `cd isodrive`

* `make`

* `sudo make install` (optional)

usage:

* `isodrive {iso} {cdrom[0/1]} {readonly[1/0]}`

mount

* `sudo isodrive /full/path/to/file.iso`

umount

* `sudo isodrive`

mount (as cdrom)

* `sudo isodrive /full/path/to/file.iso 1 1`

mount (as read write)

* `sudo isodrive /full/path/to/file.iso 0 0`

## Linux
* _Has been only tested on Halium based mobile linux, but should work on mainline devices too._

## Android

* _On Android you must be compiled in termux, using clang++_
* _On Android you might manually need to mount configfs by running: `mount -t configfs configfs /sys/kernel/config`_

## Os Support
* _Should support almost every bootable OS images, but for those who don't work or need extra steps, are documented in the [WIKI](https://github.com/nitanmarcel/isodrive/wiki)_

## Credits

Inspired by https://github.com/fredldotme/ISODriveUT
