AUTOMAKE_OPTIONS = cygnus
INCLUDES = $(NEWLIB_CFLAGS) $(CROSS_CFLAGS) $(TARGET_CFLAGS)
AM_CCASFLAGS = $(INCLUDES)
 
noinst_LIBRARIES = lib.a


extra_objs = accept.o bind.o chdir.o chroot.o close.o closedir.o connect.o crt0.o dup2.o dup.o errno.o exec.o exit.o fgets.o fork.o free.o fstat.o getcwd.o gethostname.o getlogin.o getpid.o getppid.o getsockopt.o grp.o ioctl.o isatty.o kill.o link.o listen.o lseek.o malloc.o malloc_trim.o mkdir.o mount.o mutex.o mutex_init.o open.o opendir.o pipe.o poll.o printf.o pwd.o read.o readdir.o recvfrom.o resource.o semaphore.o sem_init.o sendto.o setsockopt.o shutdown.o sigaction.o signal.o sigprocmask.o sigsuspend.o sleep.o socket.o stat.o syscall.o syscalls.o syscall_table.o tcgetattr.o tcsendbreak.o tcsetattr.o thread_create.o thread_join.o ttyname.o uid.o umask.o umount.o unlink.o vfork.o wait.o waitpid.o write.o
  
 
lib_a_SOURCES =
lib_a_LIBADD = $(extra_objs)
EXTRA_lib_a_SOURCES = accept.c bind.c chdir.c chroot.c close.c closedir.c connect.c crt0.c dup2.c dup.c errno.c exec.c exit.c fgets.c fork.c free.c fstat.c getcwd.c gethostname.c getlogin.c getpid.c getppid.c getsockopt.c grp.c ioctl.c isatty.c kill.c link.c listen.c lseek.c malloc.c malloc_trim.c mkdir.c mount.c mutex.c mutex_init.c open.c opendir.c pipe.c poll.c printf.c pwd.c read.c readdir.c recvfrom.c resource.c semaphore.c sem_init.c sendto.c setsockopt.c shutdown.c sigaction.c signal.c sigprocmask.c sigsuspend.c sleep.c socket.c stat.c syscall.c syscalls.c syscall_table.c tcgetattr.c tcsendbreak.c tcsetattr.c thread_create.c thread_join.c ttyname.c uid.c umask.c umount.c unlink.c vfork.c wait.c waitpid.c write.c
lib_a_DEPENDENCIES = $(extra_objs)      # syscalls.c into multiple files
lib_a_CCASFLAGS = $(AM_CCASFLAGS)
lib_a_CFLAGS = $(AM_CFLAGS)
  
all: crt0.o

ACLOCAL_AMFLAGS = -I ../../..
CONFIG_STATUS_DEPENDENCIES = $(newlib_basedir)/configure.host
