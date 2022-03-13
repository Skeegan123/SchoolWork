#include <stdio.h>

int main(void) {
    int sum, newNum;

    while (scanf("%d", &newNum) != EOF) {
        sum += newNum;
    }

    printf("The sum is: %d\n", sum);

    return 0;
}
