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
// ���� enum
enum dir
{
    LU, // ���� �� �밢��
    U,  // ��
    L   // ����
};

// class
// LCS class
class LCS
{
private:
    string x;       // x ������
    string y;       // y ������

    int** c;        // c ������ �迭 ������
    int** b;        // b ������ �迭 ������
    bool is_new;    // �����Ҵ� ����

public:
    LCS();                      // ������

    ~LCS();                     // �Ҹ���

    bool setXY();               // x, y ������ �����Լ�

    void checkACGT(string);     // ACGT ���ڿ� ����ó�� �Լ�

    void LCS_Length();          // LCS Ž���� ���� c, b �迭 �����Լ�

    void PRINT_CS(int, int);    // CS ���

    void PRINT_LCS();           // LCS ���
};


#endif //LCS_LCS_H
