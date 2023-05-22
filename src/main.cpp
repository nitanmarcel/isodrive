#include "configfsisomanager.h"
#include <unistd.h>
#include <stdio.h>

int main(int argc, char* argv[]){
	char *iso_target = argv[1];
	char *cdrom = (char*)"0";
	char *ro = (char*)"1";

	if (!supported())
	{
		printf("Device does not support configfs usb gadget\n");
		return 1;
	}
	if (getuid() != 0)
	{
		printf("Permission denied\n");
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
