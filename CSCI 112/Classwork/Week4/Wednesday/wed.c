#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* fptr = fopen("/public/examples/chap7/wed_2-9_in.txt", "r");
    if (fptr == NULL) {
        printf("Error: Could Not Open File");
        return 1;
    }

    int num;
    int i = 0;
    int j = 0;
    int arr[6][8];
    int sum = 0;

    while (fscanf(fptr, "%d", &num) == 1) {     

        if (num != 0) {
            arr[i][j++] = num;
        }
        else {
            arr[i++][j] = num;
            j = 0;
        }
    }

    fclose(fptr);

    int total_rows = i;
    for (int i = 0; i < total_rows; i++) {
        for (int j = 0; j < 8; j++) {
            if (arr[i][j] !=0) {
                sum += arr[i][j];
            }
            else {
                printf("The Sum Is: %d\n", sum);
                sum = 0;
                break;
            }
        }
        printf("\n");
    }
    printf("The Sum is: %d\n", sum);
    return 0;
}
