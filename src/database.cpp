#include "../headers/database.hpp"

namespace database{
	int exclude(const std::string& command){
		std::cout << "Exclude Function" << std::endl;
		return 1;
	}
	int edit(const std::string& command){
		std::cout << "Edit Function" << std::endl;
		return 1;
	}
	int init(const std::string& command){
		std::cout << "Init function" << std::endl;
		return 1;
	}
	int select(const std::string& command){
		std::cout << "Select function" << std::endl;
		return 1;
	}
	int truncate(const std::string& command){
		std::cout << "Truncate function" << std::endl;
		return 1;
	}
	int update(const std::string& command){
		std::cout << "Update function" << std::endl;
		return 1;
	}
}
