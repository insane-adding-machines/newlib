#include "sys/frosted.h"
#include <pthread.h>
#include <errno.h>

extern int sys_pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg);
extern void sys_pthread_exit(void *retval);
extern int sys_pthread_detach(pthread_t thread);
extern int sys_pthread_join(pthread_t thread, void **retval);
extern int sys_pthread_cancel(pthread_t thread);
extern pthread_t sys_pthread_self(void);

int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg)
{
    return sys_pthread_create(thread, attr, start_routine, arg);

}

void pthread_exit(void *retval)
{
    sys_pthread_exit(retval);
}

int pthread_detach(pthread_t thread)
{
    return sys_pthread_detach(thread);
}

int pthread_join(pthread_t thread, void **retval)
{
    return sys_pthread_join(thread, retval);
}

int pthread_cancel(pthread_t thread)
{
    return sys_pthread_cancel(thread);
}

pthread_t pthread_self(void)
{
    return sys_pthread_self();
}

/* Pure libC functions */
int pthread_attr_setdetachstate(pthread_attr_t *attr, int detachstate)
{
    if (detachstate)
        *attr = PTHREAD_CREATE_DETACHED;
}

int pthread_attr_getdetachstate(const pthread_attr_t *attr, int *detachstate)
{
    *detachstate = *attr;
}

int pthread_equal(pthread_t t1, pthread_t t2)
{
    if (t1 == t2)
        return 1;
    return 0;
}

