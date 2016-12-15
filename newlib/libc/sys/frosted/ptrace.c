/*
 * Frosted version of ptrace.
 */

#include "sys/ptrace.h"
#include <errno.h>
extern int sys_ptrace(int, int, void *, void *);

int ptrace( enum __ptrace_request request, pid_t pid, void *addr, void *data)
{
    return sys_ptrace(request, pid, addr, data);
}
