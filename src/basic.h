#pragma once
#include <iostream>
#include <tuple>
#include <vector>
#include <string>
using namespace std;


double basicCalc (string exp);

vector<tuple<int, char>> operatorSign(string expression);

string brackets(string exp);