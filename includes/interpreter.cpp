#pragma once
#include <iostream>
#include <string>

namespace interpreter{

	std::vector<std::string> getKeywords{
		return {
			"CREATE",
			"DELETE",
			"UPDATE",
			"EDIT",
			"SELECT"
		};


	std::string initTerminal(){
		std::string bufferInput;
		std::cout << "[$] ";
		std::cin >> bufferInput;
		return bufferInput;
	}

	// Finds the modification distance betwheen 2 words
	unsigned levenshtein_dist(std::string word1, std::string word2){
		if (word1.length() == 0) return word2.length();
		if (word2.length() == 0) return word1.length();
		unsigned cost;

		if (word1[word1.length() - 1] == word2[word2.length() - 1]) cost = 0;
		else cost = 1;

		return std::min(std::min(interpreter::levenshtein_dist(word1, word1.length() - 1, word2, word2.length()) + 1,  // deletion
				interpreter::levenshtein_dist(word1, word1.length(), word2, word2.length() - 1) + 1),		 		     // insertion
				interpreter::levenshtein_dist(word1, word1.length() - 1, word2, word2.length() - 1) + cost);  		 // substitution
	}

	// Uses the Levenshtein Distance to do a correction
	void correction(std::string command){
		std::string correction;
		unsigned record = ;
		std::vector<std::string> keywords = {
			"INIT",
			"DELETE"
	 	};
		for(unsigned i = 0; i < keywords.size(); i++)
			if( interpreter::levenshtein_dist(command, keywords[i]) < record ){
				record = interpreter::levenshtein_dist(command, keywords[i]);
				correction = keywords[i];
			}
		std::cout << "Did you mean '" << correction << "'?'" << std::endl;
	}

	int execute(std::string command){
		for( unsigned i = 0; i <= keywords.size(); i++ ){
			if(  )
		}
	}

	void printHelp(){
		std::vector<std::string> keywords = {
			"INIT",
			"DELETE"
	 	};

		std::vector<std::string> keywords_desc = {
			"Inits the database",
			"Deletes all content"
		};
		for( unsigned i = 0; i < keywords.size(); i++ )
			std::cout << keywords[i] << " - " << keywords_desc[i] << std::endl;
	}

	int checkArguments(int argc, char* argv[]){
		if( argc > 0 )
			for( unsigned i = 0; i < argc; i++ )
				if (std::string(argv[i]) == "--help"){
					printHelp();
					return 1;
				}
		return 0;
	}
}
