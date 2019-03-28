#pragma once
#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include <iostream>

namespace prepare{
	template<typename T> std::string edit(const std::string& tableName, T row);
	template<typename T> std::string exclude(const std::string& tableName, T row);
	int init(const std::string& databaseaName);
	template<typename T> std::string select(const std::string& tableName, T row);
	int truncate(const std::string& tableName);
	template<typename T> int update(const std::string& tableName, T row);
}
