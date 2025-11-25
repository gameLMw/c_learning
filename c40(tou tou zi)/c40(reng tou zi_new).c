// 扔骰子
#include <stdio.h>
#include "c40.1(shu chu yi ge shu).c"
#include "c40.2(scanf yan zheng).c"
int main(void)
{
    int i, j;
    while (1)
    {
        printf("输入非正整数时停止\n请输入骰子的面数：");
        i = scanf_1();
        if (i == 1)
        {
            return 1;
        }
        printf("请输入骰子的个数：");
        j = scanf_1();
        if (j == 1)
        {
            return 1;
        }
        printf("你扔出了 %d 个 %d 面的骰子，总点数为：%d\n\n", j, i, num(i, j));
    }
    return 0;
}