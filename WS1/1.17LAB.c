//1.17 LAB:Formatted output: Right-facing arrow 
#include <stdio.h>
int main()
{   
    int x, y;
    printf("Enter two integers:");
    scanf("%d %d", &y,&x);
    printf("    %d\n",          x);
    printf("    %d%d\n",        x,x);
    printf("%d%d%d%d%d%d%d\n",y,y,y,y,x,x,x);
    printf("%d%d%d%d%d%d%d%d\n",y,y,y,y,x,x,x,x);
    printf("%d%d%d%d%d%d%d\n",y,y,y,y,x,x,x);
    printf("    %d%d\n",        x,x);
    printf("    %d\n",          x);
    return 0;
}	