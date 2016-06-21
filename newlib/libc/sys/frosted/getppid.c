/*
 * Frosted version of getppid.
 */

#include "sys/frosted.h"
#include <errno.h>
extern int sys_getppid(void);

int getppid(void)
{
    return sys_getppid();
}
