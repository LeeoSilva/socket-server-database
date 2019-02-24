#include <iostream>
#include <string>

namespace arguments {
	int checkPort(std::string argument){
		std::size_t equal_pos = argument.find('=');
		if( equal_pos == -1 ) return -1;
		unsigned port = stoi(argument.substr(equal_pos + 1));
		return port;
	}

	int checkHelp(std::string argument){
		std::cout << "Help function Called" << std::endl;
		return 0;
	}



	void checkArguments(int argc, char *argv[]){
		// Do individual argument check in a outside function loop.
		std::string argument;
		for( unsigned i = 1; i < argc; i++ ){
			argument = std::string(argv[i]);
			std::cout << checkPort(argument) << std::endl;
			checkHelp(argument); // TODO
			// checkPort(argument);
		}
	}


}

int main(int argc, char *argv[]){
	arguments::checkArguments(argc, argv);
	return 0;
}
