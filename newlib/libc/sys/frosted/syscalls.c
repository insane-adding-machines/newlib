/*
 * Redirect newlib's syscalls (with _underscore prefix) to Frosted's syscalls
 */

#include "frosted_api.h"
#include "syscalls.h"
#include <errno.h>
#include <stdint.h>
#undef errno
extern int errno;

int _close_r(struct _reent *ptr, int fd)
{
    (void)ptr;
    return close(fd);
}

int _close(int fd)
{
    return close(fd);
}
 
int _execve_r(struct _reent *ptr, char *name, char **argv, char **env)
{
    (void)ptr;
    return execve(name, argv, env);
}

int _execve(char *name, char **argv, char **env)
{
    return execve(name, argv, env);
}

int _fork_r(struct _reent *ptr)
{
    (void)ptr;
    return fork();
}

int _fork(void)
{
    return fork();
}

int _fstat_r(struct _reent *ptr, int fd, struct stat *st)
{
    (void)ptr;
    return fstat(fd, st);
}

int _fstat(int fd, struct stat *st)
{
    return fstat(fd, st);
}

int _getpid_r(struct _reent *ptr)
{
    (void)ptr;
    return getpid();
}

int _getpid(void)
{
    return getpid();
}

int _isatty_r(struct _reent *ptr, int file)
{
    (void)ptr;
    return isatty(file);
}

int _isatty(int file)
{
    return isatty(file);
}

int _kill(int pid, int sig)
{
    return kill(pid, sig);
}

int _link_r(struct _reent *ptr, char *existing, char *new)
{
    (void)ptr;
    return link(existing, new);
}

int _link(char *existing, char *new)
{
    return link(existing, new);
}

int _lseek_r(struct _reent *ptr, int fd, int offset, int whence)
{
    (void)ptr;
    return lseek(fd, offset, whence);
}

int _lseek(int fd, int offset, int whence)
{
    return lseek(fd, offset, whence);
}

int _open_r(struct _reent *ptr, char *file, int flags, int mode)
{
    (void)ptr;
    return open(file, flags, mode);
}

int _open(char *file, int flags, int mode)
{
    return open(file, flags, mode);
}

int _read_r(struct _reent *r_ptr, int file, char *ptr, int len)
{
    (void)r_ptr;
    return read(file, ptr, len);
}


int _read(int file, char *ptr, int len)
{
    return read(file, ptr, len);
}

void * _sbrk_r(int incr)
{
    /* No sbrk needed for Frosted Malloc */
    return NULL;
}

void * _sbrk(int incr)
{
    /* No sbrk needed for Frosted Malloc */
    return NULL;
}

int _stat_r(struct _reent *ptr, const char *file, struct stat *st)
{
    return stat(file, st);
}

int _stat(const char *file, struct stat *st)
{
    return stat(file, st);
}

clock_t _times_r(struct _reent *ptr, struct tms *buf)
{
    (void)ptr;
    return (clock_t)NULL;
}

clock_t _times(struct tms *buf)
{
    return (clock_t)NULL;
}

int _unlink_r(struct _reent *ptr,  char * name)
{
    (void)ptr;
    return unlink(name);
}

int _unlink(char * name)
{
    return unlink(name);
}

int _wait_r(struct _reent *ptr, int *status)
{
    (void)ptr;
    return wait(status);
}

int _wait(int *status)
{
    return wait(status);
}

int _write_r(struct _reent *r_ptr, int file, char *ptr, int len)
{
    (void)r_ptr;
    return write(file, ptr, len);
}

int _write (int file, char *ptr, int len)
{
    return write(file, ptr, len);
}

void * _realloc_r(struct _reent *r_ptr, void *ptr, int size)
{
    (void)r_ptr;
    return realloc(ptr, size);
}

void * _realloc(void * ptr, size_t size)
{
    (void)ptr;
    return (void *)realloc(ptr, size);
}

void * _calloc_r(struct _reent *ptr, size_t num, size_t size)
{
    (void)ptr;
    return (void *)calloc(num, size);
}

void * _calloc(size_t num, size_t size)
{
    return (void *)calloc(num, size);
}

void * _malloc_r (struct _reent *ptr, int size)
{
    (void)ptr;
    return malloc(size);
}

void * _malloc(size_t size)
{
    return malloc(size);
}

void _free_r (struct _reent *r_ptr, void *ptr)
{
    (void)r_ptr;
    free(ptr);
}

void _free(void * ptr)
{
    free(ptr);
}

int _gettimeofday(struct timeval *tv, struct timezone *tz)
{
    return -1;
}

