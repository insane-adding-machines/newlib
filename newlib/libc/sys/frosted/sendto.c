/*
* Frosted version of sendto
*/


#include "frosted_api.h"
#include "syscall_table.h"
#include <sys/socket.h>
#include <errno.h>
#undef errno
extern int errno;
extern int sys_sendto(int sd, const void *buf, unsigned int len, int flags, struct sockaddr_env *se);


ssize_t	sendto(int sd, const void *buf, size_t len, int flags, const struct sockaddr *sa, socklen_t socklen)
{
    struct sockaddr_env se;
    int ret;
    se.se_addr = sa;
    se.se_len = socklen;
    return sys_sendto(sd, buf, len, flags, &se);
}
