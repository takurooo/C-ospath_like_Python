# c-ospath
Python os.path module in C  
- os.path.splitext  
- os.path.dirname  
- os.path.basename  
- os.path.split  
- os.path.join  


# Sample Code
```C
int main(void)
{
    char path[] = "abc/def/hoge.txt";
    char base[128];
    char ext[128];
    char dir[128];
    char fname[128];

    printf("input path : %s\n", path);                  // input path : abc/def/hoge.txt

    os_path_splitext(path, base, ext);
    printf("os_path_splitext base     : %s\n", base);   // os_path_splitext base     : abc/def/hoge
    printf("os_path_splitext ext      : %s\n", ext);    // os_path_splitext ext      : .txt

    os_path_dirname(path, dir);
    printf("os_path_dirname  dir      : %s\n", dir);    // os_path_dirname  dir      : abc/def

    os_path_basename(path, fname);
    printf("os_path_basename fname    : %s\n", fname);  // os_path_basename fname    : hoge.txt

    os_path_split(path, dir, fname);
    printf("os_path_split    dir      : %s\n", dir);    // os_path_split    dir      : abc/def
    printf("os_path_split    fname    : %s\n", fname);  // os_path_split    fname    : hoge.txt

    os_path_join("abc/def", "hoge.txt", base);
    printf("os_path_join     path     : %s\n", base);   // os_path_join     path     : abc/def/hoge.txt

    os_path_join("abc/def/", "hoge.txt", base);
    printf("os_path_join     path     : %s\n", base);   // os_path_join     path     : abc/def/hoge.txt

    return 0;
}
```
