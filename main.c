#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Task {
    char* name;
    char* date;
}tasks;

int GetIntInput();

void PrintMenu();
void AddTask();
void CompleteTask();
void TaskList();
void SearchTask();
void EditTask();

int main(void) {



    return 0;
}

int GetIntInput() {
    int input;
    while (1) {
        if (scanf("%d", &input) == 1 && input > 0) {
            break;
        }
        while (getchar() != '\n');
        printf("Enter a valid value!\n");
    }
    return input;
}