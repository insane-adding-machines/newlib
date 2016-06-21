
/*
* Frosted stub for getlogin
*/


#include "sys/frosted.h"
#include <errno.h>

static char * username = "root";

char *getlogin(void)
{
    return username;
}
