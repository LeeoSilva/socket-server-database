#include <iostream>
#include <string>

namespace arguments {

	// typedef struct seila{
	// 	unsigned port;
	// };

	int check_getHelp(const std::string& argument){
		if (argument.compare("--help") != 0) return -1; // EXIT_CODE.
		std::cout << "2019 - Leonardo Silva <leeosilva0909@gmail.com>" << std::endl;
		std::cout << "Usage: socket_server_datase [--options]" << std::endl << std::endl;
		std::cout << "OPTIONS: " << std::endl;
		std::cout << "\t--help\t\t\t Shows this message." << std::endl;
		std::cout << "\t--port=<COMMAND>\t Especify the port to bind the server." << std::endl;
		return 0;
	}

	int check_getPort(const std::string& argument){
		std::size_t equal_pos = argument.find('=');
		if( equal_pos == -1 ) return -1;
		unsigned port = stoi(argument.substr(equal_pos + 1));
		return port;
	}


	int checkArguments(int argc, char *argv[]){
		// Do individual argument check in a outside function loop.
		std::string argument;
		for( unsigned i = 1; i < argc; i++ ){
			argument = std::string(argv[i]);
			// Checks every argument and gets if argument especified
			if( arguments::check_getHelp(argument) == 0 ) return -1; // EXIT_CODE.
			arguments::check_getPort(argument);
		}
		return 0;
	}

}
