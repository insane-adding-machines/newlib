/*
 * Stub version of fstat.
 */

#include <errno.h>
struct stat;

int fstat(int fildes, struct stat *st)
{
  errno = ENOSYS;
  return -1;
}

