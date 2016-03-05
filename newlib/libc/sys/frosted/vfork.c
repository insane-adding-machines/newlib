#include <sys/types.h>
#include <errno.h>

pid_t vfork(void)
{
    pid_t newpid = sys_vfork();
    if (newpid == getpid())
        return 0;
    if (newpid < 0) {
        errno = 0 - newpid;
        newpid = -1;
    }
    return newpid;
}


