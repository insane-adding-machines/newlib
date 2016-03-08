/*
 * Frosted version of exit.
 */

#include "syscall_table.h"
#include <errno.h>
#include <stdio.h>

extern int sys_exit(int val);

void buf_close(void) {
    fclose(stdin);
    fclose(stdout);
    fclose(stderr);
    stdin = NULL;
    stdout = NULL;
    stderr = NULL;
}

int exit(int val)
{
    buf_close();
    return sys_exit(val);
}

int _exit(int val) {
    buf_close();
    return sys_exit(val);
}


