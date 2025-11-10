#include <stdio.h>
#include "c39.1.c"
int main()
{
    int a, b;
    printf("请输入两个整数：");
    if (scanf("%d %d", &a, &b) == 2)
    {
        printf("%d + %d = %d\n", a, b, sum(a, b));
    }
    else
    {
        printf("输入错误！\n");
    }
    return 0;
}