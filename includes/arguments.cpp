#include <iostream>
#include <string>
#include <iterator>

namespace arguments {
	int checkPort(std::string argument){
		std::cout << "Port function called" << std::endl;
		return 0;
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
			checkHelp(argument); // TODO
			checkPort(argument);
		}
	}


}

int main(int argc, char *argv[]){
	arguments::checkArguments(argc, argv);
	return 0;
}
