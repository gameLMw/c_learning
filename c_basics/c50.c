#include <stdio.h>
int main()
{
    struct Point
    {
        int x;
        int y;
    };
    struct Point p1 = {10, 20};
    printf("Point p1: (%d, %d)\n", p1.x, p1.y);
    struct Point p2 = {.y = 30,
                       .x = 40,
                       20};
    printf("Point p2: (%d, %d)\n", p2.x, p2.y);
    struct w
    {
        int a;
        char b;
    };
    struct w v1 = {
        .a = 50,
        .b = 'Z',
    };
    printf("Struct w var: (%d, %c)\n", v1.a, v1.b);
    return 0;
}