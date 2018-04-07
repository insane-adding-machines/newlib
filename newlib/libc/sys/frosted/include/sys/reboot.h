#ifndef SYS_REBOOT_H
#define SYS_REBOOT_H
#include <stdint.h>

int reboot(uint32_t fadeoff);
int standby(uint32_t fadeoff, uint32_t interval);
int suspend(uint32_t fadeoff, uint32_t interval);

#endif
