#include <iostream>
#include <tuple>
#include <vector>
#include <any>
#include "basic.h"

using namespace std;

double basicCalc(string exp)
{
    //extracting the operator signs from the expression
    auto operatorPos = operatorSign(exp);

    //Initalize a vector to store number between operation signs
    vector<int> numbers;
    size_t start = 0;

    // Isolating the numbers from operators
    for(const auto& [pos, op]: operatorPos){
        string num_str = exp.substr(start, pos - start);
        numbers.push_back(stod(num_str));
        start = pos + 1;
    }
    numbers.push_back(stod(exp.substr(start)));

    // After extracting numbers and operators in precedence order use a for loop to increment thru the var containing the sign and its position.
    for (size_t i = 0; i < operatorPos.size();){
        auto [pos, op] = operatorPos[i];

        if(op == '*' || op == '/'){
            double opResult = (op == '*') ? numbers[i] * numbers[i + 1]: numbers[i] / numbers[i + 1]; // starting from the leftside of the expression, if the operator is '/' || '*' it will multply or divide the first and second value in numbers

            numbers[i] = opResult; // Then it will assign that value to the numbers indexing the iteration of the loop
            numbers.erase(numbers.begin() + i + 1); //Then procceds to delete the next value in numbers as its current index is the reult of an operation using the next number
            operatorPos.erase(operatorPos.begin() + i);//then it deletes the operator sign that was just used
            // then loops through the operations vector again but with a shorter vector i will remain the same value and it repeats the procces until i < then the size of the vector
            //meaning either the vector == 0 indication it was only just multipcation and division operators or it just contains '+' || '-' meaning i > then the vector
            
        } else{ // if no '/' || '*' is not found no operations are done i increases by 1 and the loop repeats until i > vector
            i++;
        }  
    }
    double result = numbers[0]; // stores the result of the previous operations along with the number that got skipped in the last loop because the werent priority
    
    for (size_t i = 0; i < operatorPos.size(); i++) {
        auto [pos, op] = operatorPos[i];
        if (op == '+') {
            result += numbers[i + 1];
        } else if (op == '-') {
            result -= numbers[i + 1];
        }
    }
    
    return result;

}

vector<tuple<int, char>> operatorSign(string expression){

    string operators = "-+*/()";
    vector<tuple <int, char>> result;

    
    for(size_t i = 0; i < expression.length(); i++){
        if(operators.find(expression[i]) != std::string::npos){
            result.push_back(make_tuple(i, expression[i]));
        }
    }
    return result;
}

string brackets(string exp)
{
    string target;

    if(exp.find('(') != std::string::npos && exp.find(')') != std::string::npos){
        int openp = exp.find('(') + 1;
        int closep = exp.find(')') ;
        string newExp = exp.substr(openp , closep - openp );
        string beforep = exp.substr(0,openp-1);
        string afterp = exp.substr(closep +1 );

        double x = basicCalc(newExp);
        string pp = to_string(x);
        target = beforep + pp + afterp;

        return target;
    }else {
        return exp;
    }
    
}