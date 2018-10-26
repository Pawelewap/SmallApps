#include <stdio.h>
#include <stdint.h> // for uint32_t
#include <stdbool.h> // boolean

uint32_t  setBit(uint8_t bit, uint32_t reg)
{
	return (reg | (0x01 << bit));	
}

uint32_t clearAndInvertBit(uint8_t bit, uint32_t reg)
{
	return (reg ^ (0x01 << bit));
}

bool getBit(uint8_t bit, uint32_t reg)
{
	return ((reg >> bit) & 0x01);
}

/*
uint32_t invertBit(uint32_t bit, uint32_t reg)
{
	return (reg ^ (0x01 << bit));
}
*/
int main()
{
	uint32_t reg = 6; // 0110, main variable
	uint8_t bit = 0;  // bit number
	printf("setBit should be 7, is: %d\n", setBit(bit, reg));

	bit = 1;
        printf("clearBit should be 4, is: %d\n", clearAndInvertBit(bit, reg));

        // bit = 1 - test with bit no 1 set to ON
        printf("getBit should return 1 (true), is: %d\n", getBit(bit, reg));

	bit = 0; // test with bit no 0 set to OFF
	printf("getBit should return 0 (false), is: %d\n", getBit(bit, reg));

	// bit = 0 - test with bit no 0 set to OFF
	printf("invertBit should return 7, is: %d\n", clearAndInvertBit(bit, reg));

	bit = 1; // test with bit no 1 set to ON
	printf("invertBit should return 4, is: %d\n", clearAndInvertBit(bit, reg));

	return 0;

}
