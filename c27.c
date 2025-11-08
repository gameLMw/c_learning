#include <stdio.h>
int main(void)
{
	int a[10] = {0};
	printf("%d,%x,%p,%p", &a, &a, a, &a);
	return 0;
}