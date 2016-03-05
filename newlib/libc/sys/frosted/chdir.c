/*
 * Frosted version of chdir.
 */

#include "frosted_api.h"
#include "syscall_table.h"
#include <errno.h>
extern int sys_chdir(char *path);

int chdir(char *path)
{
    int ret;
    ret = sys_chdir(path);
    if (ret < 0) {
        errno = 0 - ret;
        ret = -1;
    }
    return ret;
}

