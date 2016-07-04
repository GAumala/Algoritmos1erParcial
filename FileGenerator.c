#include "AlUtils.h"
#include <time.h>


int main ()
{
   FILE *fp;

   fp = fopen("nums.txt", "w+");
   time_t t;
   int i;
   /* Intializes random number generator */
   srand((unsigned) time(&t));
   char str[9];
   int number = rand() % LISTSIZE + 1;
   sprintf(str, "%d", number);
   fputs(str, fp);
   for(i = 1; i < LISTSIZE; i++ ){
     int number = rand() % LISTSIZE + 1;
     sprintf(str, "\n%d", number);
     fputs(str, fp);
   }
   fclose(fp);

   return(0);
}
