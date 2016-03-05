/*
 * Frosted version of mount.
 */

#include "frosted_api.h"
#include "syscall_table.h"
#include <errno.h>
extern int sys_mount(char * source, char *target, char *module, uint32_t flags, void *args);

int mount(char * source, char *target, char *module, uint32_t flags, void *args)
{
    (void)flags; /* flags unimplemented for now */
    int ret = sys_mount(source, target, module, flags, args);
    if (ret < 0) {
        errno = 0 - ret;
        ret = -1;
    }
    return ret;
}
