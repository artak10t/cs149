//lab 6.20
#include <stdio.h>
/*
Here we just made a simple math function to calculate the miles for each lap
*/
double LapsToMiles(double laps){
    double miles = laps * 0.25;
    return miles; 
}

/*
we made a scanner for the number of laps they have done so it can give the mile
numbers in a double number by calling the LapsToMiles function. 
*/
int main(void)
{
    double rounds;
    scanf("%lf", &rounds);
    double outPut = LapsToMiles(rounds);
    printf("%0.2lf\n", outPut);
    return 0;

}
