//
// Created by Baraa Egbaria on 10/08/2024.
// Copyright © 2024 Baraa Egbaria All rights reserved.
//
// ScopeManager.cpp

#include "ScopeManager.hpp"
#include "Symbol.hpp"
#include "hw3_output.hpp"
#include <vector>
#include <string>
#include <memory>

using namespace std;

ScopeManager::ScopeManager() : offsets(stack<int>()), scopes(vector<unique_ptr<SymTable>>())
{
    offsets.push(0);
    pushScope();
}

void ScopeManager::pushScope()
{
    offsets.push(0);
    scopes.push_back(std::unique_ptr<SymTable>(new SymTable)); // replace with make unique
}

void ScopeManager::popScope()
{
    if (scopes.size() == 0)
        throw EmptyManager();
    offsets.pop();
    scopes.pop_back();
}

void ScopeManager::insertSymbol(const shared_ptr<Symbol>& e)
{
    scopes.back()->AddSymbol(e);
    offsets.top()++;
}

int ScopeManager::findSymbol(const string& name) const
{
    for (int i = scopes.size() - 1; i >= 0; i--)
    {
        int index = scopes[i]->findSymbol(name);
        if (index != -1)
            return index;
    }
    return -1;
}

int ScopeManager::getOffset() const
{
    return offsets.top();
}

void ScopeManager::printScope() const
{
    int scopeNum = 0;
    for (const auto& scope : scopes)
    {
        std::cout << "Scope number " << scopeNum++ << ":\n";
        scope->printSymTable();
    }
}