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

    PrintMenu();


    return 0;
}

void PrintMenu() {
    printf("\n");
    printf("====TO-DO List====\n");
    printf("1-Task list\n");
    printf("2-Add a new task\n");
    printf("3-Complete a task\n");
    printf("4-Task search\n");
    printf("5-Edit a task\n");
    printf("6-Delete a task\n");
    printf("\n0-Exit\n");
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