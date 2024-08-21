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

enum class ScopeType
{
    GLOBAL,
    FUNCTION,
    WHILE,
    IF,
    BLOCK,
};

class ScopeManager
{
    stack<int> offsets;
    vector<pair<unique_ptr<SymTable>, ScopeType>> scopes;
    ScopeManager();
public:
    static ScopeManager& getInstance()
    {
        static ScopeManager instance;
        return instance;
    }

    void pushScope(ScopeType type);
    void popScope();
    void insertSymbol(const shared_ptr<Symbol>& e);
    int findSymbol(const string& name) const;
    int findSymbolInCurrentScope(const string& name) const;
    bool searchIfScopeOpen(ScopeType type) const;

    shared_ptr<Symbol> getSymbol(const string& name) const;
    int getOffset() const;
    void printScope() const;
    ScopeType getLatestScopeType() const;
    string getLastScopeStartLabel() const;
    string getLastScopeEndLabel() const;
    void setLastScopeStartLabel(const string& label);
    void setLastScopeEndLabel(const string& label);

    class EmptyManager : public exception {};
};