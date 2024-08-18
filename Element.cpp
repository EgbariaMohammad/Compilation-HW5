#include "Element.hpp"
#include <vector>
#include <string>
#include <iostream>

using namespace std;


Element::Element(string name, string type, int pos, string var, bool isAParameter)
    : name(name), type(type), var(var), pos(pos), isParameter(isAParameter) {}

const string& Element::getName() const { return name; }
string Element::returnVar() const { return this->var; }
bool Element::isParam() const { return isParameter; }
string Element::getType() const { return type; }
int Element::getPos() const { return pos; }

Function::Function(string name, string type, int pos, string returnType, vector<string> parametersTypes, string var, bool isParam)
    : Element(name, type, pos, var, isParam), returnType(returnType), parametersTypes(parametersTypes) {}

string Function::getReturnType() const { return returnType; }
vector<string>& Function::getParametersTypes()  { return parametersTypes; }