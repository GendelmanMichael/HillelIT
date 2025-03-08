#include <iostream>

using namespace std;

int main()
{

    char name[50];
    cout << "Please enter your full name: ";
    cin.getline(name, 50);
    cout << "Hello " << name << endl;

    return 0;
}