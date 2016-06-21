/*
 * Frosted version of setsid.
 */

#include "sys/frosted.h"
#include <errno.h>
extern int sys_setsid(void);

int setsid(void)
{
    return sys_setsid();
}
