/*
* Frosted version of dup
*/


#include "frosted_api.h"
#include "syscall_table.h"
#include <errno.h>
extern int sys_dup(int fd);


int dup(int fd)
{
    int ret = sys_dup(fd);
    if (ret < 0) {
        errno = 0 - ret;
        ret = -1;
    }
    return ret;
}
