#include <sys/stat.h>
#include <sys/types.h>

#include "androidusbisomanager.h"
#include "util.h"
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

bool usb_supported() { return isfile((char *)ANDROID0_SYSFS_ENABLE); }

void usb_mount_iso(char *iso_path) {

  if (usb_enabled())
    usb_set_enabled(false);

  sysfs_write((char *)ANDROID0_SYSFS_IMG_FILE, iso_path);

  char *features = (char *)"mass_storage";

  sysfs_write((char *)ANDROID0_SYSFS_FEATURES, features);

  usb_set_enabled(true);
}

void usb_reset_iso() {
  usb_mount_iso((char *)"");

  if (usb_enabled())
    usb_set_enabled(false);

  char *features = (char *)"mtp";

  sysfs_write((char *)ANDROID0_SYSFS_FEATURES, features);

  usb_set_enabled(true);
}

bool usb_enabled() {
  return strcmp(sysfs_read((char *)ANDROID0_SYSFS_ENABLE), "1") == 0;
}

void usb_set_enabled(bool enabled) {
  if (enabled)
    sysfs_write((char *)ANDROID0_SYSFS_ENABLE, (char *)"1");
  else
    sysfs_write((char *)ANDROID0_SYSFS_ENABLE, (char *)"0");
}