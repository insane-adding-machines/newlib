/*
 * Frosted version of ptrace.
 */

#include <errno.h>
#include <sys/ptrace.h>

int ptrace(enum __ptrace_request request, pid_t pid, void *data, void *addr)
{
    int ret = sys_ptrace(request, pid, data, addr);
    if (ret < 0) { 
        errno = 0 - ret;
        return -1;
    }
    return ret;

}

