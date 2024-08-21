//
// Created by Baraa Egbaria on 10/08/2024.
// Copyright © 2024 Baraa Egbaria All rights reserved.
//
// Symbol.hpp

#pragma once

#include <vector>
#include <string>
#include <iostream>

#define YYSTYPE Symbol*

using namespace std;


class Symbol
{
private:
    string name;
    string type;
    string variable;
    int offset;
public:
    Symbol(const string name, const string type, string variable="NO VARIABLE ALLOCATED", int position = -1);

    Symbol(const Symbol& e);
    virtual ~Symbol() = default;

    const string& getName() const;
    virtual int getValue() const { return -1; }
    string getType() const;
    int getOffset() const;

    string getVariable() const { return variable; }
    void setVariable(const string& variable) { this->variable = variable; }
    void setName(const string& name) { this->name = name; }
};

class Num : public Symbol
{
    int val;
public:
    Num(const string name, const string type, const string variable, int position, int val) : Symbol(name, type, variable, position), val(val) {}
    virtual int getValue() const override { return val; }
};


class myString : public Symbol
{
    string val;
public:
    myString(const string name, const string type, const string variable, int position, const string val) : Symbol(name, type, variable, position), val(val) {}
    string getStringValue() const { return val; }
};

class Function : public Symbol {
private:
    string returnType;
    vector<string> parametersTypes;

public:
    Function(const string name, const string type, const string variable, int pos, string returnType = "", vector<string> parametersTypes = vector<string>());
    string getReturnType() const;
    vector<string>& getParametersTypes();
};