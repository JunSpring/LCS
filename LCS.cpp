//
// Created by june_spring_ on 2023-04-28.
//

#include "LCS.h"

// ������
LCS::LCS()
{
    is_new = false; // �����Ҵ� ���� ���� ����
}

// �Ҹ���
LCS::~LCS()
{
    // �Ҹ��� �� �����Ҵ��� ���� ���
    if (is_new)
    {
        // �����Ҵ� ����
        for (int i = 0; i < x.size(); i++)
        {
            delete[] c[i];
            delete[] b[i];
        }
        delete[] c;
        delete[] b;
    }
}

// x, y ������ �����Լ�
bool LCS::setXY()
{
    // x ������ �Է�
    cout << "���� DNA: ";
    cin >> x;
    // ����ó��
    try
    {
        checkACGT(x);
    }
    catch (vector<char> texts)              // ACGT ����ó��
    {
        for (auto &text: texts)
            cout << text << ' ';
        cout << "�� ACGT �̿��� �����Դϴ�.";
        return false;
    }
    catch (unsigned long long int length)   // ���� ���� ����ó��
    {
        cout << "�Է��Ͻ� ���ڿ��� ���̴� " << length <<"���Դϴ�." << endl;
        cout << "�Է� ���ڿ��� �ּ� 10�� �̻��̿��� �մϴ�.";
        return false;
    }

    // y ������ �Է�
    cout << "�� DNA: ";
    cin >> y;
    // ����ó��
    try
    {
        checkACGT(y);
    }
    catch (vector<char> texts)              // ACGT ����ó��
    {
        for (auto& text : texts)
            cout << text << ' ';
        cout << "�� ACGT �̿��� �����Դϴ�.";
        return false;
    }
    catch (unsigned long long int length)   // ���� ���� ����ó��
    {
        cout << "�Է��Ͻ� ���ڿ��� ���̴� " << length <<"���Դϴ�." << endl;
        cout << "�Է� ���ڿ��� �ּ� 10�� �̻��̿��� �մϴ�.";
        return false;
    }

    // x, y ���ڿ� �� �տ� �ƹ� �� insert
    x.insert(0, "0");
    y.insert(0, "0");

    // �����Ҵ�
    c = new int* [x.size()];
    b = new int* [x.size()];
    for (int i = 0; i < x.size(); i++)
    {
        c[i] = new int[y.size()];
        b[i] = new int[y.size()];
    }
    is_new = true; // �����Ҵ� �� ����

    return true;
}

// ACGT ���ڿ� ����ó�� �Լ�
void LCS::checkACGT(string gene)
{
    // ���ڿ� ���̰� 10 ���϶�� ���ڿ� ���� throw
    if(gene.size() < 10)
        throw gene.size();

    // ���� ����
    vector<char> original;

    // string ���� ���Ϳ� ����
    for (auto& text : gene)
        original.push_back(text);

    // ����
    sort(original.begin(), original.end());
    // ���� �ߺ����� �ʰ� �����ϰ� �ߺ��Ǵ� �κ� �����
    original.erase(unique(original.begin(), original.end()), original.end());

    // ACGT �����
    original.erase(remove(original.begin(), original.end(), 'A'), original.end());
    original.erase(remove(original.begin(), original.end(), 'C'), original.end());
    original.erase(remove(original.begin(), original.end(), 'G'), original.end());
    original.erase(remove(original.begin(), original.end(), 'T'), original.end());

    // ���Ͱ� ������� �ʴٸ�
    if (!original.empty())
        // ���� throw
        throw original;
}

// LCS Ž���� ���� c, b �迭 �����Լ�
// �� �Լ��� �����ڷ�� ����
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
        }
}

// CS ���
// �� �Լ��� �����ڷ�� ����
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

// LCS ���
void LCS::PRINT_LCS()
{
    // ���絵�� ���� ���
    if (c[x.size() - 1][y.size() - 1] == 0)
        cout << "���絵 ����";
    // ���絵�� �ִ� ���
    else
    {
        cout << "���絵 = " << c[x.size() - 1][y.size() - 1] << ", LCS = ";
        PRINT_CS(x.size() - 1, y.size() - 1);
    }
}
