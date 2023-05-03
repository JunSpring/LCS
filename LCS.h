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

// enum
// 방향 enum
enum dir
{
    LU, // 왼쪽 위 대각선
    U,  // 위
    L   // 왼쪽
};

// class
// LCS class
class LCS
{
private:
    string x;       // x 유전자
    string y;       // y 유전자

    int** c;        // c 이차원 배열 포인터
    int** b;        // b 이차원 배열 포인터
    bool is_new;    // 동작할당 여부

public:
    LCS();                      // 생성자

    ~LCS();                     // 소멸자

    bool setXY();               // x, y 유전자 설정함수

    void checkACGT(string);     // ACGT 문자열 예외처리 함수

    void LCS_Length();          // LCS 탐색을 위한 c, b 배열 설정함수

    void PRINT_CS(int, int);    // CS 출력

    void PRINT_LCS();           // LCS 출력
};


#endif //LCS_LCS_H
