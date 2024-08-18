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

string CodeBuffer::freshLabel(){
	std::stringstream label;
	label << "label_" << ++labels_num;
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
