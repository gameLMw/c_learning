#include <stdio.h>
int main()
{
	int a,b,c,d=0;
	scanf("%d",&a);
	do{
		c=a%10;
		d=d*10+c;
		a/=10;
	}while(a>0);
	/*	while(a>0)
	{
		c=a%10;
		printf("%d",c);//ÄæÊý 
		d=d*10+c;
		a /=10;
	}
	printf("\n");*/
	a=d;
	while(a>0)
	{
		b=a%10;
		printf("%d  ",b);
		a/=10;
	}
	//printf("\n");
	return 0;
}
