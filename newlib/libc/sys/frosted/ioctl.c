/*
 * Frosted version of ioctl.
 */

#include "frosted_api.h"
#include "syscall_table.h"
#include <errno.h>
extern int sys_ioctl(int fd, const uint32_t cmd, void *arg);

int ioctl (int fd, const uint32_t cmd, void *arg)
{
    int ret = sys_ioctl(fd, cmd, arg);
    if (ret < 0) {
        errno = 0 - ret;
        ret = -1;
    }
    return ret;
}
