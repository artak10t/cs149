#include <stdio.h>

void IntToReverseBinary(int integerValue, char binaryValue[]) {
    int index = 0;
    while (integerValue > 0) {
        binaryValue[index++] = '0' + (integerValue % 2);
        integerValue /= 2;
    }
    binaryValue[index] = '\0';
}

void StringReverse(char inputString[], char reversedString[]) {
    int i, size = 0;
    while (inputString[size]) ++size;
    for (i = 0; i < size; ++i) {
        reversedString[i] = inputString[size - i - 1];
    }
    reversedString[size] = '\0';
}

int main() {
    int decimal;
    char binary[100], final_binary[100];
    scanf("%d", &decimal);
    IntToReverseBinary(decimal, binary);
    StringReverse(binary, final_binary);
    printf("%s\n", final_binary);
    return 0;
}