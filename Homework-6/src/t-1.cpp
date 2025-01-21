#include <iostream>

using namespace std;

long int numInPow(short int num, unsigned short int pow);

int main()
{

    short int num;
    unsigned short int pow;

    cout << "Enter number (-32768 -> 32767): ";
    cin >> num;
    cout << endl
         << "Enter power (0 -> 65535): ";
    cin >> pow;
    long int res = numInPow(num, pow);
    cout << endl
         << num << '^' << pow << '=' << numInPow(num, pow) << endl;

    return 0;
}

long int numInPow(short int num, unsigned short int pow)
{
    return pow == 0 ? 1 : pow == 1 ? num
                                   : num * numInPow(num, --pow);
}
