#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	srand(time(0));
	int a = rand() % 100 + 1;
	int b = 0, c = 0;
	printf("请猜一个1到100之间的数:");
	do
	{
		scanf("%d", &b);
		c++;
		if (b > a)
		{
			printf("太大了\n");
		}
		else
		{
			printf("太小了\n");
		}
	} while (b != a);
	printf("你用了%d次\n", c);
	return 0;
}
