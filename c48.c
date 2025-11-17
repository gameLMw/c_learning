#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int *arr = (int *)calloc(5, sizeof(int)); // 分配5个int大小的内存，全部初始化为0
    if (arr != NULL)
    {
        // 使用数组...
        free(arr); // 记得释放内存
    }
    return 0;
}