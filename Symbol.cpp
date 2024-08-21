#include "Symbol.hpp"
#include <vector>
#include <string>
#include <iostream>

using namespace std;


Symbol::Symbol(const string& type, const string& name, string registerName, int offset)
    : type(type), name(name), regName(registerName), offset(offset)  {}


const string& Symbol::getType() const { return type; }
const string& Symbol::getName() const { return name; }
const string& Symbol::getRegName() const { return regName; }
int Symbol::getOffset() const { return offset; }

void  Symbol::setType(const string& type) { this->type = type; }
void  Symbol::setName(const string& name) { this->name = name; }
void  Symbol::setRegName(const string& registerName) { this->regName = registerName; }
void  Symbol::setOffset(int offset) { this->offset = offset; }


Num::Num(const string& name, int value, string registerName, int offset) : Symbol("INT", name, registerName, offset), val(value) {}
int Num::getValue() const { return val; }

myString::myString(const string& name, const string& value, string registerName, int offset) : Symbol("STRING", name, registerName, offset), val(value) {}
string myString::getStringValue() const { return val; }

Function::Function(const string& name, int offset, string returnType = "", vector<string> parametersTypes = vector<string>()) :
        Symbol("FUNCTION", name, "NONE", offset), returnType(returnType), parametersTypes(parametersTypes) {}

string Function::getReturnType() const { return returnType; }
vector<string>& Function::getParametersTypes()  { return parametersTypes; }