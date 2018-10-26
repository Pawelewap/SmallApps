#include <stdio.h>

typedef struct {
	unsigned int day : 5; //32
	unsigned int month : 4; //16
	unsigned int year : 12; //4096
	unsigned int padding : 11; //free 2048
} dateS;

int main()
{
	printf_s("Size of dateS structure: %d", sizeof(dateS));
	dateS date;
	date.padding = 0; // 000 0000 0000
	short mask = 1; // 0000 0000 0000 0001

	printf_s("\npadding before 0 | 1 : %d", date.padding);
	date.padding |= mask; // 000 0000 0001
	printf_s("\npadding after 0 | 1: %d", date.padding);
	date.padding <<= 2; // 000 0000 0100
	printf_s("\npadding after <<= 2: %d \n\n", date.padding);

	mask = 0xff; // 1111 1111
	date.padding ^= mask; // 000 1111 1011

	int IsBitOnOrOff[11]; // size of "padding" variable (11 bits)
	int whereIsBitOn[11];
	int tempPadding = date.padding;
	int i = 0, counter = 0;

	for (i = 0; i < 11; i++)
	{
		if (tempPadding % 2)
		{
			IsBitOnOrOff[i] = 1;
			whereIsBitOn[counter] = i + 1;
			counter++;
		}
		else
			IsBitOnOrOff[i] = 0;

		tempPadding >>= 1;
	}

	for (i = 10; i >= 0; i--)
	{
		if (i % 4 == 3)
			printf_s(" ");
		printf_s("%d", IsBitOnOrOff[i]);
		
	}

	printf_s("\nHow many bits are ON?: %d", counter);

	for (i = 0; i < counter; i++)
	{
		if (counter == 0)
			printf("\n there is no ON bits");
		else
			printf_s("\nbit on position %d is ON", whereIsBitOn[i]);
	}

	date.day = 16;
	date.month = 11;
	date.year = 2016;

	printf_s("\n\n%d", date.day);
	printf_s("-%d", date.month);
	printf_s("-%d", date.year);
	
	printf_s("\n");
}
