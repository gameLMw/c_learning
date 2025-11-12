#include <stdio.h>
int main(void)
{
    char temp = 'A';
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            printf("%c", temp);
            temp++;
        }
        printf("\n");
    }
    return 0;
}