/*
 * Frosted version of poll.
 */

#include "frosted_api.h"
#include "syscall_table.h"
#include <errno.h>

struct pollfd;

extern int sys_poll(struct pollfd *pfd, int nfds, int timeout);

int poll(struct pollfd *pfd, int nfds, int timeout)
{
    int ret = sys_poll(pfd, nfds, timeout);
    if (ret < 0) {
        errno = 0 - ret;
        ret = -1;
    }
    return ret;
}
