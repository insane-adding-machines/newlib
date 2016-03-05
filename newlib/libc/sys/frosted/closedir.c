/*
 * Frosted version of closedir.
 */

#include "frosted_api.h"
#include "syscall_table.h"
#include <errno.h>
extern int sys_closedir(DIR *d);

int closedir(DIR *d)
{
    int ret = sys_closedir(d);
    if (ret < 0) {
        errno = 0 - ret;
        ret = -1;
    }
    return ret;
}

