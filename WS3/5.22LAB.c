// 5.22 lab
#include <stdio.h>
int main(void) 
{
    int length;
    scanf("%d", &length);

    int array[length];

    for (int i = 0; i < length; i++)
    {
        scanf("%d", &array[i]);
    }

    int minOne = array[0] >= array[1] ? array[1] : array[0];
    int minTwo = array[0] >= array[1] ? array[0] : array[1];

    for (int i = 2; i < length; i++)
    {
        if (array[i] < minTwo) 
        {
            minTwo = array[i];
        }
        if (array[i] < minOne)
        {
            minTwo = minOne;
            minOne = array[i];
        }
    }

    printf("%d and %d\n", minOne, minTwo);

    return 0;
}