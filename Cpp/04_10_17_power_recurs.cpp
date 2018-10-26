#include <iostream>
#include <climits>

using std::cout;
using std::cin;

int power(int base , int nPower)
{
    if(nPower < 0)
    	return 0;

    else if (nPower == 0)
    	return 1;

    else
    	return (base * power(base, nPower - 1));
}

int assertP(int base, int nPower, int exp)
{
	int ret = 0;
	ret = power(base, nPower);
	cout << ret << std::endl;
	if(ret == exp)
		cout << "test passed\n";

	else
		cout << "test not passed\n";

	return ret;
}

int main()
{
    int base, nPower, ret;

    cout << "give base number: ";
    cin >> base;
    cout << "give power number: ";
    cin >> nPower;

    ret = power(base, nPower);

    cout << base << " ^ "<< nPower << " is: " << ret;

    cout << std::endl;
    assertP(10, 2, 100);
    assertP(5, 3, 125);
    assertP(0, 0, 1);
    assertP(-1, 0, 1);
    assertP(0, -1, 1);

    cout << INT_MAX;


//    // 0 i 0
//    // 1 i 100 lub wiecej

    return 0;
}


//int size;
//a = size / n
//if (a > n)
//	licze dalej
//else
//	break;
