/*
 * Frosted version of gettimeofday.
 */

#include "sys/frosted.h"
#include "time.h"
#include <sys/_timeval.h>
#include <errno.h>
struct timeval;
struct timezone;
extern int sys_clock_gettime(clockid_t clock_id, struct timespec *tp);
extern int sys_clock_settime(clockid_t clock_id, struct timespec *tp);

int gettimeofday(struct timeval *tv, struct timezone *tz)
{
    (void)tz; /* Timezone not implemented in frosted. */
    struct timespec tp;
    int ret = sys_clock_gettime(CLOCK_REALTIME, &tp);
    if (ret < 0) {
        errno = 0 - ret;
        ret = -1;
    }
    tv->tv_sec = tp.tv_sec;
    tv->tv_usec = (tp.tv_nsec / 1000);
    return ret;
}

int settimeofday(struct timeval *tv, struct timezone *tz)
{
    (void)tz; /* Timezone not implemented in frosted. */
    struct timespec tp;
    tp.tv_sec = tv->tv_sec;
    tp.tv_nsec = (tv->tv_usec * 1000);
    int ret = sys_clock_settime(CLOCK_REALTIME, &tp);
    if (ret < 0) {
        errno = 0 - ret;
        ret = -1;
    }
    return ret;
}
