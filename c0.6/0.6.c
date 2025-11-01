//选数
//程序会给出一个从1开始的数。请选择他，你觉得对输入“y”，错输入“n”。 
#include <stdio.h>
int main(void)
{
	int figure=1;
	char ch;
	printf("这个数字是%d吗\n",figure);
	while((ch=getchar())!='y')
	{
		if(ch!='n')
		{
			printf("请输入“y”或“n”\n");
		}else{
			printf("这个数是%d吗\n",++figure);
	    }
	    while(getchar() !='\n')//跳过换行符 
		{
			continue;
		}
	}
	printf("好的，那这个数就是%d",figure);
	return 0;
} 
