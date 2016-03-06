/*
 * Frosted version of closedir.
 */

#include "syscall_table.h"
#include <errno.h>
#include <dirent.h>
extern int sys_closedir(DIR *d);

int closedir(DIR *d)
{
    int ret = sys_closedir(d);
    if (ret < 0) {
        errno = 0 - ret;
        ret = -1;
    }
    return ret;
}

