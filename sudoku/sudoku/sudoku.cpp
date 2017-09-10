// sudoku.cpp : �������̨Ӧ�ó������ڵ㡣
//
/*��������Print��Check��SudokuProduce�ֱ���Ϊ�������������Ƿ�淶������������
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include "Check.h"
#include "SudokuProduce.h"
//#include "Print.h"

using namespace std;

int main(int argc, char* argv[])
{
    string input;
    Check c;
    SudokuProduce s;
    //Print P;
    int N;
    if (argc == 1)
    {
        cout << "please input another parameter������" << endl;
        exit(-1);
    }
    else if(argc == 2)
    {
        if (argv[1] != "-c")
        {
            cout << "please input correct parameter������" << endl;
            return 0;
        }
    }
    else if (argc == 3)
    {
        if (argv[1] == "-c")
        {
            input = argv[2];
            N = c.CheckNum(input);
            if (N < 0)
            {
                cout << "please input a integer������" << endl;
                return 0;
            }
            else s.Produce(N);
        }
        else
        {
            cout << "please input correct parameter������" << endl;
            return 0;
        }
        
    }    
    else
    {
        cout << "Too many parameter!!!" << endl;
        return 0;
    }
    return 0;
}
