#include "syscalls.h"
#include "sys/frosted.h"
#include "sys/pty.h"
#include "errno.h"

#define PTSNAME_LEN 20
static char *__ptsname = NULL;

extern int sys_ptsname(int fd, char *name, int len); 


char *ptsname(int fd)
{
    int ret;
    errno = 0;
    if (!__ptsname) {
        __ptsname = malloc(PTSNAME_LEN);
        if (!__ptsname) {
            errno = ENOMEM;
            return NULL;
        }
    }
    ret  = sys_ptsname(fd, __ptsname, PTSNAME_LEN);
    if (ret < 0) {
        errno = 0 - ret;
        return NULL;
    }
    return __ptsname;
}

int ptsname_r(int fd, char *buf, size_t buflen)
{
    int ret;
    errno = 0;
    ret = sys_ptsname(fd, buf, buflen);
    if (ret < 0) {
        errno = 0 - ret;
        return -1;
    }
    return ret;
}

int grantpt(int fd)
{
    errno = 0;
    if (fd >= 0)
        return 0;
    errno = EINVAL;
    return -1;
}

int unlockpt(int fd)
{
    errno = 0;
    if (fd >= 0)
        return 0;
    errno = EINVAL;
    return -1;
}

int posix_openpt(int flags)
{
    return open("/dev/ptmx", flags);
}

int openpt(int flags)
{
    return posix_openpt(flags);
}

