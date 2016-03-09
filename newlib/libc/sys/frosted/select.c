#include <stdint.h>
#include <sys/time.h>
#include <sys/select.h>
#include <poll.h>
#include <stdlib.h>
#include <unistd.h>

int select (int n, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, struct timeval *timeout)
{
    uint32_t time_ms = -1;
    struct pollfd *pfd = NULL;
    int pfd_n = 0;
    int i, pollret;

    if (timeout) {
        time_ms = timeout->tv_sec * 1000U + timeout->tv_usec / 1000;
    }

    for (i = 0; i < n; i++) {
        uint16_t events = 0;
        if (FD_ISSET(i, readfds))
            events |= POLLIN;
        if (FD_ISSET(i, writefds))
            events |= POLLOUT;
        if (FD_ISSET(i, exceptfds))
            events |= POLLERR | POLLHUP;


        if (events != 0) {
            pfd = realloc(pfd, (++pfd_n) * sizeof(struct pollfd));
            if (!pfd) {
                return -1;
            }
            pfd[pfd_n - 1].fd = i;
            pfd[pfd_n - 1].events = events;
        }
    }
    FD_ZERO(readfds);
    FD_ZERO(writefds);
    FD_ZERO(exceptfds);
    pollret = poll(pfd, pfd_n, time_ms);
    if (pollret < 0) {
        return -1;
    }
    for (i = 0; i < pfd_n; i++) {
        if (pfd[i].revents & POLLIN)
            FD_SET(pfd[i].fd, readfds);
        if (pfd[i].revents & POLLOUT)
            FD_SET(pfd[i].fd, writefds);
        if (pfd[i].revents & (POLLERR | POLLHUP))
            FD_SET(pfd[i].fd, exceptfds);
    }
    if (pfd)
        free(pfd);
    return pollret;
}

