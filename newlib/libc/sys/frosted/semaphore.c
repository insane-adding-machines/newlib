/*
 * Frosted version of semaphore.
 */

#include "frosted_api.h"
#include "syscall_table.h"
#include <errno.h>
extern int sys_sem_post(sem_t *s);
extern int sys_sem_wait(sem_t *s);
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
    int ret = sys_sem_wait(s);
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
