#include <iostream>

using namespace std;

short arr[3][3];

int main()
{

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        for (int j = 0; j < sizeof(arr[i]) / sizeof(arr[i][0]); j++)
        {
            arr[i][j] = 0;
        }
    }

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        for (int j = 0; j < sizeof(arr[i]) / sizeof(arr[i][0]); j++)
        {
            cout << " " << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}