#include <stdio.h>
int main()
{
	int x;
	scanf("%d", &x);
	int i, b = 1;
	for (i = 2; i < x; i++)
	{
		if (x % i == 0)
		{
			b = 0;
			break; // 跳出循环。continue;（跳过循环）。
		}
	}
	if (b = 1)
	{
		printf("是素数");
	}
	else
	{
		printf("不是素数");
	}
	printf("%d", i);
	return 0;
}
