//
// Created by Baraa Egbaria on 10/08/2024.
// Copyright © 2024 Baraa Egbaria All rights reserved.
//
// SymTable.hpp  - SymbolTable

#pragma once

#include "Symbol.hpp"
#include <vector>
#include <string>
#include <memory>

using namespace std;

class SymTable
{
private:
    vector<shared_ptr<Element>> elements;
    std::string startLabel;
	std::string endLabel;
public:
    SymTable() = default;
    SymTable(const SymTable& table) = default;
    ~SymTable() = default;

    void AddElement(const shared_ptr<Element>& e);
    int findSymbol(const string& elementName) const;
    void printSymTable() const;
};