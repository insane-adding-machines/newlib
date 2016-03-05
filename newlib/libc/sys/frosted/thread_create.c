/*
 * Frosted version of thread_create.
 */

#include "frosted_api.h"
#include "syscall_table.h"
#include <errno.h>
extern int sys_thread_create(void (*)(void *), void *, unsigned int);

int thread_create(void (*init)(void *), void *arg, unsigned int prio)
{
    int ret = sys_thread_create(init, arg, prio);
    if (ret < 0) {
        errno = 0 - ret;
        ret = -1;
    }
    return ret;
}

