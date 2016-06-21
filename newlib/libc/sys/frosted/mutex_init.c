/*
 * Frosted version of mutex_init.
 */

#include "sys/frosted.h"
#include <errno.h>
#include <semaphore.h>


extern mutex_t *sys_mutex_init(void);

mutex_t *mutex_init(void)
{
    mutex_t *m = sys_mutex_init();
    if (!m) {
        errno = ENOMEM;
    }
    return m;
}

