//6.30 lab
#include <stdio.h>

int MinNumber(int num1, int num2, int num3, int num4)
{
    int min = num1;
    /*
    this will check for the min number between all 4 number and return 
    the min number between all 4 numbers on the function.
    */
    min = num2 < min ? num2 : min;
    min = num3 < min ? num3 : min;
    min = num4 < min ? num4 : min;
    return min;
}

int MaxNumber(int num1, int num2, int num3, int num4)
{
    int max = num1;
    /*
    this will check for the max number between all 4 number and return 
    the max number between all 4 numbers on the function.
    */
    max = num2 > max ? num2 : max;
    max = num3 > max ? num3 : max;
    max = num4 > max ? num4 : max;
    return max;
}

int main (void)
{
     /*
    We are creating 4 numbers by calling a scanner, then we are calling wach function
    Max & Min to find the numbers from the scanner. 
    */
    int num1, num2, num3, num4;
    scanf("%d %d %d %d", &num1, &num2, &num3, &num4);
    printf("Maximum is %d\n", MaxNumber( num1,  num2,  num3,  num4));
    printf("Minimum is %d\n", MinNumber( num1,  num2,  num3,  num4));
    return 0;
}
