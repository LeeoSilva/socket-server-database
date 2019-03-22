#pragma once
#include <iostream>
#include <string>

namespace arguments{
	int check_getPort(const std::string& argument);
	int checkArguments(int argc, char *argv[]);
	int check_getHelp(const std::string& argument);
	std::string check_getServer(const std::string& argument);
}
