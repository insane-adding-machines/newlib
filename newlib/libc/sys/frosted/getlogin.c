
/*
* Frosted stub for getlogin
*/


#include "syscall_table.h"
#include <errno.h>

static char * username = "root";

char *getlogin(void)
{
    return username;
}
