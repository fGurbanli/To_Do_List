# 📋 To-Do List (C)

A console-based To-Do List application written in **C**, featuring dynamic memory management, file handling, and a modular project structure.

## ✨ Features

* View all tasks
* Add new tasks
* Edit existing tasks
* Delete tasks
* Search tasks by name
* Mark tasks as completed
* View completed task history
* Automatically saves tasks to files
* Dynamic memory allocation using `malloc()` and `realloc()`

---

## 📂 Project Structure

```text
.
├── main.c
├── taskFunctions.c
├── taskFunctions.h
├── input.c
├── input.h
├── taskList.txt
├── completeList.txt
└── README.md
```

### File Descriptions

* **main.c**

    * Contains the main program loop and menu.

* **taskFunctions.c / taskFunctions.h**

    * Implements all task management operations:

        * Add Task
        * Delete Task
        * Edit Task
        * Search Task
        * Complete Task
        * List Tasks
        * View Completed Tasks

* **input.c / input.h**

    * Contains reusable input validation functions (e.g. `GetIntInput()`).

---

## 💾 Data Storage

The program stores data in two text files.

### `taskList.txt`

Stores active tasks.

Example:

```text
2026-07-25;Finish homework;
2026-07-26;Go to the gym;
```

### `completeList.txt`

Stores completed tasks.

Example:

```text
2026-07-20;Read a book;
```

---

## 🛠 Concepts Used

* C Programming
* Structures (`struct`)
* Dynamic Memory Allocation

    * `malloc()`
    * `calloc()`
    * `realloc()`
    * `free()`
* File I/O

    * `fopen()`
    * `fclose()`
    * `fprintf()`
    * `fscanf()`
    * `fgets()`
* Modular Programming
* Pointers
* String Manipulation (`string.h`)
* Input Validation

---

## ▶️ Menu

```text
==== TO-DO List ====

1 - Task List
2 - Add a New Task
3 - History
4 - Complete a Task
5 - Search Task
6 - Edit Task
7 - Delete Task

0 - Exit
```

---

## 🚀 Future Improvements

* Sort tasks by date
* Priority levels (Low / Medium / High)
* Task categories
* Due date reminders
* Better memory management
* Linked List implementation
* Cross-platform compatibility

---

## 📚 What I Learned

This project helped me practise:

* Dynamic memory management
* Working with structures
* Modular programming
* Reading and writing files
* String processing
* Building a complete CRUD application in C

---

## ⚠️ Notes

This project is intended for educational purposes while learning the C programming language.

Feedback and suggestions are always welcome.
