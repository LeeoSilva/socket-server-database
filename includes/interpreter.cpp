#include <iostream>
#include <string>
#include <vector>
#include "../includes/database.cpp"

namespace interpreter{

	std::vector<std::string> getKeywords(void){
		return {
			"EDIT",
			"EXCLUDE",
			"INIT",
			"SELECT",
			"TRUNCATE",
			"UPDATE",
		};
	}

	std::string getKeyword(unsigned id){
		std::vector<std::string> keywords = interpreter::getKeywords();
		return keywords[id];
	}

	std::vector<std::string> getKeywordsDesc(void){
		return {
			"Deletes a given row from the database",
			"Edits a given row from the database",
			"Inits the database structure",
			"Gets content from a given row from the database",
			"Deletes all the content from the database structure",
			"Updates a given database content"
		};
	}

	std::string getKeywordDesc(unsigned id){
		std::vector<std::string> desc = interpreter::getKeywordsDesc();
		return desc[id];
	}


 	unsigned getKeywordsSize(void){
		std::vector<std::string> keywords =  interpreter::getKeywords();
		return keywords.size();
	}

	std::string initTerminal(void){
		std::string bufferInput;
		std::cout << "[$] ";
		std::cin >> bufferInput;
		return bufferInput;
	}

	// Finds the modification distance betwheen 2 words
	unsigned levenshtein_dist(std::string word1, unsigned length1, std::string word2, unsigned length2){
		if (length1 == 0) return length2;
		if (length2 == 0) return length1;
		unsigned cost;

		if (word1[length1 - 1] == word2[length2 - 1]) cost = 0;
		else cost = 1;

		return std::min(std::min(levenshtein_dist(word1, length1 - 1, word2, length2) + 1,  // deletion
				levenshtein_dist(word1, length1, word2, length2 - 1) + 1),		 		    // insertion
				levenshtein_dist(word1, length1 - 1, word2, length1 - 1) + cost);  		    // substitution
	}

	// Uses the Levenshtein Distance to do a correction
	void correction(std::string command){
		std::string correction;
		unsigned record;
		std::vector<std::string> keywords = interpreter::getKeywords();
		for(unsigned i = 0; i < getKeywordsSize(); i++)
			if( interpreter::levenshtein_dist(command, command.length(), keywords[i], keywords[i].length()) < record ){
				record = interpreter::levenshtein_dist(command, command.length(), keywords[i], keywords[i].length());
				correction = keywords[i];
			}
		std::cout << "Did you mean '" << correction << "'?'" << std::endl;
	}

	void execute(std::string command){
		for( unsigned i = 0; i < interpreter::getKeywordsSize(); i++ ){
			if( command == interpreter::getKeyword(0) )  database::edit();
			if( command == interpreter::getKeyword(1) )  database::exclude();
			if( command == interpreter::getKeyword(2) )  database::init();
			if( command == interpreter::getKeyword(3) )  database::select();
			if( command == interpreter::getKeyword(4) )  database::truncate();
			if( command == interpreter::getKeyword(5) )  database::update();
			else correction(command);
		}
	}

	void printHelp(void){
		std::vector<std::string> keywords = interpreter::getKeywords();
		std::vector<std::string> keywords_desc = interpreter::getKeywordsDesc();
		for( unsigned i = 0; i < interpreter::getKeywordsSize(); i++ )
			std::cout << interpreter::getKeyword(i) << " - " << interpreter::getKeywordDesc(i) << std::endl;
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
