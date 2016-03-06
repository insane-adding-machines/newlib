/*
 * Frosted version of exit.
 */

#include "frosted_api.h"
#include "syscall_table.h"
#include <errno.h>
#include <stdio.h>

extern int sys_exit(int val);

int exit(int val)
{
    fflush(stderr);
    fflush(stdout);
    return sys_exit(val);
}

int _exit(int val) {
    fflush(stderr);
    fflush(stdout);
    return sys_exit(val);
}


