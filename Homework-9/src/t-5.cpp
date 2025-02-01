#include <iostream>

using namespace std;

int main()
{

    cout << "size of int:   " << sizeof(int) << endl;
    cout << "size of short: " << sizeof(short) << endl;

    int *pInt = new int(32);

    cout << "Value pInt: " << *pInt << endl;

    delete pInt;
    pInt = nullptr; // next usage of this pointer occurs exception

    cout << "delete pInt" << endl;

    short *pShort = new short(64);

    cout << "Value pShort: " << *pShort << endl;
    cout << "Value pInt:   " << *pInt << endl;

    *pInt = 32768;
    cout << "*pInt = 32768" << endl;

    cout << "Value pShort: " << *pShort << endl;
    cout << "Value pInt:" << *pInt << endl;

    return 0;
}