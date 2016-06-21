/*
 * Frosted version of readdir.
 */

#include "sys/frosted.h"
#include <dirent.h>
#include <errno.h>
extern int sys_readdir(DIR *d, struct dirent *ep);

static struct dirent static_ep;

int readdir_r(DIR *d, struct dirent *ep, struct dirent **res)
{
    int ret = sys_readdir(d, ep);
    if (ret < 0) {
        errno = 0 - ret;
        *res = NULL;
        ret = -1;
    }
    *res = ep;
    return ret;
}

struct dirent *readdir(DIR *d)
{
    int ret;
    memset(&static_ep, 0, sizeof(struct dirent));
    ret = sys_readdir(d, &static_ep);
    if (ret == 0)
        return &static_ep;
    else
        return NULL;
}
