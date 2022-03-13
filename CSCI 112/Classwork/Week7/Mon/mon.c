#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *line;
    line = (char *) malloc(100);

    FILE* fptr = fopen("/public/lab4/hurricanes.csv", "r");

    // use fgets to read first line
    fgets(line, 100, fptr);

    char *result;

    result = strtok(line, ",");
    // print result
    printf("Hurricane name: %s\n", result);
    result = strtok(NULL, ",");
    // print result
    printf("Type: %s\n", result);
    result = strtok(NULL, ",");
    // print result
    printf("Date: %s", result);
    result = strtok(NULL, ",");
    // print result
    printf(" %s", result);

    return 0;
}
