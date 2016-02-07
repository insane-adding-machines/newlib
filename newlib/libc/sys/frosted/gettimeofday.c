/*
 * Frosted version of gettimeofday.
 */

#include "frosted_api.h"
#include "syscall_table.h"
#include <errno.h>
#undef errno
struct timeval;
struct timezone;
extern int errno;
extern int sys_gettimeofday(struct timeval *tv);

int gettimeofday(struct timeval *tv, struct timezone *tz)
{
    (void)tz; /* Timezone not implemented in frosted. */
    return sys_gettimeofday(tv);
}
