#include <stdio.h>
#include <string.h>

void swapNums(char* stringNum)
{
    int length = strlen(stringNum);
    int mid = length / 2;
    for(int i = 0; i < mid; i++)
    {
        length--;
        stringNum[i] ^= stringNum[length];
        stringNum[length] ^= stringNum[i];
        stringNum[i] ^= stringNum[length];
    }
}

int main()
{
    int number;
    printf("num: ");
    scanf("%d", &number);

    int num1;
    int num2;
    num1 = number / 10;
    num2 = number % 10;
    number = (num2 * 10) + num1;

    printf("\nnum: %d",number);

    /* *********************** */
    int longnum = 123456;
    char stringNum[6];
    sprintf(stringNum, "%d", longnum); // save long num as string
    swapNums(stringNum); // reverse string
    printf("\n%s", stringNum);


}