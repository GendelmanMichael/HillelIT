#include <iostream>

using namespace std;

int main()
{
    char ch;
    cout << "enter a phrase: ";
    while (cin.get(ch))
    {
        switch (ch)
        {
        case '#':
            break;
        case '!':
            ch = '$';
        default:
            cout << ch;
        }
    }
    return 0;
}
////
// enter a phrase: Now!is#the!time#for!fun#!
// Now$isthe$timefor$fun$
