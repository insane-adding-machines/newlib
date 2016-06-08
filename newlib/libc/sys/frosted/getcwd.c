/*
 * Frosted version of getcwd.
 */

#include "syscall_table.h"
#include <errno.h>
extern char * sys_getcwd(char *, int);

char *getcwd(char *buf, int size)
{
    int ret = 0;
    if (buf)
        ret = sys_getcwd(buf, size);
    if (ret == 0)
        errno = -EFAULT;
    return ret;
}
