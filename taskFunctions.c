//
// Created by Furgan Gurbanlli on 22.07.2026.
//
#include "taskFunctions.h"
#include "input.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void PrintMenu() {
    printf("\n");
    printf("====TO-DO List====\n");
    printf("1-Task list\n");
    printf("2-Add a new task\n");
    printf("3-History\n");
    printf("4-Complete a task\n");
    printf("5-Task search\n");
    printf("6-Edit a task\n");
    printf("7-Delete a task\n");
    printf("\n0-Exit\n");
}

void TaskList(int* count, Tasks* task) {

    if (*count == 0) {
        printf("\nThere is no tasks yet!\n");
        return;
    }

    printf("\n=====Task List=====\n\n");

    for (int i = 0; i < *count; i++) {
        printf("%d-) Name: %s, Date: %s\n",i + 1 ,task[i].name, task[i].date);
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

void CompleteTaskList(int* count, ComTask* com_task) {
    FILE* completeList = fopen("completeList.txt", "a");

    if (completeList == NULL) {
        printf("\nFile couldn't be opened!");
        return;
    }

    if (*count == 0) {
        printf("\nThere is no task completed yet!\n");
        return;
    }

    printf("\n=====Completed Task List=====\n\n");

    for (int i = 0; i < *count; i++) {
        printf("%d-) Name: %s, Date: %s\n", i + 1,com_task[i].name,com_task[i].date);
    }

    fclose(completeList);
}

void CompleteTask(int* count, ComTask** com_task, int* cap, Tasks* task, int* order) {
    FILE* completeList = fopen("completeList.txt", "a");

    if (completeList == NULL) {
        printf("\nFile couldn't be opened!");
        return;
    }

    if (*cap <= *count){
        (*cap) *= 2;
        ComTask* temp = realloc(*com_task, (*cap) * sizeof(ComTask));
        if (temp == NULL) {
            printf("\nMemory allocation failed!\n");
            return;
        }
        *com_task = temp;
    }

    TaskList(order, task);

    printf("\nEnter index of task to declare as completed: ");

    int input;

    while (1) {
        input = GetIntInput();
        if (input > 0 && input <= *order) break;
        printf("\nEnter a valid input!");
    }

    fprintf(completeList, "%s;%s;\n", task[input - 1].date, task[input - 1].name);

    (*com_task)[*count].name = malloc(strlen(task[input - 1].name) + 1);
    (*com_task)[*count].date = malloc(strlen(task[input - 1].date) + 1);

    strcpy((*com_task)[*count].name, task[input - 1].name);
    strcpy((*com_task)[*count].date, task[input - 1].date);

    (*count)++;


    FILE* taskList2 = fopen("taskList.txt", "w");

    for (int i = input; i < *order; i++)
    {
        strcpy(task[i - 1].name, task[i].name);
        strcpy(task[i - 1].date, task[i].date);
    }

    free(task[*order - 1].name);
    free(task[*order - 1].date);

    (*order)--;

    for (int i = 0; i < *order; i++)
    {
        fprintf(taskList2,"%s;%s;\n", task[i].date, task[i].name);
    }

    fclose(taskList2);
    fclose(completeList);
}

