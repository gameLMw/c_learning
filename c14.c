#include <stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int a=1,b=1;
	/*for(b=1;b<=n;b++)
	{
		a *=b;
	}*/
	for(b=n;b>1;b--)
	{
		a*=b;
	}
	printf("%d!=%d\n",n,a);
	return 0;
} 
