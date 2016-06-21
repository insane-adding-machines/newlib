/*
 * Frosted version of stat.
 */

#include "sys/frosted.h"
#include <errno.h>
#include <sys/stat.h>
extern int sys_stat(char * file, struct stat *st);
extern int sys_lstat(char * file, struct stat *st);
extern int sys_fstat(int fd, struct stat *st);


int stat(const char *file, struct stat *st)
{
    int ret = sys_stat(file, st);
    if (ret < 0) {
        errno = 0 - ret;
        ret = -1;
    }
    return ret;
}

int lstat(const char *file, struct stat *st)
{
    int ret = sys_lstat(file, st);
    if (ret < 0) {
        errno = 0 - ret;
        ret = -1;
    }
    return ret;
}

int fstat(const int fd, struct stat *st)
{
    int ret = sys_fstat(fd, st);
    if (ret < 0) {
        errno = 0 - ret;
        ret = -1;
    }
    return ret;
}
