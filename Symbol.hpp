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
    string trueLabel;
    string falseLabel;
public:
    Symbol(const string& type, const string& name, string registerName="NONE", int offset = -1, const string& trueLabel = "", const string& falseLabel = "");
    Symbol(const Symbol& e) = default;
    virtual ~Symbol() = default;

    const string& getType() const;
    const string& getName() const;
    const string& getRegName() const;
    int getOffset() const;
    string getTrueLabel() const;
    string getFalseLabel() const;

    void setType(const string& type);
    void setName(const string& name);
    virtual int getValue() const { return -100; }
    virtual string getStringValue() const { return "NOT Overriden"; }
    void setRegName(const string& registerName);
    void setOffset(int offset);
    void setTrueLabel(const string& label);
    void setFalseLabel(const string& label);
};

class Num : public Symbol
{
    int val;
public:
    Num(const string& name, int value, string registerName="NONE", int offset = -1);
    virtual int getValue() const override;
};


class myString : public Symbol
{
    string val;
public:
    myString(const string& name, const string& value, string registerName="NONE", int offset = -1);
    string getStringValue() const override;
};

class Function : public Symbol {
private:
    string returnType;
    vector<string> parametersTypes;
public:
    Function(const string& name, int offset, string returnType = "", vector<string> parametersTypes = vector<string>());
    string getReturnType() const;
    vector<string>& getParametersTypes();
};