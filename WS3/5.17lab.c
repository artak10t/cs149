// 5.17 lab
#include <stdio.h>
int main() {
   const int NUM_ELEMENTS  = 9;        
   int userVals[NUM_ELEMENTS];          
   int i = 0;
   int input = 0;
   
  while (input >= 0) {
      if(i > NUM_ELEMENTS ){
          printf("TOO many numbers");
      }
      scanf("%d", &input);
      if(input >= 0){
          userVals[i++] = input;
      }
   }
   printf("Middle item: %d\n", userVals[i/2]);
   return 0;
}