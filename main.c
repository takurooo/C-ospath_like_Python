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
    printf("os_path_splitext base     : %s\n", base);
    printf("os_path_splitext ext      : %s\n", ext);

    os_path_dirname(path, dir);
    printf("os_path_dirname  dir      : %s\n", dir);

    os_path_basename(path, fname);
    printf("os_path_basename fname    : %s\n", fname);

    os_path_split(path, dir, fname);
    printf("os_path_split    dir      : %s\n", dir);
    printf("os_path_split    fname    : %s\n", fname);

    os_path_join("abc/def", "hoge.txt", base);
    printf("os_path_join     path     : %s\n", base);

    os_path_join("abc/def/", "hoge.txt", base);
    printf("os_path_join     path     : %s\n", base);

    return 0;
}
