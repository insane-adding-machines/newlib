/*
* Frosted version of connect
*/


#include "frosted_api.h"
#include "syscall_table.h"
#include <netinet/in.h>
#include <errno.h>
extern int sys_connect(int sd, const struct sockaddr_env *se);

int connect(int sd, const struct sockaddr *sa, socklen_t socklen)
{
    struct sockaddr_env se;
    int ret;
    se.se_addr = sa;
    se.se_len = socklen;
    ret = sys_connect(sd, &se);
    if (ret < 0) {
        errno = 0 - ret;
        ret = -1;
    }
    return ret;
}
