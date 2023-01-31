#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>

#include "util.h"
#include "configfsisomanager.h"
#include <dirent.h>
#include <unistd.h>

char *get_gadget_root()
{
	char *configFsRoot = fs_mount_point("configfs");
	char *usbGadgetRoot = strjin(configFsRoot, "/usb_gadget/"); 
	char *gadgetRoot = nullptr;

	struct dirent *entry = nullptr;
	DIR *dp = nullptr;
	dp = opendir(usbGadgetRoot);
	if (dp != nullptr)
		while ((entry = readdir(dp)))
		{
			if (entry->d_name[0] != '.')
			{
				gadgetRoot = strjin(usbGadgetRoot, entry->d_name);
				break;
			}
		}
	return gadgetRoot;
}

char *get_config_root()
{
	char *gadgetRoot = get_gadget_root();
	char *usbConfigRoot = strjin(gadgetRoot, "/configs/");
	char *configRoot = nullptr;

	struct dirent *entry = nullptr;
	DIR *dp = nullptr;
	dp = opendir(usbConfigRoot);
	if (dp != nullptr)
		while ((entry = readdir(dp)))
		{
			if (entry->d_name[0] != '.')
			{
				configRoot = strjin(usbConfigRoot, entry->d_name);
				break;
			}
		}
	return configRoot;
}

void mount_iso(char *iso_path)
{
	char *gadgetRoot = get_gadget_root();
	char *configRoot = get_config_root();

	char *functionRoot = strjin(gadgetRoot, "/functions");
	char *massStorageRoot = strjin(functionRoot, "/mass_storage.0");
	char *lunRoot = strjin(massStorageRoot, "/lun.0");
	
	char *stallFile = strjin(massStorageRoot, "stall");
	char *udcFile = strjin(gadgetRoot, "/UDC");
	char *lunFile = strjin(lunRoot, "/file");
	char *lunCdRom = strjin(lunRoot, "/cdrom");
	char *lunRo = strjin(lunRoot, "/ro");

	reset_udc();
	if (!isdir(massStorageRoot))
	{
		mkdir(massStorageRoot, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
	}
	if (!isdir(strjin(configRoot, "/mass_storage.0")))
	{
		symlink(massStorageRoot, strjin(configRoot, "/mass_storage.0"));
	}
	sysfs_write(lunFile, iso_path);
	sysfs_write(lunCdRom, "1");
	sysfs_write(lunRo, "1");

	set_udc();
}

void reset_udc()
{
	char *gadget_root = get_gadget_root();
	char *udcFile = strjin(gadget_root, "/UDC");
	sysfs_write(udcFile, "");
}

void set_udc()
{
	char *gadget_root = get_gadget_root();
	char *udcFile = strjin(gadget_root, "/UDC");
	sysfs_write(udcFile, getprop("sys.usb.controller"));
}
