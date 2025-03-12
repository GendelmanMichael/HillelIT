#include <iostream>
#include <fstream>

using namespace std;

char *ExtendArr(char *arr, int &length, int nlength = -1)
{
    if (nlength < 0)
    {
        nlength = 2 * length;
    }
    char *res = new char[nlength];
    for (int i = 0; i < length; i++)
    {
        res[i] = arr[i];
    }
    length = nlength;
    delete[] arr;
    return res;
}

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        ifstream file(argv[1]);
        if (!file)
        {
            cout << "Unable to open " << argv[1] << " for reading.\n";
            return 1;
        }
        int capacity = 16;
        char *res = new char[capacity];
        char ch;
        int count = 0;
        while (file.get(ch))
        {
            if (ch > 31 && ch < 127)
            {
                if (count == capacity)
                {
                    res = ExtendArr(res, capacity);
                }
                res[count++] = ch;
            }
        }
        res = ExtendArr(res, count, count);
        cout << res << endl;
        file.close();
    }
    else
    {
        cout << "Please enter filename as argument\n";
    }
    return 0;
}