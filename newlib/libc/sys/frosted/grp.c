
/*
* Frosted stubs for group functions
*/

#include "syscall_table.h"
#include "grp.h"
#include <errno.h>

int getgroups(int size, gid_t list[])
{
    /* always fail for now */
    errno = EPERM;
    return -1;
}
