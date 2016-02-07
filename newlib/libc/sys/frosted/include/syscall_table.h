/* The file syscall_table.h is auto generated. DO NOT EDIT, CHANGES WILL BE LOST. */
/* If you want to add syscalls, use syscall_table_gen.py  */

#define SYS_SLEEP 			(0)
#define SYS_SUSPEND 			(1)
#define SYS_THREAD_CREATE 			(2)
#define SYS_THREAD_JOIN 			(3)
#define SYS_TEST 			(4)
#define SYS_GETPID 			(5)
#define SYS_GETPPID 			(6)
#define SYS_OPEN 			(7)
#define SYS_CLOSE 			(8)
#define SYS_READ 			(9)
#define SYS_WRITE 			(10)
#define SYS_SEEK 			(11)
#define SYS_MKDIR 			(12)
#define SYS_UNLINK 			(13)
#define SYS_GETTIMEOFDAY 			(14)
#define SYS_MALLOC 			(15)
#define SYS_FREE 			(16)
#define SYS_CALLOC 			(17)
#define SYS_REALLOC 			(18)
#define SYS_OPENDIR 			(19)
#define SYS_READDIR 			(20)
#define SYS_CLOSEDIR 			(21)
#define SYS_STAT 			(22)
#define SYS_POLL 			(23)
#define SYS_IOCTL 			(24)
#define SYS_LINK 			(25)
#define SYS_CHDIR 			(26)
#define SYS_GETCWD 			(27)
#define SYS_SEM_INIT 			(28)
#define SYS_SEM_POST 			(29)
#define SYS_SEM_WAIT 			(30)
#define SYS_SEM_DESTROY 			(31)
#define SYS_MUTEX_INIT 			(32)
#define SYS_MUTEX_UNLOCK 			(33)
#define SYS_MUTEX_LOCK 			(34)
#define SYS_MUTEX_DESTROY 			(35)
#define SYS_SOCKET 			(36)
#define SYS_BIND 			(37)
#define SYS_ACCEPT 			(38)
#define SYS_CONNECT 			(39)
#define SYS_LISTEN 			(40)
#define SYS_SENDTO 			(41)
#define SYS_RECVFROM 			(42)
#define SYS_SETSOCKOPT 			(43)
#define SYS_GETSOCKOPT 			(44)
#define SYS_SHUTDOWN 			(45)
#define SYS_DUP 			(46)
#define SYS_DUP2 			(47)
#define SYS_MOUNT 			(48)
#define SYS_UMOUNT 			(49)
#define SYS_KILL 			(50)
#define SYS_ISATTY 			(51)
#define SYS_EXEC 			(52)
#define SYS_EXECB 			(53)
#define SYS_TTYNAME_R 			(54)
#define SYS_EXIT 			(55)
#define SYS_TCSETATTR 			(56)
#define SYS_TCGETATTR 			(57)
#define SYS_TCSENDBREAK 			(58)
#define SYS_PIPE2 			(59)
#define SYS_SIGACTION 			(60)
#define SYS_SIGPROCMASK 			(61)
#define SYS_SIGSUSPEND 			(62)
#define SYS_VFORK 			(63)
#define SYS_WAITPID 			(64)
#define SYS_LSTAT 			(65)
#define _SYSCALLS_NR (66) /* We have 66 syscalls! */
