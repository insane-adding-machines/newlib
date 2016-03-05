/*
 * Frosted version of socket.
 */

#include "frosted_api.h"
#include "syscall_table.h"
#include <errno.h>
extern int sys_socket(int, int, int);

int socket(int domain, int type, int proto)
{
    int ret = sys_socket(domain, type, proto);
    if (ret < 0) {
        errno = 0 - ret;
        ret = -1;
    }
    return ret;
}
