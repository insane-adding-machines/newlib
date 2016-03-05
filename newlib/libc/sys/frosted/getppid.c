/*
 * Frosted version of getppid.
 */

#include "frosted_api.h"
#include "syscall_table.h"
#include <errno.h>
extern int sys_getppid(void);

int getppid(void)
{
    return sys_getppid();
}
