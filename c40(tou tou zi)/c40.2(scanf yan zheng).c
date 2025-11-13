// 输入并验证输入是否正确
#include <stdio.h>
int scanf_1(void)
{
    int i;
    if (scanf("%d", &i) != 1 || i <= 0)
    {
        printf("输入错误！\n");
        return 1;
    }
    return i;
}