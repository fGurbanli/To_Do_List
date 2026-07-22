#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Task {
    char* name;
    char* date;
}Tasks;

int GetIntInput();

void PrintMenu();
void AddTask(int* count, Tasks** task, int* cap);
void CompleteTask();
void TaskList(int* count, Tasks* task);
void SearchTask();
void EditTask();
void DeleteTask();

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

void TaskList(int* count, Tasks* task) {
    printf("\n=====Task List=====\n\n");

    if (*count == 0) {
        printf("\nThere is no tasks yet!\n");
        return;
    }

    for (int i = 0; i < *count; i++) {
        printf("Date: %s, Name: %s\n", task[i].date, task[i].name);
    }
}

void AddTask(int* count, Tasks** task, int* cap) {
    FILE* taskList = fopen("taskList.txt", "a");

    if (taskList == NULL) {
        printf("\nFile couldn't be opened!");
        return;
    }

    if (*cap <= *count){
        (*cap) *= 2;
        Tasks* temp = realloc(*task, (*cap) * sizeof(Tasks));
        if (temp == NULL) {
            printf("\nMemory allocation failed!\n");
            return;
        }
        *task = temp;
    }



    char temp1[100];
    char temp2[100];

    while (getchar() != '\n');
    printf("Enter a date of task: ");
    fgets(temp1, sizeof(temp1), stdin);
    temp1[strcspn(temp1, "\n")] = '\0';

    printf("Enter a name of task: ");
    fgets(temp2, sizeof(temp2), stdin);
    temp2[strcspn(temp2, "\n")] = '\0';


    (*task)[*count].date = malloc(strlen(temp1) + 1);
    if ((*task)[*count].date == NULL)
    {
        printf("\nMemory allocation failed!");
        return;

    }

    (*task)[*count].name = malloc(strlen(temp2) + 1);
    if ((*task)[*count].name == NULL)
    {
        free((*task)[*count].date);
        printf("\nMemory allocation failed!");
        return;

    }




    strcpy((*task)[*count].date, temp1);
    strcpy((*task)[*count].name, temp2);

    fprintf(taskList, "%s;%s; \n", temp1, temp2);

    printf("\nNew task successfully added!");

    (*count)++;

    fclose(taskList);
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