#include "configfsisomanager.h"
#include <iostream>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char* argv[]){
	char *iso_target = argv[1];
	if (getuid() != 0)
	{
		std::cerr << "Permission denied" << std::endl;
		return 1;
	}
	if (argc == 1)
	{
		iso_target = "";
	}
	mount_iso(iso_target);
}
