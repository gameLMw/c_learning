#include <stdio.h>
int main(void)
{
    int nums[4] = {};
    printf("nums[]={");
    for (int i = 0; i < 4; i++)
    {
        scanf("%d", &nums[i]);
    }
    printf("}\n");
    int target;
    printf("target=");
    scanf("%d", &target);
    for (int i = 0; i < 4; i++)
    {
        for (int j = i + 1; j < 4; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                printf("[%d,%d]\n", i, j);
                return 0;
            }
        }
    }
    return 0;
}
