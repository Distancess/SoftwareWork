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

/*产生1——9的随机数且不重复供递归枚举使用且避免出现数独部分局面出现雷同的情况*/
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

/*判断该枚举是否符合数独规则*/
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

/*递归枚举产生一个新的数独局面*/
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
        /*因为九个数随机排列最多只有9！=362880种，故在此设置中间过程以避免数据量超过这个数时产生相同随机序列导致产生相同的数独局面*/
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