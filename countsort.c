#include "AlUtils.h"

long countingList[LISTSIZE];


void countsort(long list[]){
    long i;
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

int main( int argc, char *argv[]){
   runAlgorithm(argc, argv, countsort);
   return 0;
}
