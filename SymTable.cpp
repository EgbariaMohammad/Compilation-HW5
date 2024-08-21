#include "SymTable.hpp"
#include "hw3_output.hpp"
#include <vector>
#include <string>

using namespace std;

void SymTable::AddSymbol(const shared_ptr<Symbol>& e)
{
    elements.push_back(e);
}

int SymTable::findSymbol(const string& elementName) const
{
    for (const auto& x : elements)
    {
        if (x->getName() == elementName)
            return true;
    }
    return false;
}

void SymTable::printSymTable() const
{
    for (const auto &x : elements)
        output::printID(x->getName(), x->getOffset(), x->getType());
}

shared_ptr<Symbol> SymTable::getSymbol(const string& elementName)
{
    for (const auto& x : elements)
    {
        if (x->getName() == elementName)
            return x;
    }
    return nullptr;
}

const string& SymTable::getStartLabel() const {
    return startLabel;
}
const string& SymTable::getEndLabel() const {
    return endLabel;
}
void SymTable::setStartLabel(const string& label) {
    startLabel = label;
}
void SymTable::setEndLabel(const string& label) {
    endLabel = label;
}