#include "AlUtils.h"

int list[LISTSIZE];
int countingList[LISTSIZE];

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
    insertionsort(list);
    displayFirstAndLast(list);

    return 0;
}
