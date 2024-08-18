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
    string var;
    int pos;
    bool isParameter;

public:
    Element(string name, string type, int pos, string var = "", bool isAParameter = false)
        : name(name), type(type), pos(pos), var(var), isParameter(isAParameter) {}

    Element(const Element&) = default;
    ~Element() = default; 

    const string &getName() const { return name; }
    string returnVar() const { return this->var; }
    bool isParam() const { return isParameter; }
    string getType() const { return type; }
    int getPos() const { return pos; }
};


class Function : public Element {
private:
    string returnType;              // in case this is a function ,otherwise its value ""
    vector<string> parametersTypes; // in case this is a function ,otherwise its Empty

public:
    Function(string name, string type, int pos, string returnType = "", vector<string> parametersTypes = vector<string>(), string var = "", bool isParam = false)
        : Element(name, type, pos, var, isParam), returnType(returnType), parametersTypes(parametersTypes) {}

    Function(const Element&) = default;
    ~Function() = default; 

    string getReturnType() const { return returnType; }
    vector<string> &getParametersTypes()  { return parametersTypes; }

};