/*
 * Frosted version of setsid.
 */

#include "syscall_table.h"
#include <errno.h>
extern int sys_setsid(void);

int setsid(void)
{
    return sys_setsid();
}
