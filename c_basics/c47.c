#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    double *ptd;
    int max;
    int number;
    int i = 0;
    if (scanf("%d", &max) != 1)
    {
        exit(EXIT_FAILURE);
    }
    ptd = (double *)malloc(max * sizeof(double));
    if (ptd == NULL)
    {
        exit(EXIT_FAILURE);
    }
    // ptd现在指向了可以存放max个double类型数据的内存空间
    while (i < max && scanf("%lf", &ptd[i]) == 1)
    {
        i++;
    }
    number = i;
    printf("\n%d\n\n", number);

    for (i = 0; i < number; i++)
    {
        printf("%7.2f\n", ptd[i]);
    }
    free(ptd);
    ptd = NULL;
    return 0;
}