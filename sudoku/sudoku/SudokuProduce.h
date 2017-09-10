#pragma once
#include <iostream>
#include <vector>
using namespace std;

class SudokuProduce
{
public:
    SudokuProduce();
    ~SudokuProduce();
    void Produce(int N);
    void Randperm();
    void DFS(int num);
    bool Judge(int n, int i);
private:
    int soduku[9][9];
    vector<int>temp;
    bool flag = false;
};

