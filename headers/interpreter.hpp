#pragma once
#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string>
#include <cstring>
#include <vector>
#include "../headers/prepare.hpp"

namespace interpreter{
	std::vector<std::string> getKeywords(void);
	std::vector<std::string> getKeywordsDesc(void);
	std::string initTerminal(void);
	std::string getKeyword(unsigned id);
	std::string getKeywordDesc(unsigned id);
	std::size_t getKeywordsSize(void);
	unsigned printHelp(void);
	int  execute(const std::string& command);
	int  adition(const std::string& word1, const std::string& word2);
	int  levenshtein_dist(const std::string& word1, const std::string& word2);
	void correction(const std::string& command);
}
