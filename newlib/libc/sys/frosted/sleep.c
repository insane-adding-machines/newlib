/*
 * Frosted version of sleep.
 */

#include "sys/frosted.h"
#include "sys/time.h"
#include <errno.h>

extern int sys_sleep(int ms, uint32_t *rem);

unsigned int sleep(int s)
{
    uint32_t rem;
    int ret = sys_sleep((s * 1000) + 1, &rem);
    if (ret < 0) {
        errno = 0 - ret;
        ret = -1;
    }
    return rem;
}

int usleep(int us)
{
    uint32_t rem;
    int ret = sys_sleep((us / 1000) + 1, &rem);
    if (ret < 0) {
        errno = 0 - ret;
        ret = -1;
    }
    if (rem > 0) {
        errno = EINTR;
        ret = -1;
    }
    return ret;
}

int nanosleep(const struct timespec *req, struct timespec *rem)
{
    uint32_t r;
    int ret = sys_sleep((req->tv_nsec / (1000 * 1000)) + req->tv_sec * 1000 + 1, &r);
    if (rem) {
        rem->tv_sec = 0;
        rem->tv_nsec = 0;
    }
    if (ret < 0) {
        errno = 0 - ret;
        ret = -1;
    }
    if (r > 0) {
        errno = EINTR;
        ret = -1;
        if (rem) {
            rem->tv_sec = r / 1000;
            rem->tv_nsec = (r % 1000) * 1000 * 1000;
        }
    }
    return ret;
}
