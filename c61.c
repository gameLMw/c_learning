#include <stdio.h>
int main()
{
    printf("%s.\n", __TIME__);                                    // 时间
    printf("%s.\n", __DATE__);                                    // 日期
    printf("%s.\n", __FILE__);                                    // 文件名
    printf("%d.\n", __LINE__);                                    // 行号
    printf("%ld.\n", __STDC_VERSION__);                           // C标准版本
    printf("%d.\n", __STDC__);                                    // 是否符合标准C
    printf("%s.\n", __STDC_HOSTED__ ? "宿主环境" : "非宿主环境"); // 宿主环境
    printf("%s.\n", __BASE_FILE__);                               // 主文件名
    printf("%s.\n", __INCLUDE_LEVEL__ ? "包含文件" : "主文件");   // 包含级别
    printf("%s.\n", __TIMESTAMP__);                               // 最后修改时间
    printf("%s.\n", __func__);                                    // 函数名
    printf("%s.\n", __PRETTY_FUNCTION__);                         // 函数名（更详细）
    printf("%s.\n", __COUNTER__ ? "已使用" : "未使用");           // 计数器
    return 0;
}