/*
* Frosted version of listen
*/


#include "frosted_api.h"
#include "syscall_table.h"
#include <errno.h>
extern int sys_listen(int sd, int backlog);


int listen(int sd, int backlog)
{
    int ret = sys_listen(sd, backlog);
    if (ret < 0) {
        errno = 0 - ret;
        ret = -1;
    }
    return ret;
}
