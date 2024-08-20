//
// Created by Baraa Egbaria on 10/08/2024.
// Copyright © 2024 Baraa Egbaria All rights reserved.
//
// Scope.hpp

#pragma once
#include "Symbol.hpp"
#include "SymTable.hpp"
#include <vector>
#include <string>
#include <stack>

using namespace std;

class ScopeManager
{
    stack<int> offsets;
    vector<unique_ptr<SymTable>> scopes;
    ScopeManager() = default;
public:
    static ScopeManager& getInstance()
    {
        static ScopeManager instance;
        return instance;
    }
    void pushScope();
    void popScope();
    void insertSymbol(const shared_ptr<Symbol>& e);
    int findSymbol(const string& name) const;
    int getOffset() const;
    void printScope() const;

    class EmptyManager : public exception {};
};