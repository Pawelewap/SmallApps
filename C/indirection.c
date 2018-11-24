#include <stdio.h>

int main()
{
    char string[2][4] = {"abcd", "efgh"};
    char* ptrOne = &string;
    char** ptrTwo = &ptrOne;

    printf("Indirection string[0][2]: %c\n\n", *(*ptrTwo) + 3);

    ptrOne++;
    printf("Indirection string[0][2]: %c\n\n", *(*ptrTwo));

    return 0;
}
