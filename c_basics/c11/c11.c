#include <stdio.h>

int main()
{
	int a = 59, b;
	scanf("%d", &b);
	while (b > 59)
	{
		printf("太大了");
		scanf("%d", &b);

		while (b < 59)
		{
			printf("太小了");
			scanf("%d", &b);
		}
	}
	printf("答对了");
	return 0;
}
/*输出一个随机整数
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	srand(time(0));
	int a=rand();
	printf("%d",a);
	return 0;
}*/
