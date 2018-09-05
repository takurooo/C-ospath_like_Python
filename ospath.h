#ifndef _OS_PATH_
#define _OS_PATH_

int os_path_splitext(char path[], char base[], char ext[]);
int os_path_split(char path[],char dir[],char fname[]);
int os_path_dirname(char path[], char dir[]);
int os_path_basename(char path[], char fname[]);
int os_path_join(char s1[], char s2[], char s[]);
int os_path_exists(char path[]);

#endif
