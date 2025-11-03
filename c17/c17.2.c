#include <stdio.h>
int main()
{
	int n,i,a=1;
	double sum=0.0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		sum+=a*1.0/i;
		a=-a;
	}
	printf("%f",sum);
    return 0;
}
