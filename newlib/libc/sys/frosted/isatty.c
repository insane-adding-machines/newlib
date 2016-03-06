/*
 * Frosted version of isatty.
 */

#include "syscall_table.h"
#include <errno.h>
extern int sys_isatty(int fd);

int isatty(int fd)
{
    int ret = sys_isatty(fd);
    if (ret < 0) {
        errno = 0 - ret;
        ret = -1;
    }
    return ret;
}

