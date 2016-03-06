/*
 * Frosted version of opendir.
 */

#include "syscall_table.h"
#include <errno.h>
#include <dirent.h>
extern DIR *sys_opendir(const char *path);

DIR *opendir(const char *path)
{
    return sys_opendir(path);
}

