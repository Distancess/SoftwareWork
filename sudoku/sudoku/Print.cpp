#include "stdafx.h"
#include "Print.h"
#include <iostream>
#include <fstream>

using namespace std;

Print::Print()
{
}


Print::~Print()
{
}

void Print::PrintToFile(int arry[9][9])
{
    ofstream out;
    out.open("./sudoku.txt", ios::out|ios::app);
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            out << arry[i][j] << " ";
        }
        out << endl;
    }
    out << endl;
    out.close();
}

