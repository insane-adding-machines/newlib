/*
 * Frosted version of free.
 */

#include "syscall_table.h"
#include <errno.h>
extern void sys_free(void * ptr);

void free(void * ptr)
{
    sys_free(ptr);
}

