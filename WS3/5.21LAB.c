// 5.21 lab

#include <stdio.h>
#include <string.h>

int main()
{ 
    int length;
    scanf("%d", &length);
    
    char characters[20][10];

    for (int i = 0; i < length; i++)
    {
        scanf("%s", characters[i]);
    }
    
    char searchCharacter;
    scanf(" %c", &searchCharacter);

    for (int i = 0; i < length; i++)
    {
        if (strchr(characters[i], searchCharacter) != NULL)
        {
            printf("%s,", characters[i]);
        }
    }

    printf("\n");

    return 0;
}

