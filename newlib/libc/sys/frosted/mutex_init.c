/*
 * Frosted version of mutex_init.
 */

#include "frosted_api.h"
#include "syscall_table.h"
#include <errno.h>
extern frosted_mutex_t *sys_mutex_init(void);

frosted_mutex_t *mutex_init(void)
{
    frosted_mutex_t *m = sys_mutex_init();
    if (!m) {
        errno = ENOMEM;
    }
    return m;
}

