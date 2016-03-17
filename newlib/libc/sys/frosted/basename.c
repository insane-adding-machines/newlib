/*
 * Frosted version of basename.
 */

char *basename(char *path)
{
    int len;
    static char basename_name[128];

    if ((!path)) {
	    strcpy(basename_name, ".");
	    return (basename_name);
    }

    len = strlen(path);
    if (!len) {
	    strcpy(basename_name, ".");
	    return (basename_name);
    }

    /* buffer overflow? */
    strcpy(basename_name, path);

    char *ptr, *start;
    start = basename_name;
    //start = path;
    ptr = start + len - 1;

    while ((*ptr == '/') && (ptr != start)) {
	    *ptr-- = '\0';
    }

    while ((*ptr != '/') && (ptr != start)) {
	    *ptr--;// = '\0';
    }

    return ptr;
}
