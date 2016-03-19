#include "syscall_table.h"
#include "syscalls.h"
#include "sys/syslimits.h"
#include "sys/stat.h"
#include "sys/types.h"
#include <string.h>
#include <errno.h>


extern int readlink(const char* file, char *buf, size_t len);
extern void* malloc(int size);
extern char* getcwd(char *buf, size_t size);
extern int lstat(const char* path, struct stat* buf);


static int level_count(char* path){
    char* p;
    int c;
    c = 0;
    p = path;
    while(*p!=0){
        if(*p == '/'){
            c++;
            while(*p == '/')
                p++;
        }
        p++;
    }
    return c+1;
}


static char *remove_dots(char* path){
    int i, j, s, k, c;
    c = level_count(path);
    char **strip, **res;
    char* final;
    char *p, *n;
    p = n = path;
    final = (char*) malloc(sizeof(char)*PATH_MAX);
    final[0] = 0;
    strip = (char**) malloc(sizeof(char*)*c);
    i = j = s = k= 0;
    while(*n != 0){
        if(*n == '/'){
            strip[k] = (char*) malloc(sizeof(char)*(n-p+2));
            strncpy(strip[k], p, n-p+1);
            strip[k][n-p+1] = 0;
            while(*n == '/') n++;
            p = n;
            k++;
        }
        else
            n++;
    }
    strip[k] = (char*) malloc(sizeof(char)*(n-p+2));
    strncpy(strip[k], p, n-p+1);
    strip[k][n-p+1] = 0;
    k++;
    for(i = 0; i < k; i++){
        if(strcmp(strip[i], "./") == 0 || strcmp(strip[i], ".") == 0)
            continue;
        else if(strcmp(strip[i], "../") == 0 || strcmp(strip[i], "..") == 0){
            if( j > 1 )
                j--;
        }
        else{
            strcpy(strip[j], strip[i]);
            j++;
        }
    }
    for(i=0; i < j; i++)
        strcat(final, strip[i]);
    strcpy(path, final);
    return final;
}


char *realpath(const char* path, char *resolved_path){
    int i, j, l, b;
    size_t s;
    char p[NAME_MAX];
    char cwd[PATH_MAX], link[PATH_MAX];
    struct stat buf;
    if(!resolved_path)
        resolved_path = (char*) malloc(sizeof(char)*PATH_MAX);
    if(!getcwd(cwd, PATH_MAX))
        return NULL;
    if(strcmp(cwd, "/") != 0)
        strcat(cwd, "/");
    strcpy(resolved_path, path);
    if(resolved_path[0] != '/'){
        strcat(cwd, resolved_path);
        strcpy(resolved_path, cwd);
    }
    b = 1;
    while(b){
        remove_dots(resolved_path);
        l = strlen(resolved_path); 
        b = 0;
        for(i=0; i<=l; i++){
            if( i == l || (resolved_path[i] == '/' && i != 0)){
                strncpy(p, resolved_path, i);
                p[i] = 0;
                if(lstat(p, &buf) < 0)
                    return NULL;
                if(S_ISLNK(buf.st_mode)){
                    if(stat(p, &buf) < 0)
                        return NULL;
                    if(S_ISDIR(buf.st_mode)){
                        s = readlink(p, link, PATH_MAX);
                        link[s] = 0;
                        if( link[0] == '/' )
                            strcpy( resolved_path, link );
                        else{
                            j = i;
                            if( resolved_path[j] == '/')
                                j--;
                            while( resolved_path[j] != '/' && j > 0)
                                j--;
                            j = j > 0 ? j+1 : j;
                            strcpy(resolved_path+j, link);
                        }
                        b = 1;
                    }
                }
            }
        }
    }
    remove_dots(resolved_path);
    return resolved_path;
}
