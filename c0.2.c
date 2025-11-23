#include <stdio.h>
int main(void)
{
	int a = 1, b = 1;
	printf("初始值：a=%d, b=%d\n", a, b);
	int n, m;
	n = a++;
	m = ++b;
	printf("a=%d\nb=%d\na++=%d\n++b=%d\n", a, b, n, m);
	return 0;
}
