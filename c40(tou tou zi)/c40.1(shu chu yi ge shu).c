// 输出一个有j个有i面的骰子的总点数
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int num(int i, int j)
{
    srand((unsigned int)time(NULL));
    i = rand() % i + 1;
    srand((unsigned int)time(NULL) + i);
    j = rand() % j + 1;
    return i + j;
}