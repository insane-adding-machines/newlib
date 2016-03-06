/*
* Frosted version of shutdown
*/


#include "syscall_table.h"
#include <errno.h>
extern int sys_shutdown(int sd, int how);


int shutdown(int sd, int how)
{
    int ret = sys_shutdown(sd, how);
    if (ret < 0) {
        errno = 0 - ret;
        ret = -1;
    }
    return ret;
}
