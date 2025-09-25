#include <iostream>
#include <string>
#include <cstring>
# define input cin
#define print cout
using namespace std;

int basicCalc(int a, int b, char sign)

    string op = sign;
{
    if (sign == '+'){
        return a + b;
    }
    if (sign == '-'){
        return a - b;
    }
    if (sign == '/'){
        if(b == 0){
            print << "Error Cant divide by zero"<< endl;
            return 0;
        }else{
            return a / b;
        }
    }
    if (sign == '*'){
        return a * b;
    }else{
        print << "invalid operator";
        return 0;
    }
}


int main()
{
    string exp;

    print << "Enter a math expression" <<endl;

    input >> exp;
    //Spliting the expression and getting the terms and operater in variables

    int operaterIdx = exp.find("+");
    char sign = exp.at(operaterIdx);
    int a = stoi(exp.substr(0,operaterIdx));
    int b = stoi(exp.substr(operaterIdx+1));

    print << sign  endl;

    // int result = basicCalc(a, b, sign);
    // print << result << endl;
    
    return 0;
}


