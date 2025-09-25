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

    getline(input,exp);

    // taking the expression and removing whitespace
    string cleanExp;
    for(char c : exp){
        if(!isspace(c)){
            cleanExp += c;
        }
    }

    //Spliting the expression and getting the terms and operater in variables
    int operaterIdx = operatorSign(cleanExp);

    char sign = cleanExp.at(operaterIdx);
    int a = stoi(cleanExp.substr(0,operaterIdx));
    int b = stoi(cleanExp.substr(operaterIdx + 1));

    int result = basicCalc(a, b, sign);
    print << "Result: "<< result << endl;
    
    return 0;
}


