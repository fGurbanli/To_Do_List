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
void DeleteTask();

int main(void) {
    FILE* taskList = fopen("taskList.txt", "r");
    int order = 0;
    char temp[100];

    rewind(taskList);

    while (fgets(temp, sizeof(temp), taskList) != NULL)
    {
        order++;
    }

    while (1) {
        PrintMenu();
        int option = GetIntInput();

        switch (option) {
            case 1:
                printf("Opening task list...\n");
                break;
            case 2:
                printf("Opening...\n");
                break;
            case 3:
                printf("Opening...\n");
                break;
            case 4:
                printf("Opening...\n");
                break;
            case 5:
                printf("Opening...\n");
                break;
            case 6:
                printf("Opening...\n");
                break;
            case 0:
                printf("Closing program...\n");
                fclose(taskList);
                exit(0);
            default:
                printf("Enter a valid value!\n");
        }
    }
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
        if (scanf("%d", &input) == 1 && input >= 0) {
            break;
        }
        while (getchar() != '\n');
        printf("Enter a valid value!\n");
    }
    return input;
}