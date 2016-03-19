/*
 * Frosted STUBS.
 */

#ifndef UNIT_TEST
#include "syscall_table.h"
#endif
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

/*
 * Frosted version of chown (STUB).
 */

int chown(const char *path, uid_t owner, gid_t group)
{
    errno = ENOSYS;
    return -1;
}

/*
 * Frosted version of chmod (STUB).
 */

int chmod(const char *path, mode_t mode)
{
    errno = ENOSYS;
    return -1;
}

/*
 * Frosted version of clearenv (STUB).
 */

int clearenv(void)
{
    errno = ENOSYS;
    return -1;
}

/*
 * Frosted version of fcntl (STUB).
 */

int fcntl(int fildes, int cmd, ...)
{
    errno = ENOSYS;
    return -1;
}

/*
 * Frosted version of fnmatch (STUB).
 */

int fnmatch(const char *pattern, const char *string, int flags)
{
    errno = ENOSYS;
    return -1;
}

/*
 * Frosted version of getpagesize (STUB).
 */

int getpagesize(void)
{
    errno = ENOSYS;
    return -1;
}

/*
 * Frosted version of getsid (STUB).
 */

pid_t getsid(pid_t pid)
{
    errno = ENOSYS;
    return -1;
}

/*
 * Frosted version of glob (STUB).
 */

#include <glob.h>

int glob(const char *pattern, int flags,
        int (*errfunc) (const char *epath, int eerrno),
        glob_t *pglob)
{
    errno = ENOSYS;
    return -1;
}

/*
 * Frosted version of globfree (STUB).
 */

#include <glob.h>

void globfree(glob_t *pglob)
{
    errno = ENOSYS;
}

/*
 * Frosted version of lchown (STUB).
 */

int lchown(const char *path, uid_t owner, gid_t group)
{
    errno = ENOSYS;
    return -1;
}

/*
 * Frosted version of major (STUB).
 */
#undef major
unsigned int major(dev_t dev)
{
    errno = ENOSYS;
    return -1;
}

/*
 * Frosted version of malloc_trim (STUB).
 */

void malloc_trim(size_t pad)
{
    errno = ENOSYS;
}

/*
 * Frosted version of mallopt (STUB).
 */

int mallopt(int param, int value)
{
    errno = ENOSYS;
    return -1;
}

/*
 * Frosted version of minor (STUB).
 */
#undef minor
unsigned int minor(dev_t dev)
{
    errno = ENOSYS;
    return -1;
}

/*
 * Frosted version of mknod (STUB).
 */

int mknod(const char *pathname, mode_t mode, dev_t dev)
{
    errno = ENOSYS;
    return -1;
}

/*
 * Frosted version of nanosleep (STUB).
 */

int nanosleep(const struct timespec *req, struct timespec *rem)
{
    errno = ENOSYS;
    return -1;
}

/*
 * Frosted version of regcomp (STUB).
 */
#include <regex.h>

int regcomp(regex_t *preg, const char *regex, int cflags)
{
    errno = ENOSYS;
    return -1;
}

/*
 * Frosted version of regerror (STUB).
 */
#include <regex.h>

size_t regerror(int errcode, const regex_t *preg, char *errbuf,
                size_t errbuf_size)
{
    errno = ENOSYS;
    return -1;
}

/*
 * Frosted version of regexec (STUB).
 */
#include <regex.h>

int regexec(const regex_t *preg, const char *string, size_t nmatch,
            regmatch_t pmatch[], int eflags)
{
    errno = ENOSYS;
    return -1;
}

/*
 * Frosted version of regfree (STUB).
 */
#include <regex.h>

void regfree(regex_t *preg)
{
    errno = ENOSYS;
}

/*
 * Frosted version of rmdir (STUB).
 */

int rmdir(const char *pathname)
{
    errno = ENOSYS;
    return -1;
}

/*
 * Frosted version of strverscmp (STUB).
 */

int strverscmp(const char *s1, const char *s2)
{
    errno = ENOSYS;
    return -1;
}

/*
 * Frosted version of symlink (STUB).
 */

int symlink(const char *oldpath, const char *newpath)
{
    errno = ENOSYS;
    return -1;
}

/*
 * Frosted version of utimes (STUB).
 */
#include <sys/time.h>

int utimes(const char *filename, const struct timeval times[2])
{
    errno = ENOSYS;
    return -1;
}

/*
 * Frosted version of chroot (STUB).
 */

int chroot(const char *path)
{
    errno = ENOSYS;
    return -1;
}

/*
 * Frosted version of fork (STUB).
 */

int fork(void)
{
    errno = ENOSYS;
    return -1;
}
