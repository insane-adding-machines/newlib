/*
* Frosted version of getpeername
*/


#include "syscall_table.h"
#include <netinet/in.h>
#include <errno.h>
#include <string.h>
extern int sys_getpeername(int sd, struct sockaddr_env *se);

int getpeername(int sd, struct sockaddr *sa, socklen_t *socklen)
{
    struct sockaddr_env se;
    int ret;
    se.se_addr = sa;
    se.se_len = *socklen;
    ret =  sys_getpeername(sd, &se);
    if (ret > 0) {
        if (*socklen < se.se_len) {
            errno = EPROTONOSUPPORT;
            return -1;
        }
        memcpy(sa, se.se_addr, se.se_len); 
        *socklen = se.se_len;
    }
    if (ret < 0) {
        errno = 0 - ret;
        ret = -1;
    }
    return ret;
}
