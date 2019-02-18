#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "../headers/interpreter.hpp"

int main(int argc, char* argv[]){
	if( interpreter::checkArguments(argc, argv) == 1) return 0;

	const int EXIT_CODE = -1;
	int fallback = 0;
	while( fallback != EXIT_CODE ){
		std::string command = interpreter::initTerminal();
		std::transform(command.begin(), command.end(), command.begin(), ::toupper);
		fallback = interpreter::execute(command);
	}
	return 0;
}
