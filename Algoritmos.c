#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LISTSIZE 10000000

int list[LISTSIZE];
int countingList[LISTSIZE];

/** UTILS **/
void display(int array[])
{
    int i;
    for(i=0; i<LISTSIZE; i++)
        printf("%d\n",array[i]);
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

/** QUICKSORT **/
int choose_pivot(int i,int j )
{
   return((i+j) /2);
}
void _quicksort(int list[],int m,int n)
{
   int key,i,j,k;
   if( m < n)
   {
       k = choose_pivot(m,n);
       swap(&list[m],&list[k]);
       key = list[m];
       i = m+1;
       j = n;
       while(i <= j)
       {
           while((i <= n) && (list[i] <= key))
               i++;
           while((j >= m) && (list[j] > key))
               j--;
           if( i < j)
               swap(&list[i],&list[j]);
       }
       /* swap two elements */
       swap(&list[m],&list[j]);

       /* recursively sort the lesser list */
       _quicksort(list,m,j-1);
       _quicksort(list,j+1,n);
   }
}

void quicksort(int list[]){
   _quicksort(list, 0, LISTSIZE - 1);
}

/** COUNTSORT **/

void countsort(int list[]){
    int i;
    for(i = 0; i < LISTSIZE; i++)
      countingList[i] = 0;

    for(i = 0; i < LISTSIZE; i++)
      countingList[list[i] - 1] += 1;

    int j = 0;
    for(i = 0; i < LISTSIZE; i++)
      while(0 < countingList[i]){
         list[j] = i + 1;
         countingList[i] -= 1;
         j++;
      }
}

/** INSERTIONSORT **/

void insertionsort(int list[]){
  int i, j;
  for (i = 1 ; i <= LISTSIZE - 1; i++) {
    j = i;
    if(i % 100) printf("i: %d\n", (int)(i));

    while ( j > 0 && list[j] < list[j-1]) {
      swap(&list[j], &list[j - 1]);
      j--;
    }
  }
}

int main()
{
    initArrayFromFile(list);
    printf("last: %d\n",list[0]);
    printf("first: %d\n",list[LISTSIZE - 1]);
    //printf("The list before sorting is:\n");
    //display(list);

    /* sort the list using quicksort algorithm */
    //quicksort(list);

    //printf("The list after sorting:\n");
    //display(list);

    return 0;
}
