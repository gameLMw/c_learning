// 扔骰子
#include <stdio.h>
#include "c40.1(shu chu yi ge shu).c"
int main(void)
{
    int i, j;
    printf("请输入骰子的面数：");
    if (scanf("%d", &i) != 1 || i <= 0)
    {
        printf("输入错误！\n");
        return 1;
    }
    printf("请输入骰子的个数：");
    if (scanf("%d", &j) != 1 || j <= 0)
    {
        printf("输入错误！\n");
        return 1;
    }
    while (1)
    {
        printf("按回车键扔骰子，按其他键退出：\n");
        if (getchar() != '\n')
            break;
        printf("你扔出了 %d 个 %d 面的骰子，总点数为：%d\n", j, i, num(i, j));
    }
    return 0;
}