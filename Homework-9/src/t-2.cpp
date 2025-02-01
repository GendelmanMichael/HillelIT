#include <iostream>

using namespace std;

int maon()
{

    int varOne, varTwo;
    int *const pVarOne = &varOne;
    varOne = 6;
    *pVarOne = 7;
    pVarOne = &varTwo;
    // error trying to change const pointer error image for t-3 included

    return 0;
}