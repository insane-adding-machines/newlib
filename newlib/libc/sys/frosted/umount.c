/*
 * Frosted version of umount.
 */

#include "syscall_table.h"
#include <errno.h>
extern int sys_umount(char *target, unsigned long flags);

int umount(char *target, unsigned long flags)
{
    int ret;
    (void)flags; /* flags unimplemented for now */
    ret = sys_umount(target, flags);
    if (ret < 0) {
        errno = 0 - ret;
        ret = -1;
    }
    return ret;
}
