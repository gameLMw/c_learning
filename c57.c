#include <stdio.h>
#define ABC 15
int main()
{

    struct a
    {
        unsigned int x : 1;
        unsigned y : 4;
    };
    struct a w = {0, ABC};
    printf("%s\n", w.y);
    printf("%d %d\n", w.x, w.y);
    return 0;
}
