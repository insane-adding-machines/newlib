/*
 * Frosted version of mount.
 */

#include "sys/frosted.h"
#include <errno.h>
extern int sys_mount(char * source, char *target, char *module, unsigned long flags, void *args);

int mount(char * source, char *target, char *module, unsigned long flags, void *args)
{
    (void)flags; /* flags unimplemented for now */
    int ret = sys_mount(source, target, module, flags, args);
    if (ret < 0) {
        errno = 0 - ret;
        ret = -1;
    }
    return ret;
}


