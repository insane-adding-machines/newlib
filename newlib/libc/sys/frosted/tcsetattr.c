/*
* Frosted version of tcsetattr
*/


#include "syscall_table.h"
#include <sys/termios.h>
#include <errno.h>
extern int sys_tcsetattr(int fd, int optional_actions, const struct termios *termios_p);


int tcsetattr(int fd, int optional_actions, const struct termios *termios_p)
{
    int ret = sys_tcsetattr(fd, optional_actions, termios_p);
    if (ret < 0) {
        errno = 0 - ret;
        ret = -1;
    }
    return ret;
}
