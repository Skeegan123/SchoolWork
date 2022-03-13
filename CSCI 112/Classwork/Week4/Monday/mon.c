#include <stdio.h>
#include <stdlib.h>


int main() {
    
    int num, i, j;
    int numArray[5];

    printf("Enter a 5 digit number: ");
    scanf("%d", &num);

    for (i = 0; i < 5; i++) {
        numArray[i] = num % 10;
        num = num / 10;
    }

    for (j = 4; j >= 0; j--) {
        printf("%d ", numArray[j]);
    }

    printf("\n");

    return 0;
}
