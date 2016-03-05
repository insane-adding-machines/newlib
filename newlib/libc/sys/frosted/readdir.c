/*
 * Frosted version of readdir.
 */

#include "frosted_api.h"
#include "syscall_table.h"
#include <errno.h>
extern int sys_readdir(DIR *d, struct dirent *ep);

int readdir(DIR *d, struct dirent *ep)
{
    int ret = sys_readdir(d, ep);
    if (ret < 0) {
        errno = 0 - ret;
        ret = -1;
    }
    return ret;
}

