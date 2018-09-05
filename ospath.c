/*********************************************
 * include
 *********************************************/
#include <stdio.h>
#include <string.h>

/*********************************************
 * define
 *********************************************/
#define OS_SEP '/'

/*********************************************
 * private function
 *********************************************/

static int strpos(char src[], char c)
{
    int idx;
    char *ret;

    ret = strrchr(src, c);
    idx = ret - src;

    return idx;
}

static int split(char src[], char c, char s1[], char s2[])
{
    char *ret;
    int pos;

    ret = strrchr(src, c);
    if (ret == NULL ) {
        return -1;
    }

    pos = ret - src;

    if(s1 != NULL) {
        strncpy(s1, src, pos);
        s1[pos] = '\0';
    }

    if(s2 != NULL) {
        strcpy(s2, ret);
    }

    return 1;
}

/*********************************************
 * public function
 *********************************************/

int os_path_splitext(char path[], char base[], char ext[])
{
    if( split(path, '.', base, ext) < 0) {
        return -1;
    }
    return 1;
}

int os_path_split(char path[],char dir[],char fname[])
{
    if( split(path, OS_SEP, dir, fname) < 0) {
        return -1;
    }

    char *tmp = fname+1;
    int len = strlen(tmp);

    memmove(fname, tmp, len);

    return 1;
}

int os_path_dirname(char path[], char dir[])
{
    if( split(path, OS_SEP, dir, NULL) < 0) {
        return -1;
    }
    return 1;
}

int os_path_basename(char path[], char fname[])
{
    if( split(path, OS_SEP, NULL, fname) < 0) {
        return -1;
    }
    char *tmp = fname+1;
    int len = strlen(tmp);

    memmove(fname, tmp, len);
    return 1;
}

int os_path_join(char s1[], char s2[], char s[])
{
    int idx;

    idx = strpos(s1, OS_SEP);

    if(strlen(s1) == (idx+1)) {
        sprintf(s, "%s%s", s1, s2);
    }
    else {
        sprintf(s, "%s/%s", s1, s2);
    }

    return 1;
}

int os_path_exists(char path[])
{
    FILE *fp;
    if ((fp = fopen(path, "r")) == NULL) {
        return -1;
    }
    fclose(fp);

    return 1;
}
