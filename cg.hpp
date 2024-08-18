#ifndef EX5_CODE_GEN
#define EX5_CODE_GEN

#include <vector>
#include <string>

using namespace std;

class CodeBuffer{
	CodeBuffer();
	CodeBuffer(CodeBuffer const&);
    void operator=(CodeBuffer const&);
	std::vector<std::string> buffer;
	std::vector<std::string> globalDefs;
	int labels_num = 1;
public:
	static CodeBuffer &instance();

	// ******** Methods to handle the code section ******** //

	//generates a jump location label for the next command and returns it
	std::string freshLabel();

	//writes command to the buffer, returns its location in the buffer
	int emit(const std::string &command);
	
	//prints the content of the code buffer to stdout
	void printCodeBuffer();

	// ******** Methods to handle the data section ******** //
	//write a line to the global section
	void emitGlobal(const string& dataLine);
	//print the content of the global buffer to stdout
	void printGlobalBuffer();

};

#endif
