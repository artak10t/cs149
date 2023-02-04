//1.19 LAB:Formatted output: Basic output with variables  
#include <stdio.h>
int main()
{   
    int x, y;
    printf("Enter integer:\n");
    scanf("%d",&x);
    printf("You entered: %d\n", x);
    int b = x * x;
    printf("%d squared is %d\n",x, b);
    int c = x * x * x;
    printf("And %d cubed is %d!!\n",x, c);
    printf("Enter another integer: \n");
    scanf("%d",&y);
    int d = x + y;
    printf("%d + %d is %d\n", x, y , d);
    int e = x * y;
    printf("%d * %d is %d\n", x, y , e);
    return 0;
}