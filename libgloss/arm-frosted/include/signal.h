/* Frosted version of signals */

#ifndef SIGNAL_H_INCLUDED
#define SIGNAL_H_INCLUDED
#include <sys/types.h>
#include <stdint.h>

#define SIGHUP       1
#define SIGINT       2
#define SIGQUIT      3
#define SIGILL       4
#define SIGTRAP      5
#define SIGABRT      6
#define SIGBUS       7
#define SIGFPE       8
#define SIGKILL      9
#define SIGUSR1     10
#define SIGSEGV     11
#define SIGUSR2     12
#define SIGPIPE     13
#define SIGALRM     14
#define SIGTERM     15
#define SIGSTKFLT   16
#define SIGCHLD     17
#define SIGCONT     18
#define SIGSTOP     19
#define SIGTTIN     20

#ifdef __frosted__      /* TEMP FOR BUSYBOX */
    #define NSIG	    23  /* signal 0 implied */
    #define	SIGXCPU	    24  /* exceeded CPU time limit */
    #define	SIGXFSZ	    25  /* exceeded file size limit */
    #define	SIGVTALRM   26	/* virtual time alarm */
    #define SIGMAX      27
    typedef void (*_sig_func_ptr)(int);
    typedef _sig_func_ptr sighandler_t;
    #define SA_RESTART	0x10000000u
#else
    #define SIGMAX      21
#endif

typedef uint32_t sigset_t;
#define SI_USER    1    /* Sent by a user. kill(), abort(), etc */
#define SI_QUEUE   2    /* Sent by sigqueue() */
#define SI_TIMER   3    /* Sent by expiration of a timer_settime() timer */
#define SI_ASYNCIO 4    /* Indicates completion of asycnhronous IO */
#define SI_MESGQ   5    /* Indicates arrival of a message at an empty queue */

#define SIG_DFL ((void (*)(int)) 0)
#define SIG_IGN ((void (*)(int)) 0xFFFFFFFF)

union sigval {
  int    sival_int;    /* Integer signal value */
  void  *sival_ptr;    /* Pointer signal value */
};

typedef struct {
  int          si_signo;    /* Signal number */
  int          si_code;     /* Cause of the signal */
  union sigval si_value;    /* Signal value */
} siginfo_t;

struct sigevent {
  int              sigev_notify;               /* Notification type */
  int              sigev_signo;                /* Signal number */
  union sigval     sigev_value;                /* Signal value */
};

struct sigaction {
    void     (*sa_handler)(int);
    void     (*sa_sigaction)(int, siginfo_t *, void *);
    sigset_t   sa_mask;
    int        sa_flags;
    void     (*sa_restorer)(void);
};

int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);
int sigemptyset(sigset_t *set);
int sigfillset(sigset_t *set);
int sigaddset(sigset_t *set, int signum);
int sigdelset(sigset_t *set, int signum);
int sigismember(const sigset_t *set, int signum);

int sigisemptyset(const sigset_t *set);
int sigorset(sigset_t *dest, const sigset_t *left, const sigset_t *right);
int sigandset(sigset_t *dest, const sigset_t *left, const sigset_t *right);

/* Process mask functions */
#define SIG_SETMASK 0	/* set mask with sigprocmask() */
#define SIG_BLOCK 1	/* set of signals to block */
#define SIG_UNBLOCK 2	/* set of signals to, well, unblock */
int sigprocmask(int how, const sigset_t *set, sigset_t *oldset);

#endif
