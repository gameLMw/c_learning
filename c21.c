#include <stdio.h>
void sum(int begin,int end)//函数头 
//begin开始。end结束 
//void,返回类型。sum，函数名。 int begin,int end，参数表。 
{
	int i;
	int sum=0;
	for(i=begin;i<=end;i++)
	{
		sum+=i;
	}
	printf("%d到%d的和是%d\n",begin,end,sum);
}//函数体 
int main(void)

{
	sum(1,2);
	return 0;
} 
