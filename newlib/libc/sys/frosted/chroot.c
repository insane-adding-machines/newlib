
/*
* Frosted stub for unimplemented chroot function
*/


#include "frosted_api.h"
#include "syscall_table.h"
#include <errno.h>

int chroot(const char *path)
{
    /* chroot always fails */
    errno = ENOSYS;
    return -1;
}
