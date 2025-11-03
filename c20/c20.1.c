#include <stdio.h>
#include <math.h>
/*
输入位数，输出对应位数的水仙花数
水仙花数的定义是每一位的位数次方的和是这个数本身
比如 
153=1^3+5^3+3^3
1634=1^4+6^4+3^4+4^4
*/ 
int main()
{
	int length;
	printf("请输入求水仙花数的位数:");
	scanf_s("%d", &length);

	int min=1,i;
	for (i = length; i > 1; i--)
	{
		min *= 10;//1 100 1000 10000 100000	
	}

	int count=0,k;
	for (k = min; k < min * 10; k++)
	{
		int sum = 0,j;
		for (j = k; j > 0; j /= 10)
		{
			sum += pow(j % 10, length);
		}
		if (sum == k)
		{

			printf("%d\n", k);
			count++;
		}
	}
	printf("计算完毕,有%d个",count);
	return 0;
}
