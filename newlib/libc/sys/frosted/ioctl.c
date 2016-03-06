/*
 * Frosted version of ioctl.
 */

#include "syscall_table.h"
#include <errno.h>
extern int sys_ioctl(int fd, const unsigned long cmd, void *arg);

int ioctl (int fd, const unsigned long cmd, void *arg)
{
    int ret = sys_ioctl(fd, cmd, arg);
    if (ret < 0) {
        errno = 0 - ret;
        ret = -1;
    }
    return ret;
}
