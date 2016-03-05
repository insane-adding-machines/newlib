/*
 * Frosted version of sem_init.
 */

#include "frosted_api.h"
#include "syscall_table.h"
#include <errno.h>
extern sem_t *sys_sem_init(int val);

sem_t *sem_init(int val)
{
    sem_t *s = sys_sem_init(val);
    if (!s) {
        errno = ENOMEM;
    }
    return s;
}

