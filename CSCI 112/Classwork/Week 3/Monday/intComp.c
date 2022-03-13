#include <stdio.h>

int main(){

    int int1;
    int int2;

    printf("Enter 2 integers.\n");
    printf("Integer 1: ");
    scanf("%d", &int1);
    printf("Integer 2: ");
    scanf("%d", &int2);

    if (int1 == int2) {
        printf("%d is equal to %d\n", int1, int2);
    } else if (int1 < int2) {
        printf("%d is less than %d\n", int1, int2);
    } else if (int1 > int2) {
        printf("%d is greater than %d\n", int1, int2);
    }

    return 0;
}
