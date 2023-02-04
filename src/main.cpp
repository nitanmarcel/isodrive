#include "configfsisomanager.h"
#include <iostream>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char* argv[]){
	char *iso_target = argv[1];
	char *cdrom = (char*)"0";
	char *ro = (char*)"1";

	if (!supported())
	{
		std::cerr << "Device does not support configfs usb gadget" << std::endl;
		return 1;
	}
	if (getuid() != 0)
	{
		std::cerr << "Permission denied" << std::endl;
		return 1;
	}
	if (argc == 1)
	{
		iso_target = (char*)"";
	}

	if (argc > 2)
	{
		cdrom = argv[2];
	}
	if (argc > 3)
	{
		ro = argv[3];
	}

	mount_iso(iso_target, cdrom, ro);

	return 0;
}
