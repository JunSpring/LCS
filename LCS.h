//
// Created by june_spring_ on 2023-04-28.
//

#ifndef LCS_LCS_H
#define LCS_LCS_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

enum dir
{
    LU,
    U,
    L
};

class LCS
{
private:
    string x;
    string y;

    int **c;
    int **b;
    bool is_new;

    int i_LCS;
    int j_LCS;
    int sml;

public:
    LCS();

    ~LCS();

    bool setXY();

    void checkACGT(string);

    void LCS_Length();

    void PRINT_CS(int, int);

    void PRINT_LCS();
};


#endif //LCS_LCS_H
