#ifndef ANDROIDUSBISOMANAGER_H
#define ANDROIDUSBISOMANAGER_H

#define ANDROID0_SYSFS_ENABLE "/sys/devices/virtual/android_usb/android0/enable"
#define ANDROID0_SYSFS_IMG_FILE                                                \
  "/sys/devices/virtual/android_usb/android0/f_mass_storage/lun/file"
#define ANDROID0_SYSFS_FEATURES                                                \
  "/sys/devices/virtual/android_usb/android0/functions"

bool usb_supported();

void usb_mount_iso(char *iso_path);
void usb_umount_iso();
void usb_reset_iso();

bool usb_enabled();
void usb_set_enabled(bool enabled);
char *usb_get_udc();

#endif // ifndef ANDROIDUSBISOMANAGER_H
