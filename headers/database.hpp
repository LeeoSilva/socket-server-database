#pragma once
#include <iostream>
#include <string>
#include <map>

struct database{
	std::map<std::string, unsigned int> databases;
	std::string desc;
	// std::map<std::map<char, int>::iterator, bool> n_tables
	std::size_t n_tables = this->databases.size(); // Get database size without no modification.

	// void setDatabaseName(const std::string& databaseName);
	// void setDesc(const std::string& desc);
	void updateSize(void);


	std::string getDatabaseName(void);
	std::string getDesc(void);


	int init(const std::string& databaseName);
	int exclude(const std::string& command);
	int edit(const std::string& command);
	int select(const std::string& command);
	int truncate(const std::string& command);
	int update(const std::string& command);
};
