//
// Created by june_spring_ on 2023-04-28.
//

#include "LCS.h"

LCS::LCS()
{
    is_new = false;
}

LCS::~LCS()
{
    if (is_new)
    {
        for (int i = 0; i < x.size(); i++)
        {
            delete[] c[i];
            delete[] b[i];
        }
        delete[] c;
        delete[] b;
    }
}

bool LCS::setXY()
{
    cout << "기존 DNA: ";
    cin >> x;
    try
    {
        checkACGT(x);
    }
    catch (vector<char> texts)
    {
        for (auto& text : texts)
            cout << text << ' ';
        cout << "는 ACGT 이외의 문자입니다.";
        return false;
    }

    cout << "비교 DNA: ";
    cin >> y;
    try
    {
        checkACGT(y);
    }
    catch (vector<char> texts)
    {
        for (auto& text : texts)
            cout << text << ' ';
        cout << "는 ACGT 이외의 문자입니다.";
        return false;
    }

    x.insert(0, "0");
    y.insert(0, "0");

    c = new int* [x.size()];
    b = new int* [x.size()];
    for (int i = 0; i < x.size(); i++)
    {
        c[i] = new int[y.size()];
        b[i] = new int[y.size()];
    }
    is_new = true;

    return true;
}

void LCS::checkACGT(string gene)
{
    vector<char> original;

    for (auto& text : gene)
        original.push_back(text);

    sort(original.begin(), original.end());
    original.erase(unique(original.begin(), original.end()), original.end());

    original.erase(remove(original.begin(), original.end(), 'A'), original.end());
    original.erase(remove(original.begin(), original.end(), 'C'), original.end());
    original.erase(remove(original.begin(), original.end(), 'G'), original.end());
    original.erase(remove(original.begin(), original.end(), 'T'), original.end());

    if (!original.empty())
        throw original;
}

void LCS::LCS_Length()
{
    sml = 0;

    int m = x.size() - 1;
    int n = y.size() - 1;

    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= n; j++)
            b[i][j] = -1;

    for (int i = 1; i <= m; i++)
        c[i][0] = 0;
    for (int j = 0; j <= n; j++)
        c[0][j] = 0;

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            if (x.at(i) == y.at(j))
            {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = LU;
            }
            else if (c[i - 1][j] >= c[i][j - 1])
            {
                c[i][j] = c[i - 1][j];
                b[i][j] = U;
            }
            else
            {
                c[i][j] = c[i][j - 1];
                b[i][j] = L;
            }

            if (c[i][j] > sml)
            {
                sml = c[i][j];
                i_LCS = i;
                j_LCS = j;
            }
        }
}

void LCS::PRINT_CS(int i, int j)
{
    if (i == 0 || j == 0)
        return;
    if (b[i][j] == LU)
    {
        PRINT_CS(i - 1, j - 1);
        cout << x.at(i);
    }
    else if (b[i][j] == U)
        PRINT_CS(i - 1, j);
    else
        PRINT_CS(i, j - 1);
}

void LCS::PRINT_LCS()
{
    if (sml == 0)
        cout << "유사도 없음";
    else
    {
        cout << "유사도 = " << sml << ", LCS = ";
        PRINT_CS(i_LCS, j_LCS);
    }
}
