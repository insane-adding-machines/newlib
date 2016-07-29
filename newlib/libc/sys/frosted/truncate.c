/*
 * Frosted version of truncate/ftruncate
 */

#include "sys/frosted.h"
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>

extern int sys_truncate(char * file, off_t size);
extern int sys_ftruncate(int fd, off_t size);


int truncate(const char *file, off_t size)
{
    int ret = sys_truncate(file, size);
    if (ret < 0) {
        errno = 0 - ret;
        ret = -1;
    }
    return ret;
}

int ftruncate(int fd, off_t size)
{
    int ret = sys_ftruncate(fd, size);
    if (ret < 0) {
        errno = 0 - ret;
        ret = -1;
    }
    return ret;
}
