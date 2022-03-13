#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

int main(void) {
    char choice;
    char classNum[20];
    char days[20];
    char profLast[100];
    Class classes[100];
    
    // open file
    FILE* fptr = fopen("/public/pgm1/classes.csv", "r");

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

    fclose(fptr);

    char *result;

    // loops through lines and creates array of structs
    for (int k = 0; k < i; k++) {
        result = strtok(strings[k], ",");
        strcpy(classes[k].number, result);

        result = strtok(NULL, ",");
        strcpy(classes[k].title, result);

        result = strtok(NULL, ",");

        result = strtok(NULL, ",");

        result = strtok(NULL, ",");

        result = strtok(NULL, ",");
        strcpy(classes[k].seats, result);

        result = strtok(NULL, ", ");
        strcpy(classes[k].profLast, result);

        result = strtok(NULL, ",");
        strcpy(classes[k].prof, result);

        result = strtok(NULL, ", ");
        strcpy(classes[k].days, result);

        result = strtok(NULL, ", ");
        strcpy(classes[k].time, result);

    // end loop
    }

    // Display choices and take input to direct to proper function
    do {
        printf("Choices:\n");
        printf("n - print class given number\n");
        printf("d - print all classes for a given day combo\n");
        printf("p - print all classes for a given professor\n");
        printf("q - quit\n");
        scanf("%s", &choice);

        if (choice == 'n'){
            printf("Enter a class number: ");
            scanf("\n");
            fgets(classNum, 20, stdin);
            classNum[strcspn(classNum, "\n")] = 0;
            printn(classes, i, classNum);
        } else if (choice == 'd') {
            printf("Enter class days to print (MWF or TR): ");
            scanf("\n");
            scanf("%s", days);
            printd(classes, i, days);
        } else if (choice == 'p') {
            printf("Enter Professor's Last Name: ");
            scanf("\n");
            scanf("%s", profLast);
            printp(classes, i, profLast);
        }

    } while (choice != 'q');
  
    return 0;
}
