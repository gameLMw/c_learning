#include <stdio.h>

// #define A 10

#ifndef A
#undef A
#define A 20
#endif

#if A > 15
#undef A
#define A 15
#else
#define A 5
#endif
// #if的判断条件中不能有赋值语句

int main()
{
    printf("%d\n", A);
#ifdef A
    printf("hello");
#else
    printf("world");
#endif

#ifndef A
    printf("!");
#else
    printf("?");
#endif
    return 0;
}