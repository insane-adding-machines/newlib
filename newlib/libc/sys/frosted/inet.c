
/*
 * Frosted version of IPv4 conversion tools.
 */

#include "syscall_table.h"
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
static inline int is_digit(char c)
{
    if (c < '0' || c > '9')
        return 0;
    return 1;
}

static inline uint32_t long_from(void *_p)
{
    unsigned char *p = (unsigned char *)_p;
    uint32_t r, p0, p1, p2, p3;
    p0 = p[0];
    p1 = p[1];
    p2 = p[2];
    p3 = p[3];
    r = (p0 << 24) + (p1 << 16) + (p2 << 8) + p3;
    return r;
}


int inet_aton(const char *ipstr, struct in_addr *ia)
{
    unsigned char buf[22] = {
        0
    };
    int cnt = 0;
    char p;
    uint32_t *ip = (uint32_t *)ia;

    while((p = *ipstr++) != 0 && cnt < 22)
    {
        if (is_digit(p)) {
            buf[cnt] = (uint8_t)((10 * buf[cnt]) + (p - '0'));
        } else if (p == '.') {
            cnt++;
        } else {
            return -1;
        }
    }
    /* Handle short notation */
    if (cnt == 1) {
        buf[3] = buf[1];
        buf[1] = 0;
        buf[2] = 0;
    } else if (cnt == 2) {
        buf[3] = buf[2];
        buf[2] = 0;
    } else if (cnt != 3) {
        /* String could not be parsed, return error */
        return -1;
    }

    *ip = htonl(long_from(buf));
    return 0;
}

static char inet_ntoa_result[20] = "";

char *inet_ntoa(struct in_addr in) 
{
    const unsigned char *addr = (const unsigned char *) &in.s_addr;
    char *ipbuf = (char *) inet_ntoa_result;
    int i;
    memset(ipbuf, 0, 20);

    for(i = 0; i < 4; i++)
    {
        if (addr[i] > 99) {
            *ipbuf++ = (char)('0' + (addr[i] / 100));
            *ipbuf++ = (char)('0' + ((addr[i] % 100) / 10));
            *ipbuf++ = (char)('0' + ((addr[i] % 100) % 10));
        } else if (addr[i] > 9) {
            *ipbuf++ = (char)('0' + (addr[i] / 10));
            *ipbuf++ = (char)('0' + (addr[i] % 10));
        } else {
            *ipbuf++ = (char)('0' + addr[i]);
        }

        if (i < 3)
            *ipbuf++ = '.';
    }
    *ipbuf = '\0';
    if (strlen(inet_ntoa_result) < 1)
        return NULL;

    return &inet_ntoa_result;
}

