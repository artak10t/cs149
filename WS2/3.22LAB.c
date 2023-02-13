// 2.22 Lab 
#include <stdio.h>
#include <math.h>

int main()
{
    int x, y , z;
    scanf("%d %d %d", &x, &y, &z);
    int value = x < y ? x : y;
    value = value < z ? value : z;
    printf("%d\n", value);

}