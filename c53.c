#include <stdio.h>
int main()
{
    struct r
    {
        int a;
        double b;
    };
    struct r p[3];
    printf("%zu\n", sizeof(struct r));
    printf("%zu\n", sizeof(p));
    int x;
    printf("%zu\n", sizeof(x));
    double y;
    printf("%zu\n", sizeof(y));
    return 0;
}