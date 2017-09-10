#include "stdafx.h"
#include "SudokuProduce.h"
#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>
#pragma warning(disable:4996)

using namespace std;

SudokuProduce::SudokuProduce()
{
}


SudokuProduce::~SudokuProduce()
{
}

/*����1����9��������Ҳ��ظ����ݹ�ö��ʹ���ұ�������������־��������ͬ�����*/
template<class RandomAccessIterator>
void random_shuffle(
    RandomAccessIterator _First,
    RandomAccessIterator _Last
);
void SudokuProduce::Randperm()
{
    for (int i = 0; i < 9; ++i)
    {
        temp.push_back(i + 1);
    }
}

/*�жϸ�ö���Ƿ������������*/
bool SudokuProduce::Judge(int n, int key)
{
    int x = n / 9, y = n % 9;
    for (int col = 0; col < 9; col++)
    {
        if (soduku[x][col] == key)
        {
            return false;
        }
    }
    for (int row = 0; row < 9; row++)
    {
        if (soduku[row][y] == key)
        {
            return false;
        }
    }
    int row = x / 3 * 3, col = y / 3 * 3;
    for (int i = row; i < row + 3; i++)
    {
        for (int j = col; j < col + 3; j++)
        {
            if (soduku[i][j] == key)
            {
                return false;
            }
        }
    }
    return true;
}

/*�ݹ�ö�ٲ���һ���µ���������*/
void SudokuProduce::DFS(int num)
{
    int row = num / 9;
    int col = num % 9;
    if (num>80)
    {
        flag = true;
        return;
    }
    if (soduku[row][col] != 0)
    {
        DFS(num + 1);
    }
    else
    {
        /*��Ϊ�Ÿ�������������ֻ��9��=362880�֣����ڴ������м�����Ա������������������ʱ������ͬ������е��²�����ͬ����������*/
        if (num % 25 == 0)
        {
            std::random_shuffle(temp.begin(), temp.end());
        }
        for (int i = 0; i<9; i++)
        {
            if (Judge(num, temp[i]) == true)
            {
                soduku[row][col] = temp[i];
                DFS(num + 1);
                if (flag == true)
                {
                    return;
                }
                else
                {
                    soduku[row][col] = 0;
                }
            }
        }
    }
}

void SudokuProduce::Produce(int N)
{
    //Print p;
    ofstream out;
    //out.open("./sudoku.txt", ios::trunc);
    freopen("./sudoku.txt", "w", stdout);
    temp.clear();
    Randperm();
    while (N--)
    {
        memset(soduku, 0, sizeof(soduku));
        soduku[0][0] = 4;
        flag = false;
        std::random_shuffle(temp.begin(), temp.end());
        DFS(0);
        //p.PrintToFile(soduku);
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                char c = '0' + soduku[i][j];
                putchar(c); putchar(' ');
                //out << soduku[i][j] << " ";
            }
            puts("");
        }
        puts("");
    }
    //out.close();
}