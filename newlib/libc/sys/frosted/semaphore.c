/*
 * Frosted version of semaphore.
 */

#include "sys/frosted.h"
#include <errno.h>
#include <semaphore.h>
#include <sys/time.h>
#include <stddef.h>
extern int sys_sem_post(sem_t *s);
extern int sys_sem_wait(sem_t *s, struct timespec *t);
extern int sys_sem_trywait(sem_t *s);
extern int sys_sem_destroy(sem_t *s);

int sem_post(sem_t *s)
{
    int ret = sys_sem_post(s);
    if (ret < 0) {
        errno = 0 - ret;
        ret = -1;
    }
    return ret;
}

int sem_wait(sem_t *s)
{
    int ret = sys_sem_wait(s, NULL);
    if (ret < 0) {
        errno = 0 - ret;
        ret = -1;
    }
    return ret;
}

int sem_timedwait(sem_t *s, struct timespec *t)
{
    int ret = sys_sem_wait(s, t);
    if (ret < 0) {
        errno = 0 - ret;
        ret = -1;
    }
    return ret;
}

int sem_trywait(sem_t *s)
{
    int ret = sys_sem_trywait(s);
    if (ret < 0) {
        errno = 0 - ret;
        ret = -1;
    }
    return ret;
}

int sem_destroy(sem_t *s)
{
    int ret = sys_sem_destroy(s);
    if (ret < 0) {
        errno = 0 - ret;
        ret = -1;
    }
    return ret;
}
