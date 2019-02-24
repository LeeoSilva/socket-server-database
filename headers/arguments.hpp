#pragma once
#include "../includes/arguments.cpp"

int arguments::checkPort(std::string argument);
int arguments::checkHelp(std::string argument);
void arguments::checkArguments(int argc, char *argv[]);
