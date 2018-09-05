/*********************************************
 * include
 *********************************************/
#include <stdio.h>
#include "ospath.h"

/*********************************************
 * define
 *********************************************/



/*********************************************
 * main function
 *********************************************/
int main(void)
{
    char path[] = "abc/def/hoge.txt";
    char base[128];
    char ext[128];
    char dir[128];
    char fname[128];

    printf("input path : %s\n", path);

    os_path_splitext(path, base, ext);
    printf("base     : %s\n", base);
    printf("ext      : %s\n", ext);

    os_path_dirname(path, dir);
    printf("dir      : %s\n", dir);

    os_path_basename(path, fname);
    printf("fname    : %s\n", fname);

    os_path_split(path, dir, fname);
    printf("dir      : %s\n", dir);
    printf("fname    : %s\n", fname);

    os_path_join("abc/def", "hoge.txt", base);
    printf("path     : %s\n", base);

    return 1;
}
