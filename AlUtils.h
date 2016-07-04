#ifndef UTILS
#define UTILS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LISTSIZE 10000000
void runAlgorithm ( int argc, char *argv[], void (*f)(int[]) );

void display(int array[]);

void displayFirstAndLast(int array[]);

void swap(int *x,int *y);

void initArrayFromFile(int *array);

#endif
