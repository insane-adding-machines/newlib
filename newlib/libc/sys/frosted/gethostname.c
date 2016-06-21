
/*
* Frosted stub for gethostname
*/


#include "sys/frosted.h"
#include "sys/types.h"
#include "string.h"
#include <errno.h>


static char * hostname = "frosted";

int gethostname(char *name, size_t namelen)
{
    strncpy(name, hostname, namelen);
    return 0;
}
