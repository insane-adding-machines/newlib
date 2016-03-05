/*
* Frosted version of setsockopt
*/


#include "frosted_api.h"
#include "syscall_table.h"
#include <sys/socket.h>
#include <errno.h>
#undef errno
extern int errno;
extern int sys_setsockopt(int sd, int level, int optname, const void *optval, unsigned int optlen);


int setsockopt(int sd, int level, int optname, const void *optval, socklen_t optlen)

{
    return sys_setsockopt(sd, level, optname, optval, optlen);
}
