// 2.25 Lab : dyvide by x
#include <stdio.h>
int main()
{
   int x, y;

   scanf("%d %d", &x, &y);
   int dev1 = x / y;
   int dev2 = dev1 / y;
   int dev3 = dev2 / y; 

   printf("%d %d %d", dev1, dev2, dev3);
   return 0;
}