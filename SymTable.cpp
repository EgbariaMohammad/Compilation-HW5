#include "SymTable.hpp"

int SymTable::AddElement(const Element& e)
{
    elements.push_back(e);
    return 1;
}

string SymTable::FunctionReturnType(const string& name) const
{
    for (auto &s : elements)
    {
        if (!s.getName().compare(name))
        {
            return s.getReturnType();
        }
    }
    return "";
}

bool SymTable::MainExists() const
{
    for (auto &x : elements)
    {
        if (!x.getName().compare("main") && x.getParametersTypes().empty() && x.getReturnType() == "VOID")
        {
            return true;
        }
    }
    return false;
}

bool SymTable::checkIfOneOfTheseAlreadyDefined(const vector<string> &vec, const string &result) const
{
    for (auto &name : vec)
    {
        for (auto &elem : elements)
        {
            if (!name.compare(elem.getName()))
            {
                result = name;
                return true;
            }
        }
    }
    return false;
}

string ElementType(const string& name) const
{
    for (auto &x : elements)
    {
        if (!x.getName().compare(name))
        {
            return x.getType();
        }
    }
    return "";
}

string SymTable::ElementVar(const string& var) const
{
    for (auto &x : elements)
    {
        if (!x.getName().compare(var))
        {
            return x.returnVar();
        }
    }
    return "";
}

bool SymTable::isParam(const string& var) const
{
    for (auto &x : elements)
    {
        if (!x.getName().compare(var))
        {
            return x.isParam();
        }
    }
    return false;
}

bool SymTable::SymbolExists(const string& elementName) const
{
    for (auto &x : elements)
    {
        if (!x.getName().compare(elementName))
        {
            return true;
        }
    }
    return false;
}

void SymTable::printSymTable() const
{
    for (auto &x : elements)
    {

        if (!x.getType().compare("FUNCTION"))
        {
            output::printID(x.getName(), x.getPos(), output::makeFunctionType(x.getReturnType(), x.getParametersTypes()));
        }
        else
            output::printID(x.getName(), x.getPos(), x.getType());
    }
}

vector<string> SymTable::getVectorOfParametersReturnType(const string& name) const
{
    for (auto &x : elements)
    {
        if (!x.getName().compare(name))
        {
            return x.getParametersTypes();
        }
    }
    return {};
}

vector<string> SymTable::getVectorOfParametersInferredFromSymTable() const
{
    vector<string> toRet;
    for (auto &x : elements)
    {
        if (x.getPos() < 0)
        {
            toRet.push_back(x.getType());
        }
    }

    return toRet;
}

vector<string> SymTable::getVectorOfParametersIdsInferredFromSymTable() const
{

    vector<string> toRet;
    for (auto &x : elements)
    {
        if (x.getPos() < 0)
        {
            toRet.push_back(x.getName());
        }
    }
    return toRet;
}
