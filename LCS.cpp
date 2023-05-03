//
// Created by june_spring_ on 2023-04-28.
//

#include "LCS.h"

// 생성자
LCS::LCS()
{
    is_new = false; // 동적할당 하지 않은 상태
}

// 소멸자
LCS::~LCS()
{
    // 소멸할 때 동적할당을 했을 경우
    if(is_new)
    {
        // 동적할당 해제
        for (int i = 0; i < x.size(); i++)
        {
            delete[] c[i];
            delete[] b[i];
        }
        delete[] c;
        delete[] b;
    }
}

// x, y 유전자 설정함수
bool LCS::setXY()
{
    // x 유전자 입력
    cout << "기존 DNA: ";
    cin >> x;
    // 예외처리
    try
    {
        checkACGT(x);
    }
    catch (vector<char> texts)
    {
        for (auto &text: texts)
            cout << text << ' ';
        cout << "는 ACGT 이외의 문자입니다.";
        return false;
    }

    // y 유전자 입력
    cout << "비교 DNA: ";
    cin >> y;
    // 예외처리
    try
    {
        checkACGT(y);
    }
    catch (vector<char> texts)
    {
        for (auto &text: texts)
            cout << text << ' ';
        cout << "는 ACGT 이외의 문자입니다.";
        return false;
    }

    // x, y 문자열 맨 앞에 아무 값 insert
    x.insert(0, "0");
    y.insert(0, "0");

    // 동적할당
    c = new int *[x.size()];
    b = new int *[x.size()];
    for (int i = 0; i < x.size(); i++)
    {
        c[i] = new int[y.size()];
        b[i] = new int[y.size()];
    }
    is_new = true; // 동적할당 한 상태

    return true;
}

// ACGT 문자열 예외처리 함수
void LCS::checkACGT(string gene)
{
    // 벡터 선언
    vector<char> original;

    // string 값을 벡터에 대입
    for (auto &text: gene)
        original.push_back(text);

    // 정렬
    sort(original.begin(), original.end());
    // 값이 중복되지 않게 정렬하고 중복되는 부분 지우기
    original.erase(unique(original.begin(), original.end()), original.end());

    // ACGT 지우기
    original.erase(remove(original.begin(), original.end(), 'A'), original.end());
    original.erase(remove(original.begin(), original.end(), 'C'), original.end());
    original.erase(remove(original.begin(), original.end(), 'G'), original.end());
    original.erase(remove(original.begin(), original.end(), 'T'), original.end());

    // 벡터가 비어있지 않다면
    if (!original.empty())
        // 벡터 throw
        throw original;
}

// LCS 탐색을 위한 c, b 배열 설정함수
// 이 함수는 강의자료와 동일
void LCS::LCS_Length()
{
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
            } else if (c[i - 1][j] >= c[i][j - 1])
            {
                c[i][j] = c[i - 1][j];
                b[i][j] = U;
            } else
            {
                c[i][j] = c[i][j - 1];
                b[i][j] = L;
            }
        }
}

// CS 출력
// 이 함수는 강의자료와 동일
void LCS::PRINT_CS(int i, int j)
{
    if (i == 0 || j == 0)
        return;
    if (b[i][j] == LU)
    {
        PRINT_CS(i - 1, j - 1);
        cout << x.at(i);
    } else if (b[i][j] == U)
        PRINT_CS(i - 1, j);
    else
        PRINT_CS(i, j - 1);
}

// LCS 출력
void LCS::PRINT_LCS()
{
    // 유사도가 없는 경우
    if (c[x.size()-1][y.size()-1] == 0)
        cout << "유사도 없음";
    // 유사도가 있는 경우
    else
    {
        cout << "유사도 = " << c[x.size()-1][y.size()-1] << ", LCS = ";
        PRINT_CS(x.size()-1, y.size()-1);
    }
}
