//4.14lab 
#include <stdio.h>
int main() {
    int x;

    scanf("%d", &x);
    
    while(x>0){
        int reminder = x % 2;
        printf("%d", reminder);
        x = x/2;
    }
    printf("\n");
    return 0;
}
