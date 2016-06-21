/*
 * Frosted version of sem_init.
 */

#include "sys/frosted.h"
#include <errno.h>
#include <semaphore.h>

extern sem_t *sys_sem_init(int val);

sem_t *sem_init(int val)
{
    sem_t *s = sys_sem_init(val);
    if (!s) {
        errno = ENOMEM;
    }
    return s;
}

