/*
* Frosted version of getsockopt
*/


#include "syscall_table.h"
#include <netinet/in.h>
#include <errno.h>
extern int sys_getsockopt(int sd, int level, int optname, void *optval, unsigned int *optlen);


int getsockopt(int sd, int level, int optname, void *optval, socklen_t *optlen)
{
    int ret = sys_getsockopt(sd, level, optname, optval, (unsigned int *)optlen);
    if (ret < 0) {
        errno = 0 - ret;
        ret = -1;
    }
    return ret;
}
