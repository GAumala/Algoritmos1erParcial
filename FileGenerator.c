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
   long number = rand() % LISTSIZE + 1;
   sprintf(str, "%ld", number);
   fputs(str, fp);
   for(i = 1; i < LISTSIZE; i++ ){
     long number = rand() % LISTSIZE + 1;
     sprintf(str, "\n%ld", number);
     fputs(str, fp);
   }
   fclose(fp);

   return(0);
}
