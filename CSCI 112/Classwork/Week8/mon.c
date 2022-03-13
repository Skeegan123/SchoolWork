#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monh.h"

int main(void) {
    char *line;
    char choice;
    Class class1;
    line = (char *) malloc(100);

    FILE* fptr = fopen("/public/pgm1/classes.csv", "r");

    if (fptr == NULL) {
        perror("Error opening file");
        return -1;
    }

    // use fgets to read first line
    fgets(line, 100, fptr);

    fclose(fptr);

    char *result;

    result = strtok(line, ",");
    strcpy(class1.number, result);
    result = strtok(NULL, ",");
    strcpy(class1.title, result);

    do {
        printf("Enter a choice (n for number, t for title, q to quit):");
        scanf("%s", &choice);

        if (choice == 'n'){
            printf("%s\n", class1.number);
        } else if (choice == 't') {
            printf("%s\n", class1.title);
        }

    } while (choice != 'q');
    
    return 0;
}
