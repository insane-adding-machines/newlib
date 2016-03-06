/*
 * Frosted version of write.
 */

#include "syscall_table.h"
#include <errno.h>
extern int sys_write(int file, const void *ptr, int len);

int write (int file, const void *ptr, int len)
{
    int ret = sys_write(file, ptr, len);
    if (ret < 0) {
        errno = 0 - ret;
        ret = -1;
    }
    return ret;
}
