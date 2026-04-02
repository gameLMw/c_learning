#include <stdio.h>
int main()
{
    typedef struct a
    {
        int x;
        int y;
    } w;
    w var = {10, 20};
    printf("x: %d, y: %d\n", var.x, var.y);
    return 0;
}