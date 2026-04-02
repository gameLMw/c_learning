#include <stdio.h>
#include <string.h>
int main(void)
{
    char ar[] = {0};
    char name[] = "example";
    sprintf(ar, "%s", name);
    printf("%s\n", ar);
    return 0;
}
