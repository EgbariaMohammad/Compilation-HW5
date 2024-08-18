//
// Created by Baraa Egbaria on 10/08/2024.
// Copyright © 2024 Baraa Egbaria All rights reserved.
//
//

#pragma once 

class Element
{
private:
    string name;
    string type;
    int pos;
    string returnType;              // in case this is a function ,otherwise its value ""
    vector<string> parametersTypes; // in case this is a function ,otherwise its Empty
    string var;
    bool isParameter;

public:
    Element(string name, string type, int pos, string returnType = "", vector<string> parametersTypes = vector<string>(), string var = "", bool isAParameter = false)
        : name(name), type(type), pos(pos), returnType(returnType), parametersTypes(parametersTypes), var(var), isParameter(isAParameter) {}

    const string &getName() const { return name; }
    string returnVar() const { return this->var; }
    bool isParam() const { return isAParameter; }
    string getType() const { return type; }
    string getReturnType() const { return returnType; }
    vector<string> &getParametersTypes()  { return parametersTypes; }
    int getPos() const { return pos; }
};