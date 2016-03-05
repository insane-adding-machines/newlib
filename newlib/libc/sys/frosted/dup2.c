/*
* Frosted version of dup2
*/


#include "frosted_api.h"
#include "syscall_table.h"
#include <errno.h>
extern int sys_dup2(int fd, int newfd);


int dup2(int fd, int newfd)
{
    int ret;
    ret = sys_dup2(fd, newfd);
    if (ret < 0) {
        errno = 0 - ret;
        ret = -1;
    }
    return ret;
}
