#include <iostream>
using namespace std;

int myFunc(unsigned short int x);

int main()
{
    unsigned short int x, y;
    // variables not defined, so they stores garbage
    y = myFunc(x);
    // mismatch between variable type(unsigned short int) ant function return type(int)
    cout << "x: " << x << " y: " << y << "\n";
}

int myFunc(unsigned short int x); // semicolon close the function without a body
{
    return (4 * x);
}
