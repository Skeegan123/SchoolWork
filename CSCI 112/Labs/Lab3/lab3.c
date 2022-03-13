#include <stdio.h>
#include <stdlib.h>

void answers(int numAnswers, char answerKey[]) {
    int k, l;

    printf("Question\t");

    for(k = 0; k < numAnswers; k++){
        printf("%d ", k+1);
    }

    printf("\n");

    printf("Answer\t\t");

    for(l = 0; l < numAnswers; l++){
        printf("%c ", answerKey[l]);
    }

    printf("\n");

    printf("ID\tGrade(%%)\n");

    // Used for loops to print out number of questions and
    // answers from array
}

double calcGrade(double score, int numAnswers) {
    double grade;
    grade = (score / (double) numAnswers) * 100;

    return grade;

    // Calculates Grade Percentage
}

int main() {
    FILE * inp;
    int numAnswers;
    char answerKey[10];
    int studentID[5];
    char studentAnswer[10];
    int i, j, k, m;
    double score = 0;
    double grade = 0;
    int missed[10] = {0};

// FILE OPEN SECTION--------------------------------------------

    inp = fopen("/public/lab3/exam.txt", "r");

    fscanf(inp, "%d %s", &numAnswers, answerKey);

    answers(numAnswers, answerKey);

// GRADE SECTION------------------------------------------------

    for(i = 0; i < 5; i++){
        fscanf(inp, "%d %s", &studentID[i], studentAnswer);
        for (j = 0; j < numAnswers; j++) {
            if (studentAnswer[j] == answerKey[j]) {
                score++;
            } else {
                missed[j]++;
            }
        }
        grade = calcGrade(score, numAnswers);

        printf("%d\t%.2lf\n", studentID[i], grade);

        score = 0;
    } 

    // Used a nested for loop to loop through students and their
    // answers to then print out to the console
    
// MISSED BY SECTION--------------------------------------------

    printf("Question\t");

    for(k = 0; k < numAnswers; k++){
        printf("%d ", k+1);
    }

    printf("\n");

    printf("Missed By\t");

    for(m = 0; m < numAnswers; m++){
        printf("%d ", missed[m]);
    }

    printf("\n");

    // Just like before used for loops to print number of
    // questions and how many students missed each one

// -------------------------------------------------------------

    return 0;
}
