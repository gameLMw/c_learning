#include <stdio.h>
int main()
{
    int a = 5;
    char buf[20];
    scanf("%d", &a);
    printf("%d\n", a);
    while (getchar() != '\n')
        continue;
    scanf("%s", buf);
    printf("%s\n", buf);
    return 0;
}