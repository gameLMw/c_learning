/*相减



91 49
49 42
42 7
7 35
7 28
7 21
7 14
7 7
*/
#include <stdio.h>
int main(void)
{
    int num1, num2;
    printf("请输入两个整数：");
    scanf("%d %d", &num1, &num2);
    while (num1 != num2)
    {
        if (num1 > num2)
            num1 = num1 - num2;
        else
            num2 = num2 - num1;
    }
    printf("最大公约数是：%d\n", num1);
    return 0;
}
