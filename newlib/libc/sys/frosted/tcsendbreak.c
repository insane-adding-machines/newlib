/*
* Frosted version of tcsendbreak
*/


#include "sys/frosted.h"
#include <sys/termios.h>
#include <errno.h>
extern int sys_tcsendbreak(int fd, int duration);


int tcsendbreak(int fd, int duration)
{
    int ret = sys_tcsendbreak(fd, duration);
    if (ret < 0) {
        errno = 0 - ret;
        ret = -1;
    }
    return ret;
}
