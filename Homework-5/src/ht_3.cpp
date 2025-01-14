#include <iostream>
using namespace std;

void myFunc(unsigned short int x);
int main()
{
    unsigned short int x, y;
    // variables is not defined so contains garbage value

    y = myFunc(int);
    // first of all here must be variable instead of inappropriate type,
    // second it's hard to get something from void function (consumer)
    cout << "x: " << x << "y: " << y << "\n";
}
void myFunc(unsigned short int x)
{
    return (4 * x); // void function doesn't return value
}
