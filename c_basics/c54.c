#include <stdio.h>
int main()
{
    struct a
    {
        int x;
        int y;
    };
    struct a p[2] = {{1, 2}, {3, 4}};
    printf("%p,%p\n", &p[0], &p[1]);
    struct a *ptr = p;
    printf("%p,%p\n", ptr, ptr + 1);
    return 0;
}
