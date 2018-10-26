#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <limits.h>

void lampOn(uint8_t *container, uint8_t eLampIn);
void lampOff(uint8_t *container, uint8_t eLampIn);
uint8_t lampGet(uint8_t *container, uint8_t eLampIn);

// bits enum
enum
{
	L_1 = 0u, // First byte: 0000 0001
	L_2,	  // 			 0000 0010
	L_3,	  // 			 0000 0100
	L_4,	  // 			 0000 1000
	L_5,	  // 			 0001 0000
	L_6,	  // 			 0010 0000
	L_7,      // 			 0100 0000
	L_8,	  // 			 1000 0000
	L_9,	  // Second byte:0000 0001
	L_10,	  // 			 0000 0010
	L_11,	  //  			 0000 0100
	L_12,	  //  			 0000 1000
	L_13,	  //  			 0001 0000
	L_14,	  //   			 0010 0000
	L_MAX,    // maximum value
};

// configuration enum
enum
{
	ARRAY_CLEAR   = 0u,
	ARRAY_CORRECT,
	IS_EVEN,
};

// define global variables
#define BIT L_8
static const uint8_t BYTE = (BIT / CHAR_BIT);		// calculate which byte is it

///////// MAIN FUNCTION ////////////////////

int main(void)
{
	uint8_t container[((L_MAX / sizeof(uint8_t)) + ARRAY_CORRECT)]; // calculate size of container array
    memset(&container, ARRAY_CLEAR, sizeof(container));

	lampOn(&container[BYTE], BIT);

	printf("container value: %d\n", container[BYTE]);
	printf("Is it on?: %d\n", lampGet(&container[BYTE], BIT));

	lampOff(&container[BYTE], (uint8_t)BIT);

	printf("container value: %d\n", container[BYTE]);
	printf("Is it on?: %d\n", lampGet(&container[BYTE], BIT));
	return EXIT_SUCCESS;
}

/* This function is for turning lamp on */
void lampOn(uint8_t *container, uint8_t eLampIn)
{
	*container |= (0x01 << eLampIn); // bit or -> turning ON lamp on eLampIn position
}

/* This function is for turning lamp off */
void lampOff(uint8_t *container, uint8_t eLampIn)
{
	*container ^= (0x01 << eLampIn); // bit xor -> turning OFF lamp on eLampIn position
}

/* This function is for getting lamp status */
uint8_t lampGet(uint8_t *container, uint8_t eLampIn)
{
	return ((*container >> eLampIn) % IS_EVEN);
}
