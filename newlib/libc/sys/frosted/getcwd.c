/*
 * Frosted version of getcwd.
 */

#include "syscall_table.h"
#include <errno.h>
extern char * sys_getcwd(char *, int);

char *getcwd(char *buf, int size)
{
    int ret = sys_getcwd(buf, size);
    if (ret < 0) {
        errno = 0 - ret;
        ret = -1;
    }
    return ret;
}
