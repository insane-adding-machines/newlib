
/*
* Frosted version of password functions
*/

#ifndef UNIT_TEST
#include "syscall_table.h"
#endif
#include "pwd.h"
#include "sys/types.h"
#include <errno.h>

static const char pw_name[] = "root";


static struct passwd pwd_root = {
	.pw_name = pw_name,
	.pw_passwd = NULL,
	.pw_uid = 0,
	.pw_gid = 0,
	.pw_gecos = NULL,
	.pw_dir = NULL,
	.pw_shell = NULL
};

struct passwd *getpwnam(const char *name)
{
    if (!name) {
        errno = EINVAL;
        return NULL;
    }
    if (strcmp(name, pwd_root.pw_name) != 0) {
        errno = ENOENT;
        return NULL;
    }

    return &pwd_root;
}

struct passwd *getpwuid(uid_t uid)
{
    if (uid != pwd_root.pw_uid) {
        errno = ENOENT;
        return NULL;
    }

    return &pwd_root;
}

int getpwnam_r(const char *name, struct passwd *pwd, char *buf, size_t buflen, struct passwd **result)
{
    *result = NULL;

    if (!name) {
        errno = EINVAL;
        return -1;
    }

    if (strcmp(name, pwd_root.pw_name) != 0) {
        errno = ENOENT;
        return -1;
    }

    *result = &pwd_root;
    return 0;
}

int getpwuid_r(uid_t uid, struct passwd *pwd, char *buf, size_t buflen, struct passwd **result)
{
    *result = NULL;

    if (uid != pwd_root.pw_uid) {
        errno = ENOENT;
        return -1;
    }

    *result = &pwd_root;
    return 0;
}
