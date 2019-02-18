#pragma once
#include "../includes/interpreter.cpp"

std::vector<std::string> interpreter::getKeywords(void);
std::vector<std::string> interpreter::getKeywordsDesc(void);
std::string interpreter::initTerminal(void);
std::string getKeyword(unsigned id);
std::string getKeywordDesc(unsigned id);
unsigned interpreter::levenshtein_dist(std::string word1, unsigned length1, std::string word2, unsigned lenght2);int interpreter::checkArguments(int argc, char* argv[]);
unsigned interpreter::getKeywordsSize(void);
int interpreter::execute(std::string command);
void interpreter::printHelp(void);
