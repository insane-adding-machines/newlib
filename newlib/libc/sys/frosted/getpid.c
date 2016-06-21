/*
 * Frosted version of getpid.
 */

#include "sys/frosted.h"
#include <errno.h>
extern int sys_getpid(void);

int getpid(void)
{
    return sys_getpid();
}
