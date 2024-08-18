//
// Created by Baraa Egbaria on 10/08/2024.
// Copyright © 2024 Baraa Egbaria All rights reserved.
//
// Scope.cpp

#include "Scope.hpp"

Scope::Scope(int current_offset, string type, string returnType = "") : current_offset(current_offset), type(type), returnType(returnType) {}

void Scope::addInScope(string name, string type, int pos, string returnType = "",
                vector<string> parametersTypes = vector<string>(), string var = "NOT_PARAM", bool isParam = false)
{
    symTable.AddElement(Element(name, type, pos, returnType, parametersTypes, var, isParam));
}

bool Scope::mainExistsInScope() const
{
    return symTable.MainExists();
}

bool Scope::varExists(const string& name) const
{    
    return symTable.SymbolExists(name);
}

void Scope::printScope() const
{
    output::endScope();
    symTable.printSymTable();
}

void Scope::setCurrentOffset(int offset)
{
    this->current_offset = offset;
}

int Scope::getCurrentOffset() const
{
    return current_offset;
}

const string& Scope::getType() const
{
    return type;
}

string Scope::getReturnType() const
{
    return returnType;
}

string Scope::returnVar(const string& name) const { return symTable.ElementVar(name); }
bool Scope::isParam(const string& name) const { return symTable.isParam(name); }

string Scope::getElementType(const string& name) const
{
    return symTable.ElementType(name);
}

string Scope::getFunctionReturnType(const string& name) const
{
    return symTable.FunctionReturnType(name);
}

vector<string> Scope::getVectorOfParametersReturnType(const string& name) const
{
    return symTable.getVectorOfParametersReturnType(name);
}

vector<string> Scope::getVectorOfParametersInferredFromSymTable() const
{
    return symTable.getVectorOfParametersInferredFromSymTable();
}

vector<string> Scope::getVectorOfParametersIdsInferredFromSymTable() const
{
    return symTable.getVectorOfParametersIdsInferredFromSymTable();
}

bool Scope::checkIfOneOfTheseAlreadyDefined(const vector<string> &vec, const string &result) const
{
    return symTable.checkIfOneOfTheseAlreadyDefined(vec, result);
}