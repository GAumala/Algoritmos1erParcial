
#include "AlUtils.h"

long greatestPowerOfTwoLessThan(long n){
  long k = 1;
  while( k < n){
     k = k << 1;
  }
  return k >> 1;
}
void bitonicmerge(long list[], long lo, long n, int dir){
  if(n > 1){
    long m = greatestPowerOfTwoLessThan(n);
    for(long i = lo; i < lo + n - m; i++){
      long j = i + m;
      if(dir == (list[i] > list[j]))
        swap(&list[i], &list[j]);
    }

    bitonicmerge(list, lo, m, dir);
    bitonicmerge(list, lo + m, n - m, dir);
  }
}

void _bitonicsort(long list[], long lo, long n, int dir){
   if(n > 1){
      long m = n/2;
      _bitonicsort(list, lo, m, !dir);
      _bitonicsort(list, lo+m, n-m, dir);
      bitonicmerge(list, lo, n, dir);
   }
}
void bitonicsort(long list[]) {
   _bitonicsort(list, 0, LISTSIZE, 1);
}

int main( int argc, char *argv[]){
   runAlgorithm(argc, argv, bitonicsort);
   return 0;
}
