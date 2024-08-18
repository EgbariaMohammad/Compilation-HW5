//
// Created by Baraa Egbaria on 10/08/2024.
// Copyright © 2024 Baraa Egbaria All rights reserved.
//
// Element.hpp

#pragma once

#include <vector>
#include <string>
#include <iostream>

using namespace std;


class Element
{
private:
    string name;
    string type;
    string var;
    int pos;
    bool isParameter;

public:
    Element(string name, string type, int pos, string var = "", bool isAParameter = false);


    Element(const Element& e) = default;
    virtual ~Element() = default;

    const string &getName() const;
    string returnVar() const;
    bool isParam() const;
    string getType() const;
    int getPos() const;
};


class Function : public Element {
private:
    string returnType;
    vector<string> parametersTypes;

public:
    Function(string name, string type, int pos, string returnType = "", vector<string> parametersTypes = vector<string>(), string var = "", bool isParam = false);

    Function(const Function&) = default;
    ~Function() = default;

    string getReturnType() const;
    vector<string>& getParametersTypes();
};