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

void printOut(char *strings[], int items) {

    FILE* output = fopen("output.txt", "w");

    int k = 0;

    char *temp1[100];
    char *temp2[100];
 
    // loop while (1)
    while (1) {
    //  malloc memory for one line
        temp1[k] = (char *) malloc(100);
        strcpy(temp1[k], strings[k]);
        //printf("1: %s\n", temp1[k]);
        temp2[k] = (char *) malloc(100);
        strcpy(temp2[k], strings[k]);
        //printf("2: %s\n", temp2[k]);
    //  read in the line using fgets
        if (k == items-1) {
            break;
        }
        k++;
    // end loop
    }

    // Create Output File
    fprintf(output, "Hurricanes in Florida with category and date\n");
    fprintf(output, "--------------------------------------------\n");
    
    char *result;
    int i;

    for (i = 0; i < items; i++) {
        result = strtok(temp1[i], ",");
        // print result
        if (strlen(result) >= 8) {
            fprintf(output, "%d:\t\t%s\t", i+1, result);
        } else {
            fprintf(output, "%d:\t\t%s\t\t", i+1, result);
        }
        result = strtok(NULL, ", ");
        result = strtok(NULL, ", ");
        // print result
        fprintf(output, "%s\t\t", result);
        result = strtok(NULL, ", ");
        result = strtok(NULL, ",");
        // print result
        fprintf(output, "%s", result);
        result = strtok(NULL, ",");
        // print result
        fprintf(output, " %s", result);
    }

    // Print Output to Console 
    printf("Hurricanes in Florida with category and date\n");
    printf("--------------------------------------------\n");
    
    char *token;
    int j;

    for (j = 0; j < items; j++) {
        token = strtok(temp2[j], ",");
        // print result
        if (strlen(token) >= 8) {
            printf("%d:\t%s\t", j+1, token);
        } else {
            printf("%d:\t%s\t\t", j+1, token);
        }
        token = strtok(NULL, ", ");
        token = strtok(NULL, ", ");
        // print result
        printf("%s\t", token);
        token = strtok(NULL, ", ");
        token = strtok(NULL, ",");
        // print result
        printf("%s", token);
        token = strtok(NULL, ",");
        // print result
        printf(" %s", token);
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
    printOut(strings, i);

    return 0;
}
