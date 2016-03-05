/*
 * Frosted version of link.
 */

#include "frosted_api.h"
#include "syscall_table.h"
#include <errno.h>
extern int sys_link(char *src, char *dst);

int link(char *src, char *dst)
{
    int ret = sys_link(src, dst);
    if (ret < 0) {
        errno = 0 - ret;
        ret = -1;
    }
    return ret;
}
