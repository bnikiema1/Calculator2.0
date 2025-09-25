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

    print << "Enter a math expression" <<endl;

    getline(input,exp);

    // taking the expression and removing whitespace
    string cleanExp;
    for(char c : exp){
        if(!isspace(c)){
            cleanExp += c;
        }
    }

    //stores a tuple of the index and the sign in a vector
    auto operaters = operatorSign(cleanExp);

    // for(const auto& op: operaters){
    //     print << "Position: " << get<0>(op) <<" Operator: " << get<1>(op) <<endl;
    // }
    string newExp = brackets(cleanExp);
    double result = basicCalc(newExp);
    print << newExp << endl;
    print << "Result: "<< result << endl;
    
    return 0;
}


