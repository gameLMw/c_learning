#include <stdio.h>
int main(void)
{
    char temp;
    int num;
    printf("请输入一个大写字母：");
    scanf("%c", &temp);
    num = temp;
    for (int i = 0; i < num - 'A' + 1; i++)
    {
        int j;
        for (j = i; j < num - 65; j++)
        {
            printf(" ");
        }
        for (j = 0; j <= i; j++)
        {
            printf("%c", 'A' + j);
        }
        for (j = i - 1; j >= 0; j--)
        {
            printf("%c", 'A' + j);
        }
        printf("\n");
    }
    return 0;
}