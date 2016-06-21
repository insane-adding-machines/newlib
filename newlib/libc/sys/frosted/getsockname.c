/*
* Frosted version of getsockname
*/


#include "sys/frosted.h"
#include <netinet/in.h>
#include <errno.h>
#include <string.h>
extern int sys_getsockname(int sd, struct sockaddr_env *se);

int getsockname(int sd, struct sockaddr *sa, socklen_t *socklen)
{
    struct sockaddr_env se;
    int ret;
    se.se_addr = sa;
    se.se_len = *socklen;
    ret =  sys_getsockname(sd, &se);
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
