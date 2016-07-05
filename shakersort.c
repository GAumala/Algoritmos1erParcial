#include "AlUtils.h"

void shakersort(long list[]) {
    for (long i = 0; i < LISTSIZE/2; i++) {
        int swapped = 0;
        for (long j = i; j < LISTSIZE - i - 1; j++) { //one way
            if (list[j] > list[j+1]) {
                  swap(&list[j], &list[j+1]);
                  swapped = 1;
            }
        }
        for (long j = LISTSIZE - 2 - i; j > i; j--) { //and back
            if (list[j] < list[j-1]) {
                swap(&list[j], &list[j-1]);
                swapped = 1;
            }
        }
        if(!swapped) break; //block (break if no element was swapped - the array is sorted)
    }
}

int main( int argc, char *argv[]){
   runAlgorithm(argc, argv, shakersort);
   return 0;
}
