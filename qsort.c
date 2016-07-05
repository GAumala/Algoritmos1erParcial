#include "AlUtils.h"

long countingList[LISTSIZE];

int compareLongs(const void *a, const void *b){
  long *l1 = (long *) a;
  long *l2 = (long *) b;
  return *l1 - *l2;
}
void qsort_gcc(long list[]){
   qsort(list, LISTSIZE, sizeof(long), compareLongs);
}

int main( int argc, char *argv[]){
   runAlgorithm(argc, argv, qsort_gcc);
   return 0;
}
