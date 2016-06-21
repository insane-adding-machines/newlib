/*
* Frosted version of sigsuspend
*/


#include "sys/frosted.h"
#include <signal.h>
#include <errno.h>
extern int sys_sigsuspend(const sigset_t mask);


int sigsuspend(const sigset_t mask)
{
    int ret = sys_sigsuspend(mask);
    if (ret < 0) {
        errno = 0 - ret;
        ret = -1;
    }
    return ret;
}
