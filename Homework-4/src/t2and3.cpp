#include <iostream>

using namespace std;

int main()

{

    int a, b, c;

    cout << "Please enter three numbers) \n";

    cout << "a: ";

    cin >> a;

    cout << "\nb: ";

    cin >> b;

    cout << "\nc: ";

    cin >> c;

    // if we will fix an error and change c = (a - b) with (c == (a - b)
    // it will check if ( a - b ) is equals to c otherwise
    // expression will be resolved as true every time except "a" equals to "b" because
    // only 0 is false and everything except 0 is true

    if (c == (a - b))

    {

        cout << "\na: ";

        cout << a;

        cout << " minus b: ";

        cout << b;

        cout << " equals c: ";

        cout << c << endl;
    }

    else

        cout << "a - b does not equal c: " << endl;

    return 0;
}
