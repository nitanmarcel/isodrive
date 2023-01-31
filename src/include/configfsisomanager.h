#ifndef CONFIGFSISOMANAGER_H
#define CONFIGFSISOMANAGER_H

char *get_gadget_root();
char *get_config_root();

void mount_iso(char *iso_path);
void set_udc();
void reset_udc();

#endif
