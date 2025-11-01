//选数
//程序会给出一个从1开始的数。请选择他，你觉得对输入“y”，错输入“n”。 
#include <stdio.h>
int main(void)
{
	int figure=1;
	char ch;
	int extra_chars=0;
	printf("这个数字是%d吗\n",figure);
	while((ch=getchar())!='y')
	{
		char next_char=getchar();
		if(next_char!='\n'){
			extra_chars=1;
			while(getchar()!='\n'){
				continue;
			}
		}else{
			extra_chars=0;
		}
		if(extra_chars){
			printf("输入了多个字符，请重新输入\n");
	    }else if(ch!='\n'){
			printf("请输入“y”或“n”\n");
	    }else{
			printf("这个数是%d吗\n",++figure);
	    }
	}
	printf("好的，那这个数就是%d",figure);
	return 0;
} 
