// 1:

int *pOne; // declare pointer for int variable

int vTwo; // declare int variable

int *pThree = &vTwo; // declare and define pointer with address of int variable vTwo

// 2:

unsigned short yourAge;
unsigned short *pYourAge = &yourAge;

// 3:

void foo()
{

	*pYourAge = 50;

} // need to wrap it to define

// 4:

#include <iostream>
using namespace std;

int main()
{
	int boo = 5;
	int *pBoo = &boo;
	cout << " boo before change: " << boo << endl;
	*pBoo = 8;
	cout << " boo after change: " << boo << endl;
	return 0;
}

// 5:

int main_5()
{
	int *pInt;
	// pointer declared but not defined with any memory address
	// need to define it with local variable or using "new"
	*pInt = 9;
	cout << " The value at pInt: " << *pInt;

	return 0;
}

// 6:

int main_6()
{
	int SomeVariable = 5;
	cout << "SomeVariable: " << SomeVariable << "\n";
	int *pVar = &SomeVariable;
	pVar = 9; // trying to put value in a pointer data type, "*" is  missed
	cout << "SomeVariable: " << *pVar << "\n";
	return 0;
}
