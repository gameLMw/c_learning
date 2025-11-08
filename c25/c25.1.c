// 不同文件地址
#include <stdio.h>
int main()
{
	int a = 2, b = 3, c = 2;
	printf("%d,%p\n", a, &a);
	printf("%d,%p\n", b, &b);
	printf("%d,%p\n", c, &c);
	a = 3;
	printf("%d,%p\n", a, &a);
	a = b;
	printf("%d,%p\n", a, &a);
	return 0;
}
