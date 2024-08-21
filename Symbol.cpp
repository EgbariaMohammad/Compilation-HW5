#include "Symbol.hpp"
#include <vector>
#include <string>
#include <iostream>

using namespace std;


Symbol::Symbol(const string name, const string type, string variable , int position)
    : name(name), type(type), variable(variable), offset(position)  {}

const string& Symbol::getName() const { return name; }
string Symbol::getType() const { return type; }
int Symbol::getOffset() const { return offset; }

Function::Function(const string name, const string type, const string variable, int pos, string returnType, vector<string> parametersTypes) : Symbol(name, type, variable, pos), returnType(returnType), parametersTypes(parametersTypes) {}

string Function::getReturnType() const { return returnType; }
vector<string>& Function::getParametersTypes()  { return parametersTypes; }