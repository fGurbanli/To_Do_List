#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "taskFunctions.h"

int main(void) {
    FILE* taskList = fopen("taskList.txt", "r");

    if (taskList == NULL) {
        printf("File couldn't be opened!\n");
        return 1;
    }

    int maxSize = 10;
    int order = 0;
    char temp[100];

    rewind(taskList);

    while (fgets(temp, sizeof(temp), taskList) != NULL)
    {
        order++;
    }

    rewind(taskList);

    if (order > maxSize) maxSize =2 * order;

    Tasks* task = calloc(maxSize, sizeof(Tasks));

    if (task == NULL) {
        printf("\nMemory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < order; i++) {
        char temp1[100];
        char temp2[100];
        if (fscanf(taskList," %99[^;];%99[^;];", temp1, temp2) != 2) {
            free(task);
            printf("\nCouldn't read file!\n");
            fclose(taskList);
            return 1;
        }

        task[i].date = malloc(strlen(temp1) + 1);
        if (task[i].date == NULL) {
            printf("\nMemory allocation failed!\n");
            free(task);
            fclose(taskList);
            return 1;
        }

        task[i].name = malloc(strlen(temp2) + 1);
        if (task[i].name == NULL) {
            printf("\nMemory allocation failed!\n");
            free(task[i].date);
            free(task);
            fclose(taskList);
            return 1;
        }

        strcpy(task[i].date, temp1);
        strcpy(task[i].name, temp2);
    }

    while (1) {
        PrintMenu();
        int option = GetIntInput();

        switch (option) {
            case 1:
                printf("Opening task list...\n");
                TaskList(&order, task);
                break;
            case 2:
                printf("Opening...\n");
                AddTask(&order, &task, &maxSize);
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
                for (int i = 0; i < order; i++) {
                    free(task[i].name);
                    free(task[i].date);
                }
                free(task);
                printf("Closing program...\n");
                fclose(taskList);
                exit(0);
            default:
                printf("Enter a valid value!\n");
        }
    }
}

