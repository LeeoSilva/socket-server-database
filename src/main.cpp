#include <iostream>
#include <string>
#include <vector>
#include "../headers/interpreter.hpp"

int main(int argc, char* argv[]){
	if( interpreter::checkArguments(argc, argv) == 1) return 0;

	std::string command =  interpreter::initTerminal();
	std::cout << command << std::endl;

	interpreter::execute(command);

	return 0;
}
