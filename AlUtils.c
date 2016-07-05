#include "AlUtils.h"

long list[LISTSIZE];

void display(long array[])
{
    int i;
    for(i=0; i<LISTSIZE; i++)
        printf("%ld\n",array[i]);
}


void displayFirstAndLast(long array[])
{
    printf("first: %ld\n",array[0]);
    printf("mid: %ld\n",array[LISTSIZE/2]);
    printf("2nd last: %ld\n",array[LISTSIZE - 2]);
    printf("last: %ld\n",array[LISTSIZE - 1]);
}

void swap(long *x,long *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void initArrayFromFile(long *array){
    FILE *fp;

    fp = fopen("nums.txt","r");
    int i;
    for(i = 0; i < LISTSIZE; i++)
     {
       char line [ 9 ]; /* or other suitable maximum line size */
       if ( fgets ( line, sizeof line, fp ) != NULL ) /* read a line */
         array[i] = atol(line);
     }
     fclose(fp);
}


void runAlgorithm (  int argc, char *argv[], void (*f)(long[]) ){
   initArrayFromFile(list);
   (*f)(list);
   if(argc == 2){
      if(strcmp(argv[1], "--summary") == 0)
         displayFirstAndLast(list);
      else if(strcmp(argv[1], "--verbose") == 0)
         display(list);
   }

}
