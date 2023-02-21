//4.16lab 
#include <stdio.h>

int main(void) {
   int max = 0;
   double sum = 0;
   int i = -1;
   int input = 0;

   while (input >= 0) {
      sum = sum + input;
      max = input > max ? input : max;
      i++;
      scanf("%d", &input);
   }

   printf("%d %0.2lf\n", max, sum / i);

   return 0;
}