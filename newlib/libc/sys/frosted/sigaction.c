/*
* Frosted version of sigaction
*/


#include "sys/frosted.h"
#include <signal.h>
#include <errno.h>
extern int sys_sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);


int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact)
{
    int ret = sys_sigaction(signum, act, oldact);
    if (ret < 0) {
        errno = 0 - ret;
        ret = -1;
    }
    return ret;
}
