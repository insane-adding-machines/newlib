/*
* Frosted version of connect
*/


#include "frosted_api.h"
#include "syscall_table.h"
#include <netinet/in.h>
#include <errno.h>
#undef errno
extern int errno;
extern int sys_connect(int sd, const struct sockaddr_env *se);

int connect(int sd, const struct sockaddr *sa, socklen_t socklen)
{
    struct sockaddr_env se;
    int ret;
    se.se_addr = sa;
    se.se_len = socklen;
    return sys_connect(sd, &se);
}
