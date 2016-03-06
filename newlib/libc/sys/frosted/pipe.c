/*
* Frosted version of pipe2
*/


#include "syscall_table.h"
#include <errno.h>
extern int sys_pipe2(int fd[2], int flags);


int pipe2(int fd[2], int flags)
{
    int ret = sys_pipe2(fd, flags);
    if (ret < 0) {
        errno = 0 - ret;
        ret = -1;
    }
    return ret;
}

int pipe(int fd[2])
{
    int ret = sys_pipe2(fd, 0);
    if (ret < 0) {
        errno = 0 - ret;
        ret = -1;
    }
    return ret;
}
