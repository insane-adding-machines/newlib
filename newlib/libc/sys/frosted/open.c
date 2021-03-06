/*
 * Frosted version of open.
 */

#include "sys/frosted.h"
#include <errno.h>
extern int sys_open(char * file, int flags, int mode);

int open(char *file, int flags, int mode)
{
    int ret = sys_open(file, flags, mode);
    if (ret < 0) {
        errno = 0 - ret;
        ret = -1;
    }
    return ret;
}
