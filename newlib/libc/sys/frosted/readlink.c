/*
 * Frosted version of readlink.
 */
#include "sys/frosted.h"
#include <stdlib.h>
#include <errno.h>

extern int sys_readlink(char* file,char *buf, size_t size);

int readlink(const char* file, char *buf, size_t len)
{
    int ret = sys_readlink(file, buf, len);
    if (ret < 0) {
        errno = 0 - ret;
        ret = -1;
    }
    return ret;
}

