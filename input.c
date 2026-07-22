//
// Created by Furgan Gurbanlli on 22.07.2026.
//
#include "input.h"
#include <stdio.h>

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