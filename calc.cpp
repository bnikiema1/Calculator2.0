#include <iostream>
#include <string>
#include <cstring>
#include "basic.h"
# define input cin
#define print cout
using namespace std;

int main()
{
    string exp;

    print << "Enter a math expression" <<endl;

    input >> exp;
    //Spliting the expression and getting the terms and operater in variables
    int operaterIdx = operatorSign(exp);

    char sign = exp.at(operaterIdx);
    int a = stoi(exp.substr(0,operaterIdx));
    int b = stoi(exp.substr(operaterIdx+1));

    int result = basicCalc(a, b, sign);
    print << result << endl;
    
    return 0;
}


