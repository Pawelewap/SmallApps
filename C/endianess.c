#include <stdio.h>

void checkWitchUnion()
{
    union
    {
        int check;
        char endianess;
    }endian;

    endian.check = 0x00000001;

    if(0x01 & endian.endianess)
    {
        printf("little endian\n");
    }
    else
    {
        printf("big endian\n");
    }
}

void checkWitchPointer()
{
    int check = 1; // 0x00 00 00 01 little endian

    if(0x01 == (*(char*)&check))
    {
        printf("little endian\n");
    }
    else
    {
        printf("big endian\n");
    }
}


int main()
{
    checkWitchUnion();
    checkWitchPointer();
}