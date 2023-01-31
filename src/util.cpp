#include <fcntl.h>   
#include <mntent.h>  
#include <stdio.h>   
#include <string.h>  
#include <sys/stat.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <array>
#include <memory>


// https://stackoverflow.com/a/123724
void trim(char *s)
{
	char * p = s;
	int l = strlen(p);
	while(isspace(p[l - 1])) p[--l] = 0;
	while(* p && isspace(* p)) ++p, --l;

	memmove(s, p, l + 1);
}

char *fs_mount_point(char *filesystem_type) {
	struct mntent *ent;
	FILE *mounts;
	char *mount_point = NULL;

	mounts = setmntent("/proc/mounts", "r");
	while (NULL != (ent = getmntent(mounts))) {
		if (strcmp(ent->mnt_fsname, filesystem_type) == 0)
		{
			mount_point = ent->mnt_dir;
			break;
		}
	}
	return mount_point;
}

char *strjin(char *w1, char *w2)
{
	char *s = new char[strlen(w1)+strlen(w2)+1];
	strcpy(s, w1);
	strcat(s, w2);
	return s;
}

bool isdir(char *path)
{
	struct stat sb;
	if (stat(path, &sb) == 0)
		return true;
	else
		return false;
}

void sysfs_write(char *path, char *content)
{
	std::cout << "Write: " << content << " -> " << path << std::endl;
	int fd;
	if (fd = open(path, O_WRONLY) == -1)
	{
		perror("Failed to open sysfs file");
		return;
	}
	if (write(fd, content, strlen(content) == -1))
	{
		perror("Failed to write sysfs file");
	}
	close(fd);
}


char *getprop(char *key)
{
	std::array<char, 128> buffer;
	char *value;
	char *cmd = strjin("getprop ", key);
	std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
	while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr)
		value = strjin("", buffer.data());
	trim(value);
	return value;

}



