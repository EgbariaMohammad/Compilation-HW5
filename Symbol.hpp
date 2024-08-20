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
    Symbol(const string& name, const string& type, int position = -1);

    Symbol(const Symbol& e) = default;
    virtual ~Symbol() = default;

    const string& getName() const;
    virtual int getVal() const { return 0; }
    string getType() const;
    int getOffset() const;
};

class NUM : public Symbol
{
    int val;
public:
    NUM(const string& name, const string& type, int position, int val) : Symbol(name, type, position), val(val) {}
    virtual int getVal() const override { return val; }
};


class myString : public Symbol
{
    string val;
public:
    myString(const string& name, const string& type, int position, const string& val) : Symbol(name, type, position), val(val) {}
    string getValue() const { return val; }
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