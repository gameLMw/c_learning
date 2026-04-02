#include <stdio.h>
int main()
{
    char a[][7] = {"Hello", "World!"};
    char *arr[] = {"hello", "world!"};
    printf("%s,%s\n", a[0], a[1]);
    printf("%s,%s\n", arr[0], arr[1]);
    return 0;
}