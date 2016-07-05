#include "AlUtils.h"

long choose_pivot(long i,long j )
{
   return((i+j) /2);
}
void _quicksort(long list[],long m,long n)
{
   long key,i,j,k;
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

void quicksort(long list[]){
   _quicksort(list, 0, LISTSIZE - 1);
}

int main( int argc, char *argv[]){
   runAlgorithm(argc, argv, quicksort);
   return 0;
}
