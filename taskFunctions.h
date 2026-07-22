//
// Created by Furgan Gurbanlli on 22.07.2026.
//

#ifndef TO_DO_LIST_TASKFUNCTIONS_H
#define TO_DO_LIST_TASKFUNCTIONS_H

typedef struct Task {
    char* name;
    char* date;
}Tasks;

void ReadFile();
void PrintMenu();
void AddTask(int* count, Tasks** task, int* cap);
void CompleteTask();
void TaskList(int* count, Tasks* task);
void SearchTask();
void EditTask();
void DeleteTask();

#endif //TO_DO_LIST_TASKFUNCTIONS_H