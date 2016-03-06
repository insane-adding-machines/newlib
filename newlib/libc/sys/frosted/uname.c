/*
 * Frosted version of uname.
 */

#include "syscall_table.h"
#include <errno.h>
#include <sys/utsname.h>
extern int sys_uname(struct utsname *u);

int uname(struct utsname *u)
{
    int ret = sys_uname(u);
    if (ret < 0) {
        errno = 0 - ret;
        ret = -1;
    }
    return ret;
}
