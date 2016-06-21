/*
* Frosted version of sigprocmask
*/


#include "sys/frosted.h"
#include <signal.h>
#include <errno.h>
extern int sys_sigprocmask(int how, const sigset_t *set, sigset_t *oldset);

int sigprocmask(int how, const sigset_t *set, sigset_t *oldset)
{
    int ret = sys_sigprocmask(how, set, oldset);
    if (ret < 0) {
        errno = 0 - ret;
        ret = -1;
    }
    return ret;
}
