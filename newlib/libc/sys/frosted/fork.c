/*
 * Stub version of fork.
 */

#include <errno.h>

int fork(void)
{
  errno = ENOSYS;
  return -1;
}

