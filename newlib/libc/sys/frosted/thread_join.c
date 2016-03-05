/*
 * Frosted version of thread_join.
 */

#include "frosted_api.h"
#include "syscall_table.h"
#include <errno.h>
extern int sys_thread_join(int pid, uint32_t timeout);

int thread_join(int pid, uint32_t timeout)
{
    int ret = sys_thread_join(pid, timeout);
    if (ret < 0) {
        errno = 0 - ret;
        ret = -1;
    }
    return ret;
}

