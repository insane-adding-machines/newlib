/*
 * Frosted version of malloc.
 */

#include "syscall_table.h"
#include <errno.h>
extern void* sys_malloc(int size);
extern void* sys_realloc(void *ptr, int size);
extern void* sys_calloc(int n, int size);

void * malloc(int size)
{
    void *ret = sys_malloc(size);
    if (!ret)
        errno = ENOMEM;
    return ret;
}

void * realloc(void *ptr, int size)
{
    void *ret = sys_realloc(ptr, size);
    if (!ret)
        errno = ENOMEM;
    return ret;
}

void * calloc(int n, int size)
{
    void *ret = sys_calloc(n, size);
    if (!ret)
        errno = ENOMEM;
    return ret;
}
