#include <stdio.h>
int main()
{
    int x;
    int one, two, five;

    // printf("请输入金额（元）: ");
    // scanf("%d", &x);
    x = 2;
    int count = 0;

    for (one = 0; one <= x * 10; one++)
    {
        for (two = 0; two <= x * 10 / 2; two++)
        {
            for (five = 0; five <= x * 10 / 5; five++)
            {
                if (one + two * 2 + five * 5 == x * 10)
                {
                    printf("可以用%d个1角%d个2角%d个5角得到%d元\n", one, two, five, x);
                    count++;
                }
            }
        }
    }

    printf("共有%d种组合方式\n", count);

    return 0;
}
