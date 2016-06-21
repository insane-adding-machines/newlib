/*
 * Frosted version of mutexaphore.
 */

#include "sys/frosted.h"
#include <errno.h>
#include <semaphore.h>

extern int sys_mutex_unlock(mutex_t *s);
extern int sys_mutex_lock(mutex_t *s);
extern int sys_mutex_destroy(mutex_t *s);

int mutex_unlock(mutex_t *s)
{
    int ret = sys_mutex_unlock(s);
    if (ret < 0) {
        errno = 0 - ret;
        ret = -1;
    }
    return ret;
}

int mutex_lock(mutex_t *s)
{
    int ret = sys_mutex_lock(s);
    if (ret < 0) {
        errno = 0 - ret;
        ret = -1;
    }
    return ret;
}

int mutex_destroy(mutex_t *s)
{
    int ret = sys_mutex_destroy(s);
    if (ret < 0) {
        errno = 0 - ret;
        ret = -1;
    }
    return ret;
}
