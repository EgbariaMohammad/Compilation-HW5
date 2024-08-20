//
// Created by Baraa Egbaria on 10/08/2024.
// Copyright © 2024 Baraa Egbaria All rights reserved.
//
// Symbol.hpp

#pragma once

#include <vector>
#include <string>
#include <iostream>

using namespace std;


class Symbol
{
private:
    string name;
    string type;
    int offset;

public:
    Symbol(const string& name, const string& type, int position);

    Symbol(const Symbol& e) = default;
    virtual ~Symbol() = default;

    const string& getName() const;
    string getType() const;
    int getOffset() const;
};

class INT : public Symbol
{
    int val;
public:
    INT(const string& name, const string& type, int position, int val) : Symbol(name, type, position), val(val) {}
    virtual int getVal() const { return val; }
};

class BOOL : public INT {
public:
    BOOL(const string& name, const string& type, int position, bool val) : INT(name, type, position, val) {}
};

class Byte : public INT {
public:
    Byte(const string& name, const string& type, int position, int val) : INT(name, type, position, val) {}
};

class myString : public Symbol
{
    string val;
public:
    myString(const string& name, const string& type, int position, const string& val) : Symbol(name, type, position), val(val) {}
    string getVal() const { return val; }
};

class Function : public Symbol {
private:
    string returnType;
    vector<string> parametersTypes;

public:
    Function(string name, string type, int pos, string returnType = "", vector<string> parametersTypes = vector<string>());

    Function(const Function&) = default;
    ~Function() = default;

    string getReturnType() const;
    vector<string>& getParametersTypes();
};