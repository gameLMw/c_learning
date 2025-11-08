#include <stdio.h>
int main()
{
	int a = 0, b = 0;
	printf("物品金额:\n");
	scanf("%d", &a);
	printf("支付金额:\n");
	scanf("%d", &b);
	if (a >= b)
	{
		printf("您的钱不够\n");
	}
	else
	{
		printf("找您%d\n", b - a);
	}

	return 0;
}
