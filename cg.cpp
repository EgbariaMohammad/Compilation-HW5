#include "cg.hpp"
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

CodeBuffer::CodeBuffer() : buffer(), globalDefs() {}

CodeBuffer &CodeBuffer::instance() {
	static CodeBuffer inst;//only instance
	return inst;
}

int CodeBuffer::bufferSize() const {
	return buffer.size();
}

string CodeBuffer::freshLabel(){
	std::stringstream label;
	label << "label_" << (labels_num+=2);
	return label.str();
}

int CodeBuffer::emit(const string &s){
    buffer.push_back(s);
	return buffer.size() - 1;
}

void CodeBuffer::printCodeBuffer(){
	for (std::vector<string>::const_iterator it = buffer.begin(); it != buffer.end(); ++it)
	{
		cout << *it << endl;
    }
}

// ******** Methods to handle the global section ********** //
void CodeBuffer::emitGlobal(const std::string& dataLine)
{
	globalDefs.push_back(dataLine);
}

void CodeBuffer::printGlobalBuffer()
{
	for (vector<string>::const_iterator it = globalDefs.begin(); it != globalDefs.end(); ++it)
	{
		cout << *it << endl;
	}
}

CodeGenerator& CodeGenerator::getInstance() {
	static CodeGenerator inst; //only instance
	return inst;
}

string CodeGenerator::freshRegister() {
    return "%t" + to_string(counterReg++);
}

string CodeGenerator::intToString(int offset) {
    return to_string(offset);
}

void CodeGenerator::increaseStringCounter() {
	stringCounter++;
}

int CodeGenerator::getStringCounter() {
	return stringCounter;
}

string CodeGenerator::getMostRecentTrueLabel() const {
	return mostRecentTrueLabel+":";
}
void CodeGenerator::setMostRecentTrueLabel(const string& label) {
	mostRecentTrueLabel = label;
}