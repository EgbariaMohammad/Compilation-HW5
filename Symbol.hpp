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
    string type; // INT, STRING, FUNCTION..
    string name;
    string regName;
    int offset;
public:
    Symbol(const string& type, const string& name, string registerName="NONE", int offset = -1);
    Symbol(const Symbol& e) = default;
    virtual ~Symbol() = default;

    const string& getType() const;
    const string& getName() const;
    const string& getRegName() const;
    int getOffset() const;

    void setType(const string& type);
    void setName(const string& name);
    void setRegName(const string& registerName);
    void setOffset(int offset);
};

class Num : public Symbol
{
    int val;
public:
    Num(const string& name, int value, string registerName="NONE", int offset = -1);
    virtual int getValue() const;
};


class myString : public Symbol
{
    string val;
public:
    myString(const string& name, const string& value, string registerName="NONE", int offset = -1);
    string getStringValue() const;
};

class Function : public Symbol {
private:
    string returnType;
    vector<string> parametersTypes;
public:
    Function(const string& name, int offset, string returnType = "", vector<string> parametersTypes = vector<string>()) :
        Symbol("FUNCTION", name, "NONE", offset), returnType(returnType), parametersTypes(parametersTypes) {}
    string getReturnType() const;
    vector<string>& getParametersTypes();
};