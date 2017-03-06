/*
 * Frosted version of sem_init.
 */

#include "sys/frosted.h"
#include <errno.h>
#include <semaphore.h>

extern int sys_sem_init(sem_t *s, int val);

int sem_init(sem_t *s, int pshared, int val)
{
    int ret = sys_sem_init(s, val);
    if (ret < 0) {
    	errno = 0 - ret;
        ret = -1;
    }
    return ret;
}

