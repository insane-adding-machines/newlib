/*
 * Frosted version of gettimeofday.
 */

#include "frosted_api.h"
#include "syscall_table.h"
#include <errno.h>
struct timeval;
struct timezone;
extern int sys_gettimeofday(struct timeval *tv);

int gettimeofday(struct timeval *tv, struct timezone *tz)
{
    (void)tz; /* Timezone not implemented in frosted. */
    int ret = sys_gettimeofday(tv);
    if (ret < 0) {
        errno = 0 - ret;
        ret = -1;
    }
    return ret;
}
