#include <stdio.h>
#include <string.h>

int main()
{
    char str[60];

    while (fgets(str, 60, stdin) != NULL)
    {
        char *ptr = strchr(str, '\n');
        if (ptr)
        {
            //if new line found replace with a null character
            *ptr  = '\0';
        }

        if (strcmp(str, "d") == 0 || strcmp(str, "done") == 0 || strcmp(str, "Done") == 0) return 0;
        
        printInReverse(str);
    }
    
    return 0;
}

void printInReverse(char *str)
{
    int n = strlen(str);

    for (int i = n - 1; i >= 0; i--)
    {
        printf("%c", str[i]);
    }
    printf("\n");
}
