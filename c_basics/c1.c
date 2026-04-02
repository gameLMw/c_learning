#include <stdio.h>

int main()
{
    int a = 5;
    int b = 6;
    int c;
    c = a;
    a = b;
    b = c;
    printf("%d \n%d\n", a, b);

    return 0;
}
