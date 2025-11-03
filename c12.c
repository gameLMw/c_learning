#include <stdio.h>
int main()
{
	int a=0,b=0,c=0;
	printf("计算平均数\n请输入:");
	scanf("%d",&a);
	while(a!=-1)
	{
		b +=a;
		c++;
		scanf("%d",&a);
	}
	printf("%f\n",1.0*b/c);
	return 0;
}
