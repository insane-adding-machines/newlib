#include "sys/frosted.h"

extern int sys_sched_yield(void);

int sched_yield(void)
{
    return sys_sched_yield();
}
