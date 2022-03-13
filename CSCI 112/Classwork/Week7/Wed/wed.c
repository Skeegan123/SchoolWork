#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Implements the selection sort
// algorithm
void SelectionSort(char *strs[], int size) {
    int i, j;
    char temp[100];

    for (i = 0; i < size-1; i++) {
        for (j = i+1 ; j < size; j++) {
            if (strcmp(strs[i], strs[j]) > 0) {
                strcpy(temp, strs[i]);
                strcpy(strs[i], strs[j]);
                strcpy(strs[j], temp);
            }
        }
    }
}

int main(void) {
    // open the file
    FILE* fptr = fopen("/public/lab4/hurricanes.csv", "r");
    // check that the file ptr is not null
    if (fptr == NULL) {
        perror("Error opening file");
        return -1;
    }
    
    // create your array of lines
    int n = 100;
    //char *str;
    char *strings[n];
    //str = (char *) malloc(100);
    int i = 0;
    
    // loop while (1)
    while (1) {
    //  malloc memory for one line
        strings[i] = (char *) malloc(100);
    //  read in the line using fgets
        if (fgets(strings[i], 100, fptr) == NULL) {
            break;
        }
        i++;
    // end loop
    }

    // SelectionSort with your array of lines
    SelectionSort(strings, i);
    // loop on number of lines
    for (int k = 0; k < i; k++) {
    //  print each line in sorted order
        printf("%d: %s\n", k+1, strings[k]);
    // end loop
    }

    return 0;
}
