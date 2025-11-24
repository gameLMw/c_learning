// 遍历所有数字来查找最大公约数
#include <stdio.h>
int main(void)
{
    int num1, num2, i;
    printf("请输入两个整数：");
    scanf("%d %d", &num1, &num2);
    for (i = (num1 < num2 ? num1 : num2); i >= 1; i--)
    {
        if (num1 % i == 0 && num2 % i == 0)
        {
            break;
        }
    }
    printf("最大公约数是：%d\n", i);
    return 0;
}
