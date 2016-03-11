/*
 * Frosted version of dirname.
 */

char *dirname(char *path)
{
    int len;
    static char dirname_path[128];

    if ((!path)) {
	    strcpy(dirname_path, ".");
	    return (dirname_path);
    }

    len = strlen(path);
    if (!len) {
	    strcpy(dirname_path, ".");
	    return (dirname_path);
    }

    strcpy(dirname_path, path);

    char *ptr, *start;
    start = dirname_path;
    ptr = start + len - 1;

    while (*ptr != '/') {
	    *ptr-- = '\0';
    }

    while ((*ptr == '/') && (ptr != start)) {
	    *ptr-- = '\0';
    }

    return (dirname_path);
}
