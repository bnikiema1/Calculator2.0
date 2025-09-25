#include <iostream>
#include "basic.h"

using namespace std;

int basicCalc(int a, int b, char sign)

{
    if (sign == '+'){
        return a + b;
    }
    if (sign == '-'){
        return a - b;
    }
    if (sign == '/'){
        if(b == 0){
            cout << "Error Cant divide by zero"<< endl;
            return 0;
        }else{
            return a / b;
        }
    }
    if (sign == '*'){
        return a * b;
    }else{
        cout << "invalid operator";
        return 0;
    }
}

char operatorSign(std::string expression){

        if(expression.find("+")!= std::string::npos){
        return expression.find("+");
    }
    if (expression.find("-") != std::string::npos){
        return expression.find("-");
    }
    if (expression.find("*") != std::string::npos){
        return expression.find("*");
    }
    if (expression.find("/") != std::string::npos){
        return expression.find("/");
    }
    else{
        std::cout << "Invalid operator please try again" << endl;
        return '!';
    }
}