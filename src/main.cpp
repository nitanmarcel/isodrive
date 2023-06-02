#include "configfsisomanager.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
  char *iso_target = (char *)"";
  char *cdrom      = (char *)"0";
  char *ro         = (char *)"1";

  for (int i = 1; i < argc; i++)
  {
    if (strcmp(argv[i], "-rw") == 0)
    {
      ro = (char *)"0";
    }
    else if (strcmp(argv[i], "-cdrom") == 0)
    {
      cdrom = (char *)"1";
    }
    else
    {
      iso_target = argv[i];
    }
  }

  if (argc == 1)
  {
    printf("Usage:\n");
    printf("cdrom [FILE]... [OPTION]...\n");
    printf("Mounts the given FILE as a bootable device using configfs.\n");
    printf(
      "Run without any arguments to unmount any mounted files and display this help message.\n\n");

    printf("Optional arguments:\n");
    printf("-rw\t Mounts the file in read write mode.\n");
    printf("-cdrom\t Mounts the file as a cdrom.\n\n");
    printf("UMOUNT:\n");
  }
  else
  {
    printf("MOUNT:\n");
  }

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

  mount_iso(iso_target, cdrom, ro);

  return 0;
}
