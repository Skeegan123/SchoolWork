#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

// Function for printing class based on class number
void printn(Class *classes, int i, char *classNum) {
    // Loops through array of structs to find all classes tought by a professor
    for(int k = 0; k < i; k++) {
        if(strcmp(classNum, classes[k].number) == 0) {
            // If statements to format output
            if(strlen(classes[k].title) <= 23 && strlen(classes[k].title) > 11) {
                printf("%s\t\t\t%s\t%s %s", classes[k].title, classes[k].number, classes[k].profLast, classes[k].prof);
            } else if (strlen(classes[k].title) <= 11){
                printf("%s\t\t\t\t%s\t%s %s", classes[k].title, classes[k].number, classes[k].profLast, classes[k].prof);
            } else {
                printf("%s\t\t%s\t%s %s", classes[k].title, classes[k].number, classes[k].profLast, classes[k].prof);
            }

            if((strlen(classes[k].prof) + strlen(classes[k].profLast)) >= 15) {
                printf("\t\t%s\t%s\t%s", classes[k].seats, classes[k].days, classes[k].time);
            } else { 
                printf("\t\t\t%s\t%s\t%s", classes[k].seats, classes[k].days, classes[k].time);
            }
        }
    }
}

// Function for printing all classes on specific days
void printd(Class *classes, int i, char *days) {
    // Loops through array of structs to find all classes tought by a professor
    for(int k = 0; k < i; k++) {
        if(strcmp(days, classes[k].days) == 0) {
            // If statements to format output
            if(strlen(classes[k].title) <= 23 && strlen(classes[k].title) > 11) {
                printf("%s\t\t\t%s\t%s %s", classes[k].title, classes[k].number, classes[k].profLast, classes[k].prof);
            } else if (strlen(classes[k].title) <= 11){
                printf("%s\t\t\t\t%s\t%s %s", classes[k].title, classes[k].number, classes[k].profLast, classes[k].prof);
            } else {
                printf("%s\t\t%s\t%s %s", classes[k].title, classes[k].number, classes[k].profLast, classes[k].prof);
            }

            if((strlen(classes[k].prof) + strlen(classes[k].profLast)) >= 15) {
                printf("\t\t%s\t%s\t%s", classes[k].seats, classes[k].days, classes[k].time);
            } else {
                printf("\t\t\t%s\t%s\t%s", classes[k].seats, classes[k].days, classes[k].time);
            }
        }
    }
}

// Function for printing classes based on last name of Professor
void printp(Class *classes, int i, char *profLast) {
    // Loops through array of structs to find all classes tought by a professor
    for(int k = 0; k < i; k++) {
        if(strcmp(profLast, classes[k].profLast) == 0) {
            // If statements to format output
            if(strlen(classes[k].title) <= 23 && strlen(classes[k].title) > 11) {
                printf("%s\t\t\t%s\t%s %s", classes[k].title, classes[k].number, classes[k].profLast, classes[k].prof);
            } else if (strlen(classes[k].title) <= 11){
                printf("%s\t\t\t\t%s\t%s %s", classes[k].title, classes[k].number, classes[k].profLast, classes[k].prof);
            } else {
                printf("%s\t\t%s\t%s %s", classes[k].title, classes[k].number, classes[k].profLast, classes[k].prof);
            }

            if((strlen(classes[k].prof) + strlen(classes[k].profLast)) >= 15) {
                printf("\t\t%s\t%s\t%s", classes[k].seats, classes[k].days, classes[k].time);
            } else {
                printf("\t\t\t%s\t%s\t%s", classes[k].seats, classes[k].days, classes[k].time);
            }
        }
    }
}
