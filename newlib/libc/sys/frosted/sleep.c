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

extern int sys_gettimeofday(struct timeval *tv);

int clock_getres(clockid_t clock_id, struct timespec *res)
{
    int ret = -1;
    if (res) {
        res->tv_sec = 0;
        res->tv_nsec = 1 * 1000 * 1000;
        ret = 0;
    }
    return ret;
}

int clock_gettime(clockid_t clock_id, struct timespec *tp)
{
    struct timeval tv;
    int ret = sys_gettimeofday(&tv);
    if (ret < 0) {
        errno = 0 - ret;
        ret = -1;
    }
    tp->tv_sec = tv.tv_sec;
    tp->tv_nsec = tv.tv_usec * 1000;
    return ret;
}

extern int sys_clock_settime(struct timeval *tv);

int clock_settime(clockid_t clock_id, const struct timespec *tp)
{
    struct timeval tv;
    tv.tv_sec = tp->tv_sec;
    tv.tv_usec = tp->tv_nsec * 1000;

    int ret = sys_clock_settime(&tv);
    if (ret < 0) {
        errno = 0 - ret;
        ret = -1;
    }
    return ret;
}

