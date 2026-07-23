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

void CompleteTask(int* count, ComTask** com_task, int* cap) {
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
            fclose(completeList);
            return;
        }
        *com_task = temp;
    }

    printf("\n=====Completed Task List=====\n\n");

    if (*count == 0) {
        printf("\nThere is no task completed yet!\n");
        return;
    }

    for (int i = 0; i < *count; i++) {
        printf("Date: %s, Name: %s\n", (*com_task)[i].date,(*com_task)[i].name);
    }

    fclose(completeList);
}