#include <stdio.h>
#include <string.h>
int main(void)
{
    char ar[30] = {" asda sdas"};
    char arr[30] = {" qwe dgsg"};
    strcat(ar, arr);
    printf("%s\n", ar);
    printf("%s\n", arr);
    strcat(arr, ar);
    printf("%s\n", arr);
    printf("%s\n", ar);
    return 0;
}
// sizeof(dest) 必须 ≥ strlen(dest) + strlen(src) + 1
