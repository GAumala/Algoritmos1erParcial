#ifndef UTILS
#define UTILS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LISTSIZE 10000000L
void runAlgorithm ( int argc, char *argv[], void (*f)(long[]) );

void display(long array[]);

void displayFirstAndLast(long array[]);

void swap(long *x,long *y);

void initArrayFromFile(long *array);

#endif
