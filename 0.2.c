#include <stdio.h>
int main(void)
{
	int a = 1, b = 1;
	int n, m;
	n = a++;
	m = ++b;
	printf("a=%d\nb=%d\na++=%d\n++a=%d\n", a, b, n, m);
	return 0;
}