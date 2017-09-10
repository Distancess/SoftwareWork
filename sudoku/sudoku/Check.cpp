#include "stdafx.h"
#include "Check.h"
#include <sstream>


Check::Check()
{
}


Check::~Check()
{
}

int Check::CheckNum(string str)
{
    int i;
    int l = str.size();
    for (i = 0; i < l; i++)
        if (str[i] < '0' || str[i]>'9') break;
    if (i < l)
        return -1;
    else
    {
        int num;
        stringstream stream;
        stream << str;
        stream >> num;
        stream.clear();
        return num;
    }
}