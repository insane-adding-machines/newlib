
/*
* Frosted stubs for group functions
*/

#include "syscall_table.h"
#include "grp.h"
#include <errno.h>

static const char gr_name[] = "root";
const char *gr_members[2] = { gr_name, NULL };

static struct group grp_root = { 
    .gr_name = gr_name,
    .gr_passwd = NULL,
    .gr_gid = 0,
    .gr_mem = gr_members
};


int getgroups(int size, gid_t list[])
{
    if (size < 1) {
        errno = EINVAL;
        return -1;
    }
    list[0] = 0;
    return 1;
}


struct group *getgrnam(const char *name) 
{
    if (!name) {
        errno = EBADF;
        return NULL;
    }
    if (strcmp(name, "root") != 0) {
        errno = ENOENT;
        return NULL;
    }
    return &grp_root;
}

struct group *getgrgid(gid_t g)
{
    if (g == 0)
        return &grp_root;
    errno = ENOENT;
    return NULL;
}
