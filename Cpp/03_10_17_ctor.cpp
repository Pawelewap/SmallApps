#include <iostream>
using std::cout;
using std::endl;

static int counter;
bool       checkIfInvoke = true;

class PawelSzydelko
{
private:
    double cheesburger;
    double chips;
    float  cola;

public:
        PawelSzydelko() // konstruktor domyslny
        {
        	counter++;
        	cheesburger = 1;
        	chips = 1;
        	cola = 1;
        	cout << "Default constructor " << counter << endl;
        }

        PawelSzydelko(const PawelSzydelko &other) // konstruktor kopiujacy
        {
        	counter++;
        	cheesburger = other.cheesburger + 1;
        	chips = 1;
        	cola = 1;
            cout << "Copy constructor " << counter <<endl;
        }

        PawelSzydelko(int arg) // konstruktor z jednym argumentem formalnym
        {
        	counter++;
        	cheesburger = arg;
        	chips = 1;
        	cola = 1;
            cout << "constructor with one argument "<< counter << endl;
        }

        PawelSzydelko(int arga, int argb, int argc) // konstruktor z wieloma argumentami
        : cheesburger(arga), // lista inicjalizacyjna konstruktora
		  chips(argb),
		  cola(argc) // zmiana wartosci stalej
        {
        	counter++;
        	cout << "constructor with many arguments "<< counter << endl;
        }

        PawelSzydelko(int arga, int argb): PawelSzydelko(1)
        {
        	cout << "delegating constructor " << counter << endl;
        }

        ~PawelSzydelko()
        {
        	counter--;
        	cout << "destructor " << counter << endl;
        }

        void DoWork()
        {
        	if(checkIfInvoke)
        	{
        		cout << "done" << endl;
        		checkIfInvoke = false;
        	}
        	else
        	{
        		cout << "already done" << endl;
        	}
        }

}psObj; // tworzenie pierwszego obiektu przed wywolaniem main

int main()
{

	PawelSzydelko psObj2(2); // jeden arg
	psObj2.DoWork();
	PawelSzydelko psObj3(3,3,3); // wiele arg
	psObj3.DoWork();
	PawelSzydelko psObj4(3,3); // delegujacy
	psObj4.DoWork();
	PawelSzydelko psObj5(psObj3); // kopiujacy
	psObj4.DoWork();

}
