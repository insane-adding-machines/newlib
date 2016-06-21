/*
* Frosted version of dup
*/


#include "sys/frosted.h"
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
