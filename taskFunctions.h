//
// Created by Furgan Gurbanlli on 22.07.2026.
//

#ifndef TO_DO_LIST_TASKFUNCTIONS_H
#define TO_DO_LIST_TASKFUNCTIONS_H

typedef struct Task {
    char* name;
    char* date;
}Tasks;

typedef struct ComTask {
    char* name;
    char* date;
}ComTask;

void ReadFile();
void PrintMenu();
void AddTask(int* count, Tasks** task, int* cap);
void CompleteTaskList(int* count, ComTask* com_task);
void CompleteTask(int* count, ComTask** com_task, int* cap, Tasks* task, int* order);
void TaskList(int* count, Tasks* task);
void SearchTask(Tasks* task);
void EditTask(int* count, Tasks* task);
void DeleteTask(int* count, Tasks* task);

#endif //TO_DO_LIST_TASKFUNCTIONS_H