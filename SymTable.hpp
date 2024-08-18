//
// Created by Baraa Egbaria on 10/08/2024.
// Copyright © 2024 Baraa Egbaria All rights reserved.
//
// SymTable.hpp  - SymbolTable

#pragma once 

#include "Element.hpp"
#include <vector>

class SymTable
{
private:
    vector<Element> elements;

public:
    SymTable() = default;
    SymTable(const& SymTable& table) = delete;
    ~SymTable() = default;
    
    int AddElement(const Element& e);
    string FunctionReturnType(const string& name) const;
    bool MainExists() const;
    bool checkIfOneOfTheseAlreadyDefined(const vector<string> &vec, const string &result) const;
    string ElementType(const string& name) const;

    string ElementVar(const string& var) const;
    bool isParam(const string& var) const;
    bool SymbolExists(const string& elementName) const;
    void printSymTable() const;

    vector<string> getVectorOfParametersReturnType(const string& name) const;
    vector<string> getVectorOfParametersInferredFromSymTable() const;
    vector<string> getVectorOfParametersIdsInferredFromSymTable() const; 
    
};