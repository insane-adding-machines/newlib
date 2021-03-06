/*
 * Frosted version of fgets.
 */

#include "sys/frosted.h"
#include <errno.h>
#include <stdio.h>

char *fgets(char *s, int size, FILE *stream)
{
    int r, tot = 0;
    if (stream != stdin)
        return NULL;

    s[0] = '\0';

    while (tot < (size - 1)) {
        r = read(0, s + tot, 1);
        if (r > 0)
           tot++; 
        s[tot] = '\0';
        if (r <= 0) {
            if (tot == 0)
                return NULL;
            break;
        }
        if (s[tot - 1] == '\r')
            s[tot - 1]  = '\n';
        if (s[tot - 1] == '\n')
            break;
    }
    return s;
}




