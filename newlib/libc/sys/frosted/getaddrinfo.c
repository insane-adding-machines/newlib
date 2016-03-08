/*
 * Frosted version of getaddrinfo.
 */

#include "syscall_table.h"
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

extern int sys_getaddrinfo(const char *, const char *, const struct addrinfo *, struct addrinfo **);
extern void sys_freeaddrinfo(struct addrinfo *);

int getaddrinfo(const char *node, const char *service, const struct addrinfo *hints, struct addrinfo **res)
{
    int ret = sys_getaddrinfo(node, service, hints, res);
    if (ret < 0) {
        errno = 0 - ret;
        ret = -1;
    }
    return ret;
}

void freeaddrinfo(struct addrinfo *res)
{
    sys_freeaddrinfo(res);
}
