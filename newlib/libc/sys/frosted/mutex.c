/*
 * Frosted version of mutexaphore.
 */

#include "frosted_api.h"
#include "syscall_table.h"
#include <errno.h>
extern sys_mutex_unlock(frosted_mutex_t *s);
extern sys_mutex_lock(frosted_mutex_t *s);
extern sys_mutex_destroy(frosted_mutex_t *s);

int mutex_unlock(frosted_mutex_t *s)
{
    int ret = sys_mutex(s);
    if (ret < 0) {
        errno = 0 - ret;
        ret = -1;
    }
    return ret;
}

int mutex_lock(frosted_mutex_t *s)
{
    int ret = sys_mutex_lock(s);
    if (ret < 0) {
        errno = 0 - ret;
        ret = -1;
    }
    return ret;
}

int mutex_destroy(frosted_mutex_t *s)
{
    int ret = sys_mutex_destroy(s);
    if (ret < 0) {
        errno = 0 - ret;
        ret = -1;
    }
    return ret;
}
