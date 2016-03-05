/*
 * Frosted version of sleep.
 */

#include "frosted_api.h"
#include "syscall_table.h"
#include <errno.h>
extern int sys_sleep(int s);

int sleep(int s)
{
    int ret = sys_sleep(s);
    if (ret < 0) {
        errno = 0 - ret;
        ret = -1;
    }
    return ret;
}

