/*
欧几里得算法
使用取余运算（除法）
求最大公约数
*/
#include <stdio.h>
int main()
{
	int a, b, c;
	scanf("%d %d", &a, &b);
	while (b > 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	printf("%d", a);
	return 0;
}
