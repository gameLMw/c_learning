#include <stdio.h>
#include <string.h>
int main(void)
{
    char str1[50];
    strcpy(str1, "Hello, ");
    strcat(str1, "World!");
    printf("%s\n", str1);
    return 0;
}
