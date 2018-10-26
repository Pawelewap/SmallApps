#include <iostream>
#include <math.h>

int test_counter = 0;

/* calcArray:
 * calculate sum of nearby elements and returns average of elements
 * resolution X - 0 to 3
 * resolution Y - 0 to 3
 * INPUT:
 * posX: position of first dimension of an array
 * posY: position of second dimension of an array
 * OUTPUT:
 * aver: computed average of elements nearby to given position
 */
float calcArray(int posX = 0, int posY = 0)
{
	static int tab[4][4] = {{0,  1,  2,  3},
	                        {4,  5,  6,  7},
	                        {8,  9,  10, 11},
	                        {12, 13, 14, 15}};

	int counter = 0;
	float sum   = 0;
	if((posX < 0 || posX > 3) || (posY < 0 || posY > 3))
	{
		return 0;
	}
	else
	{
		for(int i = posX - 1; i < posX + 2; i++)
		{
			if((posX == 0 && i < 0) || (posX == 3 && i > 3))
			{
				continue;
			}

			for(int j = posY - 1; j < posY + 2; j++)
			{
				if(i == posX && j == posY)
				{
					std::cout << "  ";
					continue;
				}

				else if((posY == 0 && j < 0) || (posY == 3 && j > 3))
				{
					continue;
				}

				else
				{
					std::cout << tab[i][j] << " ";
					counter++;
					sum += tab[i][j];
				}
			}
			std::cout << "\n";
		}
	}
	    float aver = sum / counter;

	    return aver;
}

/*
 * assertP:
 * function is made for easy module tests of calcArray function.
 * INPUT:
 * argOne: position of first dimension of an array
 * argTwo: position of second dimension of an array
 * expected: expected result of calcArray() function
 * OUTPUT:
 * printed result of the test
 */

void assertP(int argOne, int argTwo, float expected)
{
	float ret = 0;
	test_counter++;
	ret = (round(calcArray(argOne, argTwo) * 100) / 100);

	if(ret == expected)
		std::cout << "test " << test_counter <<" passed\n\n";

	else
		std::cout << "test " << test_counter <<" fails\n\n";

}

int main()
{
	/*
	 * test corners:
	 */
	assertP(0, 0, 3.33); //1
    assertP(0, 3, 5);    //2
    assertP(3, 0, 10);   //3
    assertP(3, 3, 11.67);//4

    /*
     * test middle
     */
    assertP(2, 2, 10);    //5

    /*
     * test from every side
     */
    assertP(0, 2, 4.4);  //6
    assertP(1, 0, 4.6);  //7
    assertP(2, 3, 10.4); //8
    assertP(3, 2, 11.6); //9

    /*
     * test if out of range (should return 0)
     */

    assertP(-1, -1, 0);        //10
    assertP(0, -1, 0);         //11
    assertP(-1, 0, 0);         //12
    assertP(100000000, 0, 0);  //13
    assertP(0, 100000000, 0);  //14
    assertP(-99, 100000000, 0);//15
    assertP(100000000, -99, 0);//16

    /*
     * Bad expected values:
     */
    assertP(0, 2, 2);    //17
    assertP(1, 1, 9);    //18
    assertP(2, 2, 2);    //19
}
