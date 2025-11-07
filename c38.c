#include <stdio.h>
int main(int argc, char *argv[]) {
    int count;
    printf("%d\n", argc);
for (count = 1; count < argc; count++) {
        printf("%s\n", argv[count]);
}
printf("\n");
    return 0;
}