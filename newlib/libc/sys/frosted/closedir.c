/*
 * Frosted version of closedir.
 */

#include "sys/frosted.h"
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

