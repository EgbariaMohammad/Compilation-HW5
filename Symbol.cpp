//
// Created by Baraa Egbaria on 10/08/2024.
// Copyright © 2024 Baraa Egbaria All rights reserved.
//
// Symbol.cpp

#include "Symbol.hpp"
#include <vector>
#include <string>
#include <iostream>

using namespace std;


Symbol::Symbol(const string& type, const string& name, string registerName, int offset,const string& trueLabel, const string& falseLabel) :
        type(type), name(name), regName(registerName), offset(offset), trueLabel(trueLabel), falseLabel(falseLabel) {}


const string& Symbol::getType() const { return type; }
const string& Symbol::getName() const { return name; }
const string& Symbol::getRegName() const { return regName; }
int Symbol::getOffset() const { return offset; }
string Symbol::getTrueLabel() const { return trueLabel; }
string Symbol::getFalseLabel() const { return falseLabel; }

void  Symbol::setType(const string& type) { this->type = type; }
void  Symbol::setName(const string& name) { this->name = name; }
void  Symbol::setRegName(const string& registerName) { this->regName = registerName; }
void  Symbol::setOffset(int offset) { this->offset = offset; }
void Symbol::setTrueLabel(const string& label) { trueLabel = label; }
void Symbol::setFalseLabel(const string& label) { falseLabel = label; }


Num::Num(const string& name, int value, string registerName, int offset) : Symbol("INT", name, registerName, offset), val(value) {}
int Num::getValue() const { return val; }

myString::myString(const string& name, const string& value, string registerName, int offset) : Symbol("STRING", name, registerName, offset), val(value) {}
string myString::getStringValue() const { return val; }

Function::Function(const string& name, int offset, string returnType, vector<string> parametersTypes) :
        Symbol("FUNCTION", name, "NONE", offset), returnType(returnType), parametersTypes(parametersTypes) {}

string Function::getReturnType() const { return returnType; }
const vector<string>& Function::getParametersTypes() const { return parametersTypes; }