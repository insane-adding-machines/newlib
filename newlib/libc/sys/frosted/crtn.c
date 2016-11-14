#include <fcntl.h>
#include <reent.h>

/* This is overridden by gcc if using -nostartfiles */
 
extern void exit(int code);
extern int main ();
extern void _init_signal();
 
extern struct _reent *_impure_ptr;
struct _reent * __getreent (void) {
    return _impure_ptr;
}


void _start(char *argv[]) {
    struct _reent impure_data = _REENT_INIT (impure_data);
    int ex;
    int argc = 0;
    if (argv) {
        while(argv[argc] != 0)
            argc++;
    }
    _impure_ptr = &impure_data;
    __sinit(_impure_ptr);
    ex = main(argc, argv);
    exit(ex);
}
