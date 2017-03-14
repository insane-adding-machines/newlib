#include "sys/frosted.h"
#include <pthread.h>
#include <sched.h>
#include <errno.h>

extern int sys_pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                              void *(*start_routine)(void *), void *arg);
extern void sys_pthread_exit(void *retval);
extern int sys_pthread_detach(pthread_t thread);
extern int sys_pthread_join(pthread_t thread, void **retval);
extern int sys_pthread_cancel(pthread_t thread);
extern pthread_t sys_pthread_self(void);
extern int sys_pthread_setcancelstate(int state, int *oldstate);
extern int sys_pthread_mutex_init(pthread_mutex_t *mutex,
                                  const pthread_mutexattr_t *restrict attr);
extern int sys_pthread_mutex_destroy(pthread_mutex_t *mutex);
extern int sys_pthread_mutex_lock(pthread_mutex_t *mutex);
extern int sys_pthread_mutex_trylock(pthread_mutex_t *mutex);
extern int sys_pthread_mutex_unlock(pthread_mutex_t *mutex);
extern int sys_pthread_kill(pthread_t thread, int sig);
extern int sys_pthread_getspecific(pthread_key_t *key, uint32_t *value);
extern int sys_pthread_setspecific(pthread_key_t key, const uint32_t value);
extern int sys_pthread_key_create(pthread_key_t key, void *destructor);



int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                   void *(*start_routine)(void *), void *arg)
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

int pthread_setcancelstate(int state, int *oldstate)
{
    return sys_pthread_setcancelstate(state, oldstate);
}

int pthread_yield(void)
{
    return sched_yield();
}

int pthread_mutex_init(pthread_mutex_t *mutex,
                       const pthread_mutexattr_t *restrict attr)
{
    return sys_pthread_mutex_init(mutex, attr);
}

int pthread_mutex_destroy(pthread_mutex_t *mutex)
{
    return sys_pthread_mutex_destroy(*mutex);
}

int pthread_mutex_lock(pthread_mutex_t *mutex)
{
    return sys_pthread_mutex_lock(mutex);
}

int pthread_mutex_trylock(pthread_mutex_t *mutex)
{
    return sys_pthread_mutex_trylock(mutex);
}

int pthread_mutex_unlock(pthread_mutex_t *mutex)
{
    return sys_pthread_mutex_unlock(*mutex);
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

int pthread_attr_init(pthread_attr_t *attr)
{
    return 0;
}

int pthread_attr_destroy(pthread_attr_t *attr)
{
    return 0;
}

int pthread_setcanceltype(int type, int *oldtype)
{
    if (type != PTHREAD_CANCEL_DEFERRED && type != PTHREAD_CANCEL_ASYNCHRONOUS)
        return EINVAL;
    if (oldtype)
        *oldtype = type;
    return 0;
}

int pthread_kill(pthread_t thread, int sig)
{
    int ret = sys_pthread_kill(thread, sig);
    if (ret < 0) {
        errno = 0 - ret;
        return -1;
    }
    return ret;
}

int pthread_key_create(pthread_key_t *key, void (*destructor)(void*))
{
    int ret = sys_pthread_key_create(key, destructor);
    if (ret < 0) {
        errno = 0 - ret;
        return -1;
    }
    return ret;
}


int pthread_setspecific(pthread_key_t key, const void *value)
{
    int ret = sys_pthread_setspecific(key, (uint32_t)value);
    if (ret < 0) {
        errno = 0 - ret;
        return -1;
    }
    return ret;
}

/* proxy to sys_pthread_getspecific */
void *pthread_getspecific(pthread_key_t key)
{
    uint32_t value;
    int ret = sys_pthread_getspecific(key, &value);
    if (ret < 0) {
        errno = 0 - ret;
        return NULL;
    }
    return (void *)value;
}
