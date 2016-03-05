#include <fcntl.h>
 
extern void exit(int code);
extern int main ();
extern void _init_signal();

uint16_t errno;
 
/* no argv, argc for now */
void _start(char *argv[]) {
    int ex;
    int argc = 0;
    if (argv) {
        while(argv[argc] != 0)
            argc++;
    }
    ex = main(argc, argv);
    exit(ex);
}
