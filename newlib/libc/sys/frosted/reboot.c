/*
 * Frosted version of reboot.
 */

#include "sys/frosted.h"
#include <errno.h>
extern int sys_reboot(void);

int reboot(void)
{
    return sys_reboot(); /* Actually it will never return. */
}
