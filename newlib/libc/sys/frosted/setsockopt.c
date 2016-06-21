/*
* Frosted version of setsockopt
*/


#include "sys/frosted.h"
#include <sys/socket.h>
#include <errno.h>
extern int sys_setsockopt(int sd, int level, int optname, const void *optval, unsigned int optlen);


int setsockopt(int sd, int level, int optname, const void *optval, socklen_t optlen)

{
    int ret = sys_setsockopt(sd, level, optname, optval, optlen);
    if (ret < 0) {
        errno = 0 - ret;
        ret = -1;
    }
    return ret;
}
