#include <stdio.h>
int main(void)
{
    int a[2] = {0};
    int *b;
    int *p, *i;
    b = a;
    p = &a[0];
    i = &a[1];
    printf("%p, %p, %p\n", (void *)b, (void *)p, (void *)i);
    return 0;
}
