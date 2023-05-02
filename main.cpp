#include <iostream>
#include "LCS.h"

using namespace std;

int main()
{
    LCS lcs;

    if (!lcs.setXY())
        return 0;
    lcs.LCS_Length();
    lcs.PRINT_LCS();

    return 0;
}
