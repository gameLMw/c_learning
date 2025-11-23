#include <stdio.h>
int main()
{
    int a, b, c;
    scanf("%d", &a);
    while (getchar() != '\n')
        continue;
    scanf("%d", &b);
    while (getchar() != '\n')
        continue;
    scanf("%d", &c);
    printf("a = %d, b = %d, c = %d\n", a, b, c);
    return 0;
}