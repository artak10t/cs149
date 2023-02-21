//5.16lab
#include <stdio.h>

int main() {
   const int NUM_ELEMENTS = 20;         
   int userVals[NUM_ELEMENTS];        
   int num;

   scanf("%d", &num);
   for(int i = 0; i < num; i++) {
      int value;
      scanf("%d", &value);
      userVals[num - 1 - i] = value;
   }

   for(int i = 0; i < num; i++) {
      printf("%d,", userVals[i]);
   }

   printf("\n");
   return 0;
}