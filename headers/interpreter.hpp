#pragma once
#include <string>
#include "../includes/interpreter.cpp"

std::string interpreter::initTerminal();
unsigned interpreter::levenshtein_dist(std::string word1, unsigned length1, std::string word2, unsigned lenght2);
void interpreter::printHelp();
int interpreter::checkArguments();
