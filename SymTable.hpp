//
// Created by Baraa Egbaria on 10/08/2024.
// Copyright © 2024 Baraa Egbaria All rights reserved.
//
// SymTable.cpp

#pragma once

#include "Symbol.hpp"
#include <vector>
#include <string>
#include <memory>

using namespace std;

class SymTable
{
private:
    vector<shared_ptr<Symbol>> elements;
    std::string startLabel;
	std::string endLabel;
public:
    SymTable() = default;
    SymTable(const SymTable& table) = default;
    ~SymTable() = default;

    void AddSymbol(const shared_ptr<Symbol>& e);
    int findSymbol(const string& elementName) const;
    shared_ptr<Symbol> getSymbol(const string& elementName);
    const string& getStartLabel() const;
    const string& getEndLabel() const;
    void setStartLabel(const string& label);
    void setEndLabel(const string& label);
    void printSymTable() const;
};