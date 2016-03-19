/* The file syscall_table.h is auto generated. DO NOT EDIT, CHANGES WILL BE LOST. */
/* If you want to add syscalls, use syscall_table_gen.py  */

#define SYS_SLEEP 			(0)
#define SYS_SUSPEND 			(1)
#define SYS_GETPID 			(2)
#define SYS_GETPPID 			(3)
#define SYS_OPEN 			(4)
#define SYS_CLOSE 			(5)
#define SYS_READ 			(6)
#define SYS_WRITE 			(7)
#define SYS_SEEK 			(8)
#define SYS_MKDIR 			(9)
#define SYS_UNLINK 			(10)
#define SYS_GETTIMEOFDAY 			(11)
#define SYS_MALLOC 			(12)
#define SYS_FREE 			(13)
#define SYS_CALLOC 			(14)
#define SYS_REALLOC 			(15)
#define SYS_OPENDIR 			(16)
#define SYS_READDIR 			(17)
#define SYS_CLOSEDIR 			(18)
#define SYS_STAT 			(19)
#define SYS_POLL 			(20)
#define SYS_IOCTL 			(21)
#define SYS_LINK 			(22)
#define SYS_CHDIR 			(23)
#define SYS_GETCWD 			(24)
#define SYS_SEM_INIT 			(25)
#define SYS_SEM_POST 			(26)
#define SYS_SEM_WAIT 			(27)
#define SYS_SEM_DESTROY 			(28)
#define SYS_MUTEX_INIT 			(29)
#define SYS_MUTEX_UNLOCK 			(30)
#define SYS_MUTEX_LOCK 			(31)
#define SYS_MUTEX_DESTROY 			(32)
#define SYS_SOCKET 			(33)
#define SYS_BIND 			(34)
#define SYS_ACCEPT 			(35)
#define SYS_CONNECT 			(36)
#define SYS_LISTEN 			(37)
#define SYS_SENDTO 			(38)
#define SYS_RECVFROM 			(39)
#define SYS_SETSOCKOPT 			(40)
#define SYS_GETSOCKOPT 			(41)
#define SYS_SHUTDOWN 			(42)
#define SYS_DUP 			(43)
#define SYS_DUP2 			(44)
#define SYS_MOUNT 			(45)
#define SYS_UMOUNT 			(46)
#define SYS_KILL 			(47)
#define SYS_ISATTY 			(48)
#define SYS_EXEC 			(49)
#define SYS_TTYNAME_R 			(50)
#define SYS_EXIT 			(51)
#define SYS_TCSETATTR 			(52)
#define SYS_TCGETATTR 			(53)
#define SYS_TCSENDBREAK 			(54)
#define SYS_PIPE2 			(55)
#define SYS_SIGACTION 			(56)
#define SYS_SIGPROCMASK 			(57)
#define SYS_SIGSUSPEND 			(58)
#define SYS_VFORK 			(59)
#define SYS_WAITPID 			(60)
#define SYS_LSTAT 			(61)
#define SYS_UNAME 			(62)
#define SYS_GETADDRINFO 			(63)
#define SYS_FREEADDRINFO 			(64)
#define SYS_FSTAT 			(65)
#define SYS_GETSOCKNAME 			(66)
#define SYS_GETPEERNAME 			(67)
#define SYS_READLINK 			(68)
#define _SYSCALLS_NR (69) /* We have 69 syscalls! */
