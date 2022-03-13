#include <stdio.h>
#include <stdlib.h>

int main() {

    int* num;
    double* dub;
    char* letter;

    num = (int*)malloc(sizeof(int));

    int numv = 5;

    num = &numv;

    dub = (double*)malloc(sizeof(double));

    double dubv = 2.5;

    dub = &dubv;

    letter = (char*)malloc(sizeof(char));

    char letterv = 'c';

    letter = &letterv;

    printf("num address = %p\n", &num);
    printf("num value = %d\n", numv);

    printf("double address = %p\n", &dub);
    printf("double value = %lf\n", dubv);

    printf("char address = %p\n", &letter);
    printf("char value = %c\n", letterv);

    num = NULL;
    dub = NULL;
    letter = NULL;

    return 0;
}
