# isodrive (halium)

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


Inspired by https://github.com/fredldotme/ISODriveUT
