#include <sys/resource.h>
#include <errno.h>

int getrlimit(int resource, struct rlimit *rlim)
{
    rlim->rlim_cur = RLIM_INFINITY;
    rlim->rlim_max = RLIM_INFINITY;
    return 0;
}
int setrlimit(int resource, const struct rlimit *rlim)
{
    errno = ENOSYS;
    return -1;
}

