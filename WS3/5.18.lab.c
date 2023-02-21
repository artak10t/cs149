// 5.18 lab
#include <stdio.h>
int main(void) 
{
    const int NUM_ELEMENTS  = 20;       
    int userVals[NUM_ELEMENTS];          

    int num;
    scanf("%d", &num);

    for (int i = 0; i < num; i++) 
     {
          scanf("%d", &userVals[i]);
     }

    int threshold;
    scanf("%d", &threshold);
    
    for (int i = 0; i < num; i++) 
     {
         if(userVals[i] <= threshold ){
            printf("%d,", userVals[i]);

         }
     }
   printf("\n");
   return 0;
}