/*
 * Frosted version of mkdir.
 */

#include "sys/frosted.h"
#include "sys/types.h"
#include <errno.h>
extern int sys_mkdir(const char *path, mode_t mode);

int mkdir(const char *path, mode_t mode)
{
    int ret = sys_mkdir(path, mode);
    if (ret < 0) {
        errno = 0 - ret;
        ret = -1;
    }
    return ret;
}

