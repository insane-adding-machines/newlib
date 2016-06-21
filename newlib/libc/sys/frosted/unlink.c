/*
 * Frosted version of unlink.
 */

#include "sys/frosted.h"
#include <errno.h>
extern int sys_unlink(const char *name);

int unlink (const char * name)
{
    int ret = sys_unlink(name);
    if (ret < 0) {
        errno = 0 - ret;
        ret = -1;
    }
    return ret;
}
