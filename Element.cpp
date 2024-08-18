#include "Element.hpp"

Element::Element(string name, string type, int pos, string var = "", bool isAParameter = false)
    : name(name), type(type), pos(pos), var(var), isParameter(isAParameter) {}

Element::Element(const Element&) = default;
Element::~Element() = default;

const string& Element::getName() const { return name; }
string Element::returnVar() const { return this->var; }
bool Element::isParam() const { return isParameter; }
string Element::getType() const { return type; }
int Element::getPos() const { return pos; }

Function::Function(string name, string type, int pos, string returnType = "", vector<string> parametersTypes = vector<string>(), string var = "", bool isParam = false)
    : Element(name, type, pos, var, isParam), returnType(returnType), parametersTypes(parametersTypes) {}

Function::Function(const Element&) = default;
Function::~Function() = default;

string Function::getReturnType() const { return returnType; }
vector<string>& Function::getParametersTypes()  { return parametersTypes; }