/* The file syscall_table.c is auto generated. DO NOT EDIT, CHANGES WILL BE LOST. */
/* If you want to add syscalls, use syscall_table_gen.py  */

#include <stdint.h>
#include "syscall_table.h"
/* Syscall: sleep(1 arguments) */
int sys_sleep(uint32_t arg1){
    return syscall(SYS_SLEEP, arg1, 0, 0, 0, 0); 
}

/* Syscall: suspend(1 arguments) */
int sys_suspend(uint32_t arg1){
    return syscall(SYS_SUSPEND, arg1, 0, 0, 0, 0); 
}

/* Syscall: getpid(0 arguments) */
int sys_getpid(void){
    return syscall(SYS_GETPID, 0, 0, 0, 0, 0); 
}

/* Syscall: getppid(0 arguments) */
int sys_getppid(void){
    return syscall(SYS_GETPPID, 0, 0, 0, 0, 0); 
}

/* Syscall: open(3 arguments) */
int sys_open(uint32_t arg1, uint32_t arg2, uint32_t arg3){
    return syscall(SYS_OPEN, arg1, arg2, arg3, 0,  0); 
}

/* Syscall: close(1 arguments) */
int sys_close(uint32_t arg1){
    return syscall(SYS_CLOSE, arg1, 0, 0, 0, 0); 
}

/* Syscall: read(3 arguments) */
int sys_read(uint32_t arg1, uint32_t arg2, uint32_t arg3){
    return syscall(SYS_READ, arg1, arg2, arg3, 0,  0); 
}

/* Syscall: write(3 arguments) */
int sys_write(uint32_t arg1, uint32_t arg2, uint32_t arg3){
    return syscall(SYS_WRITE, arg1, arg2, arg3, 0,  0); 
}

/* Syscall: seek(3 arguments) */
int sys_seek(uint32_t arg1, uint32_t arg2, uint32_t arg3){
    return syscall(SYS_SEEK, arg1, arg2, arg3, 0,  0); 
}

/* Syscall: mkdir(2 arguments) */
int sys_mkdir(uint32_t arg1, uint32_t arg2){
    return syscall(SYS_MKDIR, arg1, arg2, 0, 0, 0); 
}

/* Syscall: unlink(1 arguments) */
int sys_unlink(uint32_t arg1){
    return syscall(SYS_UNLINK, arg1, 0, 0, 0, 0); 
}

/* Syscall: gettimeofday(1 arguments) */
int sys_gettimeofday(uint32_t arg1){
    return syscall(SYS_GETTIMEOFDAY, arg1, 0, 0, 0, 0); 
}

/* Syscall: malloc(1 arguments) */
int sys_malloc(uint32_t arg1){
    return syscall(SYS_MALLOC, arg1, 0, 0, 0, 0); 
}

/* Syscall: free(1 arguments) */
int sys_free(uint32_t arg1){
    return syscall(SYS_FREE, arg1, 0, 0, 0, 0); 
}

/* Syscall: calloc(2 arguments) */
int sys_calloc(uint32_t arg1, uint32_t arg2){
    return syscall(SYS_CALLOC, arg1, arg2, 0, 0, 0); 
}

/* Syscall: realloc(2 arguments) */
int sys_realloc(uint32_t arg1, uint32_t arg2){
    return syscall(SYS_REALLOC, arg1, arg2, 0, 0, 0); 
}

/* Syscall: opendir(1 arguments) */
int sys_opendir(uint32_t arg1){
    return syscall(SYS_OPENDIR, arg1, 0, 0, 0, 0); 
}

/* Syscall: readdir(2 arguments) */
int sys_readdir(uint32_t arg1, uint32_t arg2){
    return syscall(SYS_READDIR, arg1, arg2, 0, 0, 0); 
}

/* Syscall: closedir(1 arguments) */
int sys_closedir(uint32_t arg1){
    return syscall(SYS_CLOSEDIR, arg1, 0, 0, 0, 0); 
}

/* Syscall: stat(2 arguments) */
int sys_stat(uint32_t arg1, uint32_t arg2){
    return syscall(SYS_STAT, arg1, arg2, 0, 0, 0); 
}

/* Syscall: poll(3 arguments) */
int sys_poll(uint32_t arg1, uint32_t arg2, uint32_t arg3){
    return syscall(SYS_POLL, arg1, arg2, arg3, 0,  0); 
}

/* Syscall: ioctl(3 arguments) */
int sys_ioctl(uint32_t arg1, uint32_t arg2, uint32_t arg3){
    return syscall(SYS_IOCTL, arg1, arg2, arg3, 0,  0); 
}

/* Syscall: link(2 arguments) */
int sys_link(uint32_t arg1, uint32_t arg2){
    return syscall(SYS_LINK, arg1, arg2, 0, 0, 0); 
}

/* Syscall: chdir(1 arguments) */
int sys_chdir(uint32_t arg1){
    return syscall(SYS_CHDIR, arg1, 0, 0, 0, 0); 
}

/* Syscall: getcwd(2 arguments) */
int sys_getcwd(uint32_t arg1, uint32_t arg2){
    return syscall(SYS_GETCWD, arg1, arg2, 0, 0, 0); 
}

/* Syscall: sem_init(1 arguments) */
int sys_sem_init(uint32_t arg1){
    return syscall(SYS_SEM_INIT, arg1, 0, 0, 0, 0); 
}

/* Syscall: sem_post(1 arguments) */
int sys_sem_post(uint32_t arg1){
    return syscall(SYS_SEM_POST, arg1, 0, 0, 0, 0); 
}

/* Syscall: sem_wait(1 arguments) */
int sys_sem_wait(uint32_t arg1){
    return syscall(SYS_SEM_WAIT, arg1, 0, 0, 0, 0); 
}

/* Syscall: sem_destroy(1 arguments) */
int sys_sem_destroy(uint32_t arg1){
    return syscall(SYS_SEM_DESTROY, arg1, 0, 0, 0, 0); 
}

/* Syscall: mutex_init(0 arguments) */
int sys_mutex_init(void){
    return syscall(SYS_MUTEX_INIT, 0, 0, 0, 0, 0); 
}

/* Syscall: mutex_unlock(1 arguments) */
int sys_mutex_unlock(uint32_t arg1){
    return syscall(SYS_MUTEX_UNLOCK, arg1, 0, 0, 0, 0); 
}

/* Syscall: mutex_lock(1 arguments) */
int sys_mutex_lock(uint32_t arg1){
    return syscall(SYS_MUTEX_LOCK, arg1, 0, 0, 0, 0); 
}

/* Syscall: mutex_destroy(1 arguments) */
int sys_mutex_destroy(uint32_t arg1){
    return syscall(SYS_MUTEX_DESTROY, arg1, 0, 0, 0, 0); 
}

/* Syscall: socket(3 arguments) */
int sys_socket(uint32_t arg1, uint32_t arg2, uint32_t arg3){
    return syscall(SYS_SOCKET, arg1, arg2, arg3, 0,  0); 
}

/* Syscall: bind(2 arguments) */
int sys_bind(uint32_t arg1, uint32_t arg2){
    return syscall(SYS_BIND, arg1, arg2, 0, 0, 0); 
}

/* Syscall: accept(2 arguments) */
int sys_accept(uint32_t arg1, uint32_t arg2){
    return syscall(SYS_ACCEPT, arg1, arg2, 0, 0, 0); 
}

/* Syscall: connect(2 arguments) */
int sys_connect(uint32_t arg1, uint32_t arg2){
    return syscall(SYS_CONNECT, arg1, arg2, 0, 0, 0); 
}

/* Syscall: listen(2 arguments) */
int sys_listen(uint32_t arg1, uint32_t arg2){
    return syscall(SYS_LISTEN, arg1, arg2, 0, 0, 0); 
}

/* Syscall: sendto(5 arguments) */
int sys_sendto(uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4, uint32_t arg5){
    return syscall(SYS_SENDTO, arg1, arg2, arg3, arg4, arg5); 
}

/* Syscall: recvfrom(5 arguments) */
int sys_recvfrom(uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4, uint32_t arg5){
    return syscall(SYS_RECVFROM, arg1, arg2, arg3, arg4, arg5); 
}

/* Syscall: setsockopt(5 arguments) */
int sys_setsockopt(uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4, uint32_t arg5){
    return syscall(SYS_SETSOCKOPT, arg1, arg2, arg3, arg4, arg5); 
}

/* Syscall: getsockopt(5 arguments) */
int sys_getsockopt(uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4, uint32_t arg5){
    return syscall(SYS_GETSOCKOPT, arg1, arg2, arg3, arg4, arg5); 
}

/* Syscall: shutdown(2 arguments) */
int sys_shutdown(uint32_t arg1, uint32_t arg2){
    return syscall(SYS_SHUTDOWN, arg1, arg2, 0, 0, 0); 
}

/* Syscall: dup(1 arguments) */
int sys_dup(uint32_t arg1){
    return syscall(SYS_DUP, arg1, 0, 0, 0, 0); 
}

/* Syscall: dup2(2 arguments) */
int sys_dup2(uint32_t arg1, uint32_t arg2){
    return syscall(SYS_DUP2, arg1, arg2, 0, 0, 0); 
}

/* Syscall: mount(5 arguments) */
int sys_mount(uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4, uint32_t arg5){
    return syscall(SYS_MOUNT, arg1, arg2, arg3, arg4, arg5); 
}

/* Syscall: umount(2 arguments) */
int sys_umount(uint32_t arg1, uint32_t arg2){
    return syscall(SYS_UMOUNT, arg1, arg2, 0, 0, 0); 
}

/* Syscall: kill(2 arguments) */
int sys_kill(uint32_t arg1, uint32_t arg2){
    return syscall(SYS_KILL, arg1, arg2, 0, 0, 0); 
}

/* Syscall: isatty(1 arguments) */
int sys_isatty(uint32_t arg1){
    return syscall(SYS_ISATTY, arg1, 0, 0, 0, 0); 
}

/* Syscall: exec(2 arguments) */
int sys_exec(uint32_t arg1, uint32_t arg2){
    return syscall(SYS_EXEC, arg1, arg2, 0, 0, 0); 
}

/* Syscall: ttyname_r(3 arguments) */
int sys_ttyname_r(uint32_t arg1, uint32_t arg2, uint32_t arg3){
    return syscall(SYS_TTYNAME_R, arg1, arg2, arg3, 0,  0); 
}

/* Syscall: exit(1 arguments) */
int sys_exit(uint32_t arg1){
    return syscall(SYS_EXIT, arg1, 0, 0, 0, 0); 
}

/* Syscall: tcsetattr(3 arguments) */
int sys_tcsetattr(uint32_t arg1, uint32_t arg2, uint32_t arg3){
    return syscall(SYS_TCSETATTR, arg1, arg2, arg3, 0,  0); 
}

/* Syscall: tcgetattr(2 arguments) */
int sys_tcgetattr(uint32_t arg1, uint32_t arg2){
    return syscall(SYS_TCGETATTR, arg1, arg2, 0, 0, 0); 
}

/* Syscall: tcsendbreak(2 arguments) */
int sys_tcsendbreak(uint32_t arg1, uint32_t arg2){
    return syscall(SYS_TCSENDBREAK, arg1, arg2, 0, 0, 0); 
}

/* Syscall: pipe2(2 arguments) */
int sys_pipe2(uint32_t arg1, uint32_t arg2){
    return syscall(SYS_PIPE2, arg1, arg2, 0, 0, 0); 
}

/* Syscall: sigaction(3 arguments) */
int sys_sigaction(uint32_t arg1, uint32_t arg2, uint32_t arg3){
    return syscall(SYS_SIGACTION, arg1, arg2, arg3, 0,  0); 
}

/* Syscall: sigprocmask(3 arguments) */
int sys_sigprocmask(uint32_t arg1, uint32_t arg2, uint32_t arg3){
    return syscall(SYS_SIGPROCMASK, arg1, arg2, arg3, 0,  0); 
}

/* Syscall: sigsuspend(1 arguments) */
int sys_sigsuspend(uint32_t arg1){
    return syscall(SYS_SIGSUSPEND, arg1, 0, 0, 0, 0); 
}

/* Syscall: vfork(0 arguments) */
int sys_vfork(void){
    return syscall(SYS_VFORK, 0, 0, 0, 0, 0); 
}

/* Syscall: waitpid(3 arguments) */
int sys_waitpid(uint32_t arg1, uint32_t arg2, uint32_t arg3){
    return syscall(SYS_WAITPID, arg1, arg2, arg3, 0,  0); 
}

/* Syscall: lstat(2 arguments) */
int sys_lstat(uint32_t arg1, uint32_t arg2){
    return syscall(SYS_LSTAT, arg1, arg2, 0, 0, 0); 
}

/* Syscall: uname(1 arguments) */
int sys_uname(uint32_t arg1){
    return syscall(SYS_UNAME, arg1, 0, 0, 0, 0); 
}

/* Syscall: getaddrinfo(4 arguments) */
int sys_getaddrinfo(uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4){
    return syscall(SYS_GETADDRINFO, arg1, arg2, arg3, arg4, 0); 
}

/* Syscall: freeaddrinfo(1 arguments) */
int sys_freeaddrinfo(uint32_t arg1){
    return syscall(SYS_FREEADDRINFO, arg1, 0, 0, 0, 0); 
}

/* Syscall: fstat(2 arguments) */
int sys_fstat(uint32_t arg1, uint32_t arg2){
    return syscall(SYS_FSTAT, arg1, arg2, 0, 0, 0); 
}

/* Syscall: getsockname(2 arguments) */
int sys_getsockname(uint32_t arg1, uint32_t arg2){
    return syscall(SYS_GETSOCKNAME, arg1, arg2, 0, 0, 0); 
}

/* Syscall: getpeername(2 arguments) */
int sys_getpeername(uint32_t arg1, uint32_t arg2){
    return syscall(SYS_GETPEERNAME, arg1, arg2, 0, 0, 0); 
}

/* Syscall: readlink(3 arguments) */
int sys_readlink(uint32_t arg1, uint32_t arg2, uint32_t arg3){
    return syscall(SYS_READLINK, arg1, arg2, arg3, 0,  0); 
}

/* Syscall: fcntl(3 arguments) */
int sys_fcntl(uint32_t arg1, uint32_t arg2, uint32_t arg3){
    return syscall(SYS_FCNTL, arg1, arg2, arg3, 0,  0); 
}

/* Syscall: setsid(0 arguments) */
int sys_setsid(void){
    return syscall(SYS_SETSID, 0, 0, 0, 0, 0); 
}

