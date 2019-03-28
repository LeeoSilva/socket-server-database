#include "../headers/prepare.hpp"

namespace prepare{

	int init(const std::string& command){
		/*
		Alocates memory for the initial state of the database.
			@row const std::string&
		*/
		std::size_t space_pos = command.find(" "); // Finds the fist occurence of spaces.
		std::string databaseName = command.substr(0,space_pos);
		if( space_pos == std::string::npos ) return -1;
		else std::cout << databaseName << std::endl;
		std::cout << "Arrived here" << std::endl;
		// struct database database;
		return 0;
	}

	template <typename T>
	std::string edit(const std::string& tableName, T row){
		/*
		Edit the row of the database.
			@row const std::string
			@row unsigned int
		*/
	}

	template <typename T>
	std::string exclude(const std::string& tableName, T row){
		/*
		Exclude the row in common with the argument
			@row const std::string
			@row unsigned int
		*/
	}


	template <typename T>
	std::string select(const std::string& tableName, T row){
		/*
		Gets the content of a row in the database
			@row const std::string&
			@row unsigned int
		*/
	}

	int truncate(const std::string& tableName){
		/*
		Erase all the values from the memory for the given table.
		*/
	}

	template <typename T>
	int update(const std::string& tableName, T row){
		/*
		Updates the content of a table given its row.
		This function supports the following types:
			@row const std::string&
			@row unsigned int
		*/
	}
}
