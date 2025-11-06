#include <stdio.h>
#include <string.h>

char *s_gets(char *st, int n);

int main() {
    char str[10];  // 固定大小的缓冲区：最多可存储 9 个字符 + '\0'
    s_gets(str, sizeof(str));
    printf("%d\n", str[0]);  // 打印第一个字符的 ASCII 值，如果输入为空则为 0
    return 0;
}

char *s_gets(char *st, int n) {
    char *ret_val;
    char *find;
    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}