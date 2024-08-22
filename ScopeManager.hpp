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
    WHILE_LOOP,
    IF_STATEMENT,
    ELSE_STATEMENT,
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
    bool findSymbol(const string& name) const;
    bool findSymbolInCurrentScope(const string& name) const;
    bool searchIfScopeOpen(ScopeType type) const;

    shared_ptr<Symbol> getSymbol(const string& name) const;
    int getOffset() const;
    ScopeType getLatestScopeType() const;
    string getLastScopeStartLabel() const;
    string getLastScopeEndLabel() const;
    string getLastWhileScopeStartLabel() const;
    string getLastWhileScopeEndLabel() const;
    void setLastScopeStartLabel(const string& label);
    void setLastScopeEndLabel(const string& label);

    void printScope() const;
    class EmptyManager : public exception {};
};