#include <stdio.h>
int func(int *a, int *b);
int func1(int a);
int main(void)
{
    int a = 1, b = 2;
    func1(a);
    func(&a, &b);
    printf("%d %d", a, b);
    return 0;
}
int func(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int func1(int a)
{
    printf("%d\n", a);
}
