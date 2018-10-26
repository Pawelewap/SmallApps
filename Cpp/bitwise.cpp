// Struct_sizeof.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int main()
{
	struct
	{
		short rok; // 2 bajty
		char dzien; // 1 bajt
	}tescik; // rozmiar struktury = 4 bajty

	struct
	{
		unsigned int rok;
		char miesiac;
		char dzien;
		char padding[2]; // dopelnienie tablica char do zadeklarowanego rozmiaru pamieci (int 4B + 2x 1B char + tablica 2B)
	}tescik2; // rozmiar struktury = 8 bajtow

	struct // rozmiar struktury 8 bajtow ale dpiero po utworzeniu instancji zagniezdzonej struktury
	{
		short a;
		
		struct
		{
			int b;
		}nestedStruct;

	}nested;



	tescik2.rok = 16;
	tescik2.miesiac = 10;
	tescik2.dzien = 17;
	tescik2.padding[0] = 0;
	tescik2.padding[1] = 1;

	std::cout << "\n sizeof struct tescik: " << sizeof(tescik);
	std::cout << "\n sizeof struct tescik2: " << sizeof(tescik2);
	std::cout << "\n sizeof nested: " << sizeof(nested) << std::endl;
	std::cout << tescik2.rok << " " << (int)tescik2.miesiac << " " << (int)tescik2.dzien
		<< " " << (int)tescik2.padding[0] << " " << (int)tescik2.padding[1] << std::endl;

    return 0;
}