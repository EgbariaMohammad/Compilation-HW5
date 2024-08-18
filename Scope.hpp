//
// Created by Baraa Egbaria on 10/08/2024.
// Copyright © 2024 Baraa Egbaria All rights reserved.
//
// Scope.hpp

#pragma once
#include "SymTable.hpp"
#include "Element.hpp"

class Scope
{
    int current_offset;
    SymbolTable symTable;
    string type;
    string returnType; // in case this is a function scope ,otherwise its value ""
public:
    Scope(int current_offset, string type, string returnType = "");

    void addInScope(string name, string type, int pos, string returnType = "",
                    vector<string> parametersTypes = vector<string>(), string var = "NOT_PARAM", bool isParam = false);
    bool mainExistsInScope() const;
    bool varExists(const string& name) const;
    void printScope() const;
    void setCurrentOffset(int offset);
    int getCurrentOffset() const;

    const string& getType() const;
    string getReturnType() const;
    string returnVar(const string& name) const;
    bool isParam(const string& name) const;
    string getElementType(const string& name) const;
    string getFunctionReturnType(const string& name) const;

    vector<string> getVectorOfParametersReturnType(const string& name) const;
    vector<string> getVectorOfParametersInferredFromSymTable() const;
    vector<string> getVectorOfParametersIdsInferredFromSymTable() const;
    bool checkIfOneOfTheseAlreadyDefined(const vector<string> &vec, const string &result) const;
};