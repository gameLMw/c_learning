#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p = (int *)malloc(sizeof(int)); // 分配一个整数大小的内存
    if (p == NULL)
    { // 检查分配是否成功
        printf("内存分配失败\n");
        return -1;
    }

    *p = 10; // 使用内存
    printf("值为: %d\n", *p);

    free(p);  // 释放内存
    p = NULL; // 避免悬空指针

    return 0;
}