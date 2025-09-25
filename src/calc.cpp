#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <tuple>
#include "basic.h"
# define input cin
#define print cout

using namespace std;

int main()
{
    string exp;
    string var1;
    string var2;

    print << "Enter a math expression" <<endl;
    getline(input,exp);

    string cleanExp = brackets(exp);
    
    double result = basicCalc(cleanExp);
    print << "Result: "<< result << endl;
    
    return 0;
}


