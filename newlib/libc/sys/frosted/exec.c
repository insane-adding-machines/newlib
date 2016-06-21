/*
 * Frosted version of exec.
 */

#include "sys/frosted.h"
#include <errno.h>
extern int sys_exec(char *cmd, char **args);

int exec(char *cmd, char **args)
{
    return sys_exec(cmd, args);
}

int execve(char *cmd, char *argv[], char *envp[])
{
    (void)envp;
    return sys_exec(cmd, (char **)argv);
}

int execvp(char *cmd, char *argv[])
{
    return sys_exec(cmd, (char **)argv);
}

int execv(char *cmd, char *argv[])
{
    return sys_exec(cmd, (char **)argv);
}

