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
		printf("test %d passed\n\n", test_counter);

	else
		printf("test %d fails\n\n", test_counter);

}


	assertP(0, 0, 3.33); //1

	
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
////////////// SET AND GET //////////////////////
	
	/*
 * assertP:
 * function is made for easy module tests of setHalfByte function.
 * INPUT:
 * byte: storage for two halfbytes
 * position: position of halfbyte to change
 * value: new value to store
 * expected: expected result of halfByteStorage() function
 * OUTPUT:
 * printed result of the test
 */
void assertP(uint8_t test_byte, uint8_t position, uint8_t value, uint8_t expected)
{
    ++test_counter;
    uint8_t result = 0;
    setHalfByte(&test_byte, position, value);
    result = getHalfByte(test_byte, position);

    if(result == expected)
    {
        printf("test %d passed\n", test_counter);
    }

    else
    {
        printf("\ntest %d fails\n", test_counter);
        printf("returned: %d\nexpected: %d\n", result, expected);
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void assertP(string argOne, string expected) {
    string result = "";
    static int test_counter = 0;
    test_counter++;

    result = KaCokadekaMe(argOne);

    if(result == expected) {
        printf("\ntest %d passed\n", test_counter);
    }

    else {
        cout << "\n------------------------------------------" << endl;
        cout << "| test " << test_counter << " fails" << endl;
        cout << "| returned: " << result << "\n| expected: " << expected << endl;
        cout << "------------------------------------------" << endl;
    }

}

int main()
{
    assertP("a", "kaa");