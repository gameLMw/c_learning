#include <stdio.h>
int main()
{
    for (int i = 0; i < 2; i++)
    {
        int j = 2, k = 3;
        for (; j >= (i + 1); j--)
        {
            printf(" ");
        }
        for (int l = 0; l < 2 * (i + 1); l++)
        {
            printf("*");
        }
        for (; k > 2 * i; k--)
        {
            printf(" ");
        }
        for (int l = 0; l < 2 * (i + 1); l++)
        {
            printf("*");
        }
        printf("\n");
    }
    for (int i = 0; i < 6; i++)
    {
        for (int k = 0; k < i; k++)
        {
            printf(" ");
        }

        for (int j = 0; j < 11 - i * 2; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}