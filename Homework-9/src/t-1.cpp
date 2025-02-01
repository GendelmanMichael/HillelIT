#include <iostream>

using namespace std;

int main()
{
    int foo;
    int *pFoo = &foo;
    int &lFoo = foo;

    foo = 6;

    cout << endl
         << "foo = 6" << endl;
    cout << "value foo:  " << foo << endl;
    cout << "value pFoo: " << *pFoo << endl;
    cout << "value lFoo: " << lFoo << endl;

    *pFoo = 14;

    cout << endl
         << "*pFoo = 14" << endl;
    cout << "value foo:  " << foo << endl;
    cout << "value pFoo: " << *pFoo << endl;
    cout << "value lFoo: " << lFoo << endl;

    lFoo = 22;

    cout << endl
         << "lFoo = 22" << endl;
    cout << "value foo:  " << foo << endl;
    cout << "value pFoo: " << *pFoo << endl;
    cout << "value lFoo: " << lFoo << endl;

    return 0;
}