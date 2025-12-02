#include <stdio.h>
int main()
{
    char str;
    double num;
    int num2;
    printf("%zu\n", _Alignof(str));
    printf("%zu\n", _Alignof(num));
    printf("%zu\n", _Alignof(num2));
    printf("%d\n", (void *)&str);
    printf("%d\n", (void *)&num);
    printf("%d\n", (void *)&num2);
    return 0;
}