// 5.23 lab
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

 
    int min = userVals[0];
    for (int i = 0; i < num; i++) 
     {
         if(userVals[i] < min){
             min = userVals[i];
         }
        printf("%d and ", min);
    }
   printf("End");
   return 0;
}