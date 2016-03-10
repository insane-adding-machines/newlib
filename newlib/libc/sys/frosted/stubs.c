/*
 * Frosted STUBS.
 */

#include "syscall_table.h"
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

/*
 * Frosted version of chown (STUB).
 */

extern int sys_chown(const char *path, uid_t owner, gid_t group);

int chown(const char *path, uid_t owner, gid_t group)
{
    errno = ENOSYS;
    return -1;
}

/*
 * Frosted version of chmod (STUB).
 */

extern int sys_chmod(const char *path, mode_t mode);

int chmod(const char *path, mode_t mode)
{
    errno = ENOSYS;
    return -1;
}

/*
 * Frosted version of clearenv (STUB).
 */

extern int sys_clearenv(void);

int clearenv(void)
{
    errno = ENOSYS;
    return -1;
}

/*
 * Frosted version of dirname (STUB).
 */

extern char *sys_dirname(char *path);

char *dirname(char *path)
{
    errno = ENOSYS;
    return -1;
}

/*
 * Frosted version of fcntl (STUB).
 */

extern int sys_fcntl(int fildes, int cmd, ...);

int fcntl(int fildes, int cmd, ...)
{
    errno = ENOSYS;
    return -1;
}

/*
 * Frosted version of fnmatch (STUB).
 */

extern int sys_fnmatch(const char *pattern, const char *string, int flags);

int fnmatch(const char *pattern, const char *string, int flags)
{
    errno = ENOSYS;
    return -1;
}

/*
 * Frosted version of getpagesize (STUB).
 */

extern int sys_getpagesize(void);

int getpagesize(void)
{
    errno = ENOSYS;
    return -1;
}

/*
 * Frosted version of getsid (STUB).
 */

extern pid_t sys_getsid(pid_t pid);

pid_t getsid(pid_t pid)
{
    errno = ENOSYS;
    return -1;
}

/*
 * Frosted version of glob (STUB).
 */

#include <glob.h>

extern int sys_glob(const char *pattern, int flags,
                int (*errfunc) (const char *epath, int eerrno),
                glob_t *pglob);

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

extern void sys_globfree(glob_t *pglob);

void globfree(glob_t *pglob)
{
    errno = ENOSYS;
    return -1;
}

/*
 * Frosted version of lchown (STUB).
 */

extern int sys_lchown(const char *path, uid_t owner, gid_t group);

int lchown(const char *path, uid_t owner, gid_t group)
{
    errno = ENOSYS;
    return -1;
}

/*
 * Frosted version of major (STUB).
 */

extern unsigned int sys_major(dev_t dev);

unsigned int major(dev_t dev)
{
    errno = ENOSYS;
    return -1;
}

/*
 * Frosted version of malloc_trim (STUB).
 */

extern void sys_malloc_trim(size_t pad);

void malloc_trim(size_t pad)
{
    errno = ENOSYS;
    return -1;
}

/*
 * Frosted version of mallopt (STUB).
 */

extern int sys_mallopt(int param, int value);

int mallopt(int param, int value)
{
    errno = ENOSYS;
    return -1;
}

/*
 * Frosted version of minor (STUB).
 */

extern unsigned int sys_minor(dev_t dev);

unsigned int minor(dev_t dev)
{
    errno = ENOSYS;
    return -1;
}

/*
 * Frosted version of mknod (STUB).
 */

extern int sys_mknod(const char *pathname, mode_t mode, dev_t dev);

int mknod(const char *pathname, mode_t mode, dev_t dev)
{
    errno = ENOSYS;
    return -1;
}

/*
 * Frosted version of nanosleep (STUB).
 */

extern int sys_nanosleep(const struct timespec *req, struct timespec *rem);

int nanosleep(const struct timespec *req, struct timespec *rem)
{
    errno = ENOSYS;
    return -1;
}

/*
 * Frosted version of readlink (STUB).
 */

extern ssize_t sys_readlink(const char *path, char *buf, size_t bufsiz);

ssize_t readlink(const char *path, char *buf, size_t bufsiz)
{
    errno = ENOSYS;
    return -1;
}

/*
 * Frosted version of realpath (STUB).
 */

extern char *sys_realpath(const char *path, char *resolved_path);

char *realpath(const char *path, char *resolved_path)
{
    errno = ENOSYS;
    return -1;
}

/*
 * Frosted version of regcomp (STUB).
 */
#include <regex.h>

extern int sys_regcomp(regex_t *preg, const char *regex, int cflags);

int regcomp(regex_t *preg, const char *regex, int cflags)
{
    errno = ENOSYS;
    return -1;
}

/*
 * Frosted version of regerror (STUB).
 */
#include <regex.h>

extern size_t sys_regerror(int errcode, const regex_t *preg, char *errbuf,
                        size_t errbuf_size);

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

extern int sys_regexec(const regex_t *preg, const char *string, size_t nmatch,
                    regmatch_t pmatch[], int eflags);

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

extern void sys_regfree(regex_t *preg);

void regfree(regex_t *preg)
{
    errno = ENOSYS;
    return -1;
}

/*
 * Frosted version of rmdir (STUB).
 */

extern int sys_rmdir(const char *pathname);

int rmdir(const char *pathname)
{
    errno = ENOSYS;
    return -1;
}

/*
 * Frosted version of strverscmp (STUB).
 */

extern int sys_strverscmp(const char *s1, const char *s2);

int strverscmp(const char *s1, const char *s2)
{
    errno = ENOSYS;
    return -1;
}

/*
 * Frosted version of symlink (STUB).
 */

extern int sys_symlink(const char *oldpath, const char *newpath);

int symlink(const char *oldpath, const char *newpath)
{
    errno = ENOSYS;
    return -1;
}

/*
 * Frosted version of utimes (STUB).
 */
#include <sys/time.h>

extern int sys_utimes(const char *filename, const struct timeval times[2]);

int utimes(const char *filename, const struct timeval times[2])
{
    errno = ENOSYS;
    return -1;
}
