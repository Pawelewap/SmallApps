#include <stdio.h>
#include <stdint.h>

uint16_t CheckLength(const uint8_t* str)
{
    uint16_t length = 0;
    for(;str[length] != 0; length++);

    return length;
}

void ReverseStrin(uint8_t* str)
{
    uint16_t length = CheckLength(str);
    uint16_t mid = (length / 2);

    for(uint16_t i = 0; i < mid; i++)
    {
        length--;
        str[i] ^= str[length];
        str[length] ^= str[i];
        str[i] ^= str[length];
    }
}

int main()
{
    uint8_t sourceStr[] = "abcd";
    ReverseStrin(sourceStr);
    printf("str: %s", sourceStr);
}