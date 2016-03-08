/*
 * Frosted version of exit.
 */

#include "syscall_table.h"
#include <errno.h>
#include <stdio.h>

extern int sys_exit(int val);

int exit(int val)
{
    return sys_exit(val);
}

int _exit(int val) {
    return sys_exit(val);
}


