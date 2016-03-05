/*
 * Stub version of fork.
 */

#include "frosted_api.h"
#include <errno.h>

int fork(void)
{
  errno = ENOSYS;
  return -1;
}

