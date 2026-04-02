#include <stdio.h>
int main()
{
	int n, i;
	double sum = 0.0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		if (i % 2 == 0) // iÎªÅ¼Êý
		{
			sum += -1.0 / i;
		}
		else
		{
			sum += 1.0 / i;
		}
	}
	printf("%f", sum);
	return 0;
}
