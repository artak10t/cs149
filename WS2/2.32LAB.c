// 2.32 Lab 
#include <stdio.h>
#include <math.h>

int main()
{
    int curPrice, lastPrice;

    scanf("%d %d", &curPrice, &lastPrice);
    int change = (curPrice - lastPrice);
    double estimatedMortage = ((curPrice * 0.051)/12);

    printf("This house is $%d. The change is $%d since last month.\nThe estimated monthly mortgage is $%.6lf.\n",curPrice,change,estimatedMortage);
    return 0;
}