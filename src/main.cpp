#include <iostream>
#include <string>
#include <algorithm>
#include "../headers/interpreter.hpp"
#include "../headers/arguments.hpp"

int main(int argc, char* argv[]){
	const int EXIT_CODE = -1; // Init 0 the program.
	if( arguments::checkArguments(argc, argv) == EXIT_CODE) return 0;

	int fallback = 0;
	while( fallback != EXIT_CODE ){
		std::string command = interpreter::initTerminal();
		std::transform(command.begin(), command.end(), command.begin(), ::toupper);
		fallback = interpreter::execute(command);
	}
	return 0;
}
