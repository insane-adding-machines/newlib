/*
 * Frosted version of free.
 */

#include "sys/frosted.h"
#include <errno.h>
extern void sys_free(void * ptr);

void free(void * ptr)
{
    sys_free(ptr);
}

