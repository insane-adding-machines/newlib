/*
 * Frosted version of setpriority.
 */

#include "sys/frosted.h"
#include "sys/resource.h"
#include <sys/types.h>
#include <unistd.h>

#include <errno.h>
extern int sys_setpriority(int which, id_t pid, int prio);

int setpriority(int which, id_t pid, int prio)
{
    int ret;
    if (which != PRIO_PROCESS) {
       errno = EINVAL;
       return -1;
    }
    ret = sys_setpriority(which, pid, prio);
    if (ret < 0) {
        errno = 0 - ret;
        ret = -1;
    }
    return ret;
}

int nice(int inc)
{
    int pid = getpid();
    int prio = getpriority(PRIO_PROCESS, pid);
    if (errno != 0)
        return -1;

    prio += inc;

    if (pid > 0) {
        setpriority(PRIO_PROCESS, pid, prio);
    } else
        return -1;
}
