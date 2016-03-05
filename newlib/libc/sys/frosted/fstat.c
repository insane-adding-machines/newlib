/*
 * Stub version of fstat.
 */

#include "frosted_api.h"
#include <errno.h>
struct stat;

int fstat(int fildes, struct stat *st)
{
  errno = ENOSYS;
  return -1;
}

