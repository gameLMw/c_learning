#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
    int i;
    srand((unsigned int)time(0));
    printf("%d\n", rand());
    return 0;
}