/*
 * Frosted version of thread_join.
 */

#include "syscall_table.h"
#include <errno.h>
extern int sys_thread_join(int pid, unsigned long timeout);

int thread_join(int pid, unsigned long timeout)
{
    errno = ENOSYS;
    return -1;
}

