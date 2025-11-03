#include <stdio.h>
#include <math.h>//"pow"的头文件 
int main()
{
	int a,b,c,d=1;
	scanf("%d",&a);
	int cnt=0;
	c=a;//用t代入循环保持a不变 
	while(c>9)
	{
		c/=10;
		//cnt++;
		d*=10;
	}
	printf("a=%d,d=%d,c=%d\n",a,d,c);
	//d=pow(10,cnt-1);//平方函数，10的“cnt-1”平方 
	do{
		b=a/d;
		printf("%d  ",b);
		/*if(d>9){
			printf("  ");
		}*/
		a%=d;
		d/=10;
	}while(d>0);
	printf("\n");
	return 0;
}
