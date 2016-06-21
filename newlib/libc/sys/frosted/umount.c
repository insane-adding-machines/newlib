/*
 * Frosted version of umount.
 */

#include "sys/frosted.h"
#include <errno.h>
extern int sys_umount(char *target, unsigned long flags);

int umount(char *target)
{
    int ret;
    ret = sys_umount(target, 0);
    if (ret < 0) {
        errno = 0 - ret;
        ret = -1;
    }
    return ret;
}

int umount2(char *target, unsigned long flags)
{
    int ret;
    ret = sys_umount(target, flags);
    if (ret < 0) {
        errno = 0 - ret;
        ret = -1;
    }
    return ret;
}

