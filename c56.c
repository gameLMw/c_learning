#include <stdio.h>
int main()
{
    int a, b, c;
    a = 01001 & 111;
    b = 01001 | 111;
    c = 01001 ^ 111;
    printf("%d\n", a);
    printf("%d\n", b);
    printf("%d\n", c);
    return 0;
}