#include <stdio.h>
#include <string.h>
char *s_gets(char *st, int n);
int main()
{
    const char *ar[6] = {"asd", "qwe", "zxc", "wer", "tyh", "wda"};
    int count = 0;
    int i;
    for (i = 0; i < 6; i++)
    {
        if (strncmp(ar[i], "qwe", 3) == 0)
        {
            printf("%s\n", ar[i]);
            count++;
        }
    }
    printf("%d\n", count);
    return 0;
}
char *s_gets(char *st, int n)
{
    char *ret_val;
    int i = 0;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        while (st[i] != '\n' && st[i] != '\0')
            i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}
