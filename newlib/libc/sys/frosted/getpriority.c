/*
 * Frosted version of getpriority.
 */

#include "sys/frosted.h"
#include "sys/resource.h"
#include <errno.h>
extern int sys_getpriority(int which, id_t pid);

int getpriority(int which, id_t pid)
{
    int ret;
    if (which != PRIO_PROCESS) {
       errno = EINVAL;
       return -1;
    }

    errno = 0;
    ret = sys_getpriority(which,pid);
    if (ret < (-20)) {
        errno = ESRCH;
        ret = -1;
    }
    return ret;
}

