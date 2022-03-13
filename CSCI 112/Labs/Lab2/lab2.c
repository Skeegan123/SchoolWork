#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isDivis(int x, int y) {
    if (x % 9 == 0) {
        printf("Since %d is divisible by 9, %d is divisible by 9\n", x, y);
    } else {
        printf("Since %d is not divisible by 9, %d is not divisible by 9\n", x, y);
    }
    return 0;

    // Checks if the sum of the digits id divisible by 9 and prints 
    // output accordingly
}

int main() {
    
    // var declaration
    int num, i, j;
    int digits;
    int sum = 0;
    int og;

    // Gets number
    printf("Enter a number to check (0 to end): ");
    scanf("%d", &num);

    og = num;

    // Exits if input is 0
    if (num == 0) {
        return 0;
    }

    // Calculates how many digits in input
    digits = log10(num)+1;

    // Creates array of digits
    int numArray[digits];

    for (i = 0; i < digits; i++) {
        numArray[i] = num % 10;
        num = num / 10;
        sum += numArray[i];
    }

    // Prints equation of digits being added
    for (j = digits - 1; j >= 0; j--) {
        printf("%d ", numArray[j]);
        if (j == 0) {
            printf("= ");
        } else {
            printf("+ ");
        }
    }

    printf("%d\n", sum);

    isDivis(sum, og);

    main();

    return 0;
}
