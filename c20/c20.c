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
	printf("请输入求水仙花数的位数:\n");
	scanf("%d",&length);//输入求水仙花数的位数
	
	int min,i;
	 
	min=1;
	for(i=length; i>1; i--)
	{
		min*=10;//1 100 1000 10000 100000	
	}
	printf("min=%d\n",min);
	 
	int a,m;
	int sum=0,cut=0;
	//b=length;
	/*for(d=1;b>1;b--)
	{
		d*=10;//1 100 1000 10000 100000
		
	}*/
	for(a=min;a<min*10;a++)
	{
		sum=0;
		int c=a;
		while(c>0)
		{
			m=c%10;
			sum+=pow(m,length);
			c/=10;
	    }
		if(sum==a)
		{
			printf("%d\n",a);
		}
	}
	return 0;
}

