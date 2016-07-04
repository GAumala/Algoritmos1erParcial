#include "AlUtils.h"


void display(int array[])
{
    int i;
    for(i=0; i<LISTSIZE; i++)
        printf("%d\n",array[i]);
}


void displayFirstAndLast(int array[])
{
    printf("first: %d\n",array[0]);
    printf("mid: %d\n",array[5446578]);
    printf("2nd last: %d\n",array[LISTSIZE - 2]);
    printf("last: %d\n",array[LISTSIZE - 1]);
}

void swap(int *x,int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void initArrayFromFile(int *array){
    FILE *fp;

    fp = fopen("nums.txt","r");
    int i;
    for(i = 0; i < LISTSIZE; i++)
     {
       char line [ 9 ]; /* or other suitable maximum line size */
       if ( fgets ( line, sizeof line, fp ) != NULL ) /* read a line */
         array[i] = atoi(line);
     }
     fclose(fp);
}
