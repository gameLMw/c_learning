#include <stdio.h>
int main()
{
	int a = 0, b = 0;
	scanf("%d", &a);
	while (a > 0)
	{
		b = a % 10;
		printf("%d", b); // 逆数
		a /= 10;
	}
	// printf("%d",b);//最高位的数
	return 0;
}
