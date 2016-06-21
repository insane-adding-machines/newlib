/*
 * Frosted version of close.
 */

#include "sys/frosted.h"
#include <errno.h>
extern int sys_close(int fd);

int close(int fd)
{
    int ret;
    ret = sys_close(fd);
    if (ret < 0) {
        errno = 0 - ret;
        ret = -1;
    }
    return ret;
}

