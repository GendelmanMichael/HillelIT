#include <iostream>

using namespace std;

int main(int argsc, char *argsv[])
{
    cout << "{";
    for (int i = argsc - 1; i > 0; i--)
    {
        cout << " " << argsv[i];
        if (i > 1)
        {
            cout << ',';
        }
    }
    cout << "}\n";
    return 0;
}