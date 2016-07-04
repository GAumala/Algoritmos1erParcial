#include "AlUtils.h"

int list[LISTSIZE];

void display(int array[])
{
    int i;
    for(i=0; i<LISTSIZE; i++)
        printf("%d\n",array[i]);
}


void displayFirstAndLast(int array[])
{
    printf("first: %d\n",array[0]);
    printf("mid: %d\n",array[LISTSIZE/2]);
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


void runAlgorithm (  int argc, char *argv[], void (*f)(int[]) ){
   initArrayFromFile(list);
   (*f)(list);
   if(argc == 2){
      if(strcmp(argv[1], "--summary") == 0)
         displayFirstAndLast(list);
      else if(strcmp(argv[1], "--verbose") == 0)
         display(list);
   }

}
