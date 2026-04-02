#include <stdio.h>
#line 1000 "c62.c"
// #error "触发编译错误以显示行号和文件名"
#pragma message("编译信息：行号和文件名示例") // #pragma 指令
int main()
{
    printf("%d\n", __LINE__); // 输出当前行号
    printf("%s\n", __FILE__); // 输出当前文件名
    return 0;
}