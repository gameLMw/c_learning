#include <stdio.h>
#include <stdlib.h>
int main(void){
    srand(2);
    printf("Random number: %d\n", rand()%100);
}