#include "../headers/constructor.hpp"

namespace constructor{
	std::fstream initDatabase(const std::string& databaseName){
		// Create a file stream object.
		std::fstream databaseFile;

		// Enter new file with the name of the database.
		databaseFile.open((databaseName) + ".ssd", std::fstream::out | std::fstream::trunc); // Apends the extension
		if( !databaseFile.good() ) std::cerr << "Error creating the database file." << std::endl;
		else return databaseFile;
	}
}

// int main(void){
// 	constructor::initDatabase("Test0");
//
// 	return 0;
// }
