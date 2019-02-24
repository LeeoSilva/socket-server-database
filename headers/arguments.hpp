#pragma once
#include "../includes/arguments.cpp"

void arguments::checkArguments(int argc, char *argv[]);
int  arguments::check_getHelp(std::string argument);
int  arguments::check_getPort(std::string argument);
