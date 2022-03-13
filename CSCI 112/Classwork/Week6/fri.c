#include <stdio.h>
#include <stdlib.h>

int main(){
    char letters[24];


    printf("Enter a word: ");
    scanf("%s", letters);

    printf("%s starts with the letter %c\n", letters, letters[0]);

    return 0;
}
