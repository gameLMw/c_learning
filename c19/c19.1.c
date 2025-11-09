// 遍历所有数字来查找最大公约数
#include <stdio.h>
int main(void)
{
    int num1, num2, num3;
    printf("请输入两个整数：");
    scanf("%d %d", &num1, &num2);
    for (int i = 1; i <= (num1 < num2 ? num1 : num2); i++)
    {
        if (num1 % i == 0 && num2 % i == 0)
        {
            num3 = i;
        }
    }
    printf("最大公约数是：%d\n", num3);
    return 0;
}