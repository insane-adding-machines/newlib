## Process this file with automake to generate Makefile.in

AUTOMAKE_OPTIONS = cygnus

INCLUDES = $(NEWLIB_CFLAGS) $(CROSS_CFLAGS) $(TARGET_CFLAGS)

AM_CCASFLAGS = $(INCLUDES)

noinst_LIBRARIES = lib.a

# crt0.o comes from libgloss
lib_a_SOURCES = \
	accept.c bind.c chdir.c chroot.c close.c closedir.c connect.c \
	dup2.c dup.c errno.c exec.c exit.c fgets.c fork.c free.c fstat.c getaddrinfo.c getcwd.c \
	gethostname.c getlogin.c getpid.c getppid.c getsockopt.c gettimeofday.c grp.c \
	inet.c ioctl.c \
	isatty.c kill.c link.c listen.c  lseek.c malloc.c malloc_trim.c mkdir.c \
	mount.c mutex.c mutex_init.c open.c opendir.c pipe.c \
	poll.c printf.c pwd.c read.c readdir.c recvfrom.c resource.c select.c semaphore.c \
	sem_init.c sendto.c setsockopt.c shutdown.c sigaction.c signal.c sigprocmask.c \
	sigsuspend.c sleep.c socket.c stat.c svc.s syscall.c syscalls.c syscall_table.c tcgetattr.c \
	tcsendbreak.c tcsetattr.c ttyname.c uid.c umask.c \
	umount.c unlink.c uname.c vfork.c wait.c waitpid.c write.c

lib_a_CCASFLAGS = $(AM_CCASFLAGS)
lib_a_CFLAGS = $(AM_CFLAGS)

all-local: crt0.o

ACLOCAL_AMFLAGS = -I ../../.. -I ../../../..
CONFIG_STATUS_DEPENDENCIES = $(newlib_basedir)/configure.host
