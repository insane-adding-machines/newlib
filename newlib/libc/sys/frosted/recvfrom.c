/*
* Frosted version of recvfrom
*/


#include "sys/frosted.h"
#include <errno.h>
#include <netinet/in.h>
#include <string.h>
extern int sys_recvfrom(int sd, void *buf, unsigned int len, int flags, struct sockaddr_env *se);


int recvfrom(int sd, void *buf, size_t len, int flags, struct sockaddr *sa, socklen_t *socklen)
{
    struct sockaddr_env se;
    int ret;
    if (sa) {
        se.se_addr = sa;
        se.se_len = *socklen;
        ret = sys_recvfrom(sd, buf, len, flags, &se);
    } else {
        ret = sys_recvfrom(sd, buf, len, flags, NULL);
    }
    if (sa && ret > 0) {
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

int recv(int sd, void *buf, size_t len, int flags)
{
    return recvfrom(sd, buf, len, flags, NULL, NULL);
}
