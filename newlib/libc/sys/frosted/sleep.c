/*
 * Frosted version of sleep.
 */

#include "syscall_table.h"
#include <errno.h>
extern int sys_sleep(int ms);

int sleep(int s)
{
    int ret = sys_sleep(s * 1000);
    if (ret < 0) {
        errno = 0 - ret;
        ret = -1;
    }
    return ret;
}

int usleep(int us)
{
    int ret = sys_sleep(us / 1000);
    if (ret < 0) {
        errno = 0 - ret;
        ret = -1;
    }
    return ret;
}

