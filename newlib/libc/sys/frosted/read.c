/*
 * Frosted version of read.
 */

#include "sys/frosted.h"
#include <errno.h>
extern int sys_read(int file, void *ptr, int len);

int read(int file, void *ptr, int len)
{
    int ret = sys_read(file, ptr, len);
    if (ret < 0) {
        errno = 0 - ret;
        ret = -1;
    }
    return ret;
}
