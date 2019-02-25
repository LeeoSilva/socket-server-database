#pragma once
#include "../includes/arguments.cpp"

int arguments::checkArguments(int argc, char *argv[]);
int  arguments::check_getHelp(const std::string& argument);
int  arguments::check_getPort(const std::string& argument);
