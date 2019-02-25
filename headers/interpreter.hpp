#pragma once
#include "../includes/interpreter.cpp"

std::vector<std::string> interpreter::getKeywords(void);
std::vector<std::string> interpreter::getKeywordsDesc(void);
std::string interpreter::initTerminal(void);
std::string interpreter::getKeyword(unsigned id);
std::string interpreter::getKeywordDesc(unsigned id);
unsigned interpreter::getKeywordsSize(void);
int  interpreter::execute(std::string command);
int  interpreter::adition(const std::string& word1, const std::string& word2);
int  interpreter::levenshtein_dist(const std::string& word1, const std::string& word2);
void interpreter::correction(const std::string& command);
void interpreter::printHelp(void);
