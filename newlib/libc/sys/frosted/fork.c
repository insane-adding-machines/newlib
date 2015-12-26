/*
 * Stub version of fork.
 */

#include "frosted_api.h"
#include <errno.h>
#undef errno
extern int errno;

int _fork(void)
{
  errno = ENOSYS;
  return -1;
}

int fork(void) {
  errno = ENOSYS;
  return -1;
}
    
