/*
 * Frosted version of getaddrinfo.
 */

#include "sys/frosted.h"
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

extern int sys_getaddrinfo(const char *, const char *, const struct addrinfo *, struct addrinfo **);
extern void sys_freeaddrinfo(struct addrinfo *);

int getaddrinfo(const char *node, const char *service, const struct addrinfo *hints, struct addrinfo **res)
{
    int ret = sys_getaddrinfo(node, service, hints, res);
    if (ret < 0) {
        errno = 0 - ret;
        ret = -1;
    }
    return ret;
}

void freeaddrinfo(struct addrinfo *res)
{
    sys_freeaddrinfo(res);
}

/* Legacy gethostbyname call implementation */
static struct hostent PRIV_HOSTENT = { };
struct hostent *gethostbyname(const char *name)
{
    struct addrinfo *res;
    struct addrinfo hint = {.ai_family = AF_INET};
    int ret;
    if (!PRIV_HOSTENT.h_addr_list) {
        /* Done only once: reserve space for 2 entries */
        PRIV_HOSTENT.h_addr_list = malloc(2 * sizeof(void*));
        PRIV_HOSTENT.h_addr_list[1] = NULL;
    }
    ret = getaddrinfo(name, NULL, &hint, &res);
    if (ret == 0) {
        if (PRIV_HOSTENT.h_name != NULL) {
            free(PRIV_HOSTENT.h_name);
            PRIV_HOSTENT.h_name = NULL;
        }
        if (PRIV_HOSTENT.h_addr_list[0] != NULL) {
            free(PRIV_HOSTENT.h_addr_list[0]);
            PRIV_HOSTENT.h_addr_list[0] = NULL;
        }
        PRIV_HOSTENT.h_name = malloc(strlen(name));
        if (!PRIV_HOSTENT.h_name) {
            freeaddrinfo(res);
            return NULL;
        }
        strcpy(PRIV_HOSTENT.h_name, name);
        PRIV_HOSTENT.h_addrtype = res->ai_addr->sa_family;
        if (PRIV_HOSTENT.h_addrtype == AF_INET) {
            PRIV_HOSTENT.h_length = 4;
            PRIV_HOSTENT.h_addr_list[0] = malloc(4); 
            if (!PRIV_HOSTENT.h_addr_list[0]) {
                freeaddrinfo(res);
                return NULL;
            }
            memcpy (PRIV_HOSTENT.h_addr_list[0], &(((struct sockaddr_in *)res->ai_addr)->sin_addr.s_addr), 4);
        } else {
            /* Only IPv4 supported by this ancient call. */
            freeaddrinfo(res);
            return NULL;
        }
        freeaddrinfo(res);
        return &PRIV_HOSTENT;
    }
    return NULL;
}
