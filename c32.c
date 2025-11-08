#include <stdio.h>
#include <string.h>
int main(void)
{
    char ar[9] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', '\0'};
    printf("%zu", strlen(ar));
    return 0;
}
