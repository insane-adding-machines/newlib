/*
 * Frosted version of fcntl.
 */

#include "syscall_table.h"
#include <errno.h>
extern int sys_fcntl(int fd, int cmd, unsigned int arg);

int fcntl(int fd, int cmd, unsigned int arg)
{
    int ret = sys_fcntl(fd, cmd, arg);
    if (ret < 0) {
        errno = 0 - ret;
        ret = -1;
    }
    return ret;
}
