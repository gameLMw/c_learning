//地址
 //目前，同函数 同字母 不同数 同地址，不同函数 都不同。(10.29 23:22)
#include <stdio.h> 
void d(void);
int main()
{
	int a=2,b=3,c=2;
	printf("1 a=%d,%p\n",a,&a);//a=2
	printf("2 b=%d,%p\n",b,&b);//b=3
	printf("3 c=%d,%p\n",c,&c);//c=2
	a=3;
	printf("4 a=%d,%p\n",a,&a);//a=3
	a=b;
	printf("5 a=%d,%p\n",a,&a);//a=b=2
    printf("\n");
    
	int *p;
	p=&b;
	printf("10 a=%d,%p\n",a,p);//a=&b=2	
	printf("\n");
	
	d();
	printf("\n");
			
	printf("数1=3=5=6，2=4=7=8。字母1=4=5=6=7,2=8=9.函数1=2=3=4=5，6=7=8=9\n");
	return 0;
 } 
 void d(void)
 {
 	int a=2; 
	printf("6 a=%d,%p\n",a,&a);//a=2
	a=3;
	printf("7 a=%d,%p\n",a,&a);//a=3
	int b=3;
	printf("8 b=%d,%p\n",b,&b);//b=3
	b=4;
	printf("9 b=%d,%p\n",b,&b);//b=4
 }
