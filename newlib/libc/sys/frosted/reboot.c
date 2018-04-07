/*
 * Frosted version of reboot.
 */

#include <errno.h>
#include <stdint.h>
#include "sys/frosted-io.h"
#include "sys/frosted.h"
extern int sys_reboot(void);
extern int sys_suspend(uint32_t interval);
extern int sys_standby(uint32_t interval);

int reboot(uint32_t fadeoff)
{
    if (fadeoff != SYS_FROSTED_FADEOFF)
        return -EINVAL;
    return sys_reboot(); /* Actually it will never return. */
}

int suspend(uint32_t fadeoff, uint32_t interval)
{
    if (fadeoff != SYS_FROSTED_FADEOFF)
        return -EINVAL;
    return sys_suspend(interval); /* Actually it will never return. */
}

int standby(uint32_t fadeoff, uint32_t interval)
{
    if (fadeoff != SYS_FROSTED_FADEOFF)
        return -EINVAL;
    return sys_standby(interval);
}
