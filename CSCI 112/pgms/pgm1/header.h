
typedef struct {
    char number[100];
    char title[100];
    char seats[20];
    char prof[100];
    char profLast[100];
    char days[20];
    char time[20];
} Class;

void printn(Class*, int, char*);

void printd(Class*, int, char*);

void printp(Class*, int, char*);
