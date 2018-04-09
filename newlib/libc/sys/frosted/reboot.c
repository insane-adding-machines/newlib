/*
 * Frosted version of reboot.
 */

#include <errno.h>
#include <stdint.h>
#include "sys/frosted-io.h"
#include "sys/frosted.h"
extern int sys_reboot(uint32_t, int, uint32_t);

static int do_reboot(uint32_t fadeoff, int cmd, uint32_t interval)
{
    if (fadeoff != SYS_FROSTED_FADEOFF)
        return -EINVAL;
    return sys_reboot(fadeoff, cmd, interval);
}

int reboot()
{
    return do_reboot(SYS_FROSTED_FADEOFF, RB_REBOOT, 0); /* Never returns */
}

int suspend(uint32_t interval)
{
    return do_reboot(SYS_FROSTED_FADEOFF, RB_SUSPEND, interval); 
}

int standby(uint32_t interval)
{
    return do_reboot(SYS_FROSTED_FADEOFF, RB_STANDBY, interval); /* Never returns */
}
