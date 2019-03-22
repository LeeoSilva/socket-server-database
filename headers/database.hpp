#pragma once
#include <iostream>
#include <string>
#include <vector>

namespace database{
	int exclude(const std::string& command);
	int edit(const std::string& command);
	int init(const std::string& command);
	int select(const std::string& command);
	int truncate(const std::string& command);
	int update(const std::string& command);
}
