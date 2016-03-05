/*
* Frosted version of tcgetattr
*/


#include "frosted_api.h"
#include "syscall_table.h"
#include <sys/termios.h>
#include <errno.h>
extern int sys_tcgetattr(int fd, struct termios *termios_p);


int tcgetattr(int fd, struct termios *termios_p)
{
    int ret = sys_tcgetattr(fd, termios_p);
    if (ret < 0) {
        errno = 0 - ret;
        ret = -1;
    }
    return ret;
}
