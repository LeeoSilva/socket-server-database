#include <iostream>
#include <string>
#include <vector>
#include "../includes/database.cpp"

namespace interpreter{

	std::vector<std::string> getKeywords(void){
		return {
			"QUIT",
			"EDIT",
			"EXCLUDE",
			"INIT",
			"SELECT",
			"TRUNCATE",
			"UPDATE"
		};
	}

	std::string getKeyword(unsigned id){
		std::vector<std::string> keywords = interpreter::getKeywords();
		return keywords[id];
	}

	std::vector<std::string> getKeywordsDesc(void){
		return {
			"Terminates the program",
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
		std::cout << "[$]> ";
		getline(std::cin, bufferInput);
		return bufferInput;
	}

	// Finds the modification distance betwheen 2 words
	unsigned levenshtein_dist(std::string word1, unsigned length1, std::string word2, unsigned length2){
		// TODO: optimize it with separated functions executed by threads.
		if (length1 == 0) return length2;
		if (length2 == 0) return length1;
		if ( word1 == word2 ) return 0;

		unsigned cost;

		if (word1[length1 - 1] == word2[length2 - 1]) cost = 0;
		else cost = 1;

		unsigned deletion =  levenshtein_dist(word1, length1 - 1, word2, length2) + 1;
		unsigned insertion =  levenshtein_dist(word1, length1, word2, length2 - 1) + 1;
		unsigned substitution = levenshtein_dist(word1, length1 - 1, word2, length1 - 1) + cost;
		return std::min(std::min(deletion, insertion), substitution);
	}

	

	// Uses the Levenshtein Distance to do a correction
	void correction(std::string command){
		// TODO: Split the command in spaces
		std::string correction;
		unsigned record;
		std::vector<std::string> keywords = interpreter::getKeywords();
		unsigned threshold = 5;

		for(unsigned i = 0; i < interpreter::getKeywordsSize(); i++){
			// if( record > threshold ){
				// std::cout << "Command not found: " << command << std::endl;
				// return;
			// }

			unsigned current = interpreter::levenshtein_dist(command, command.length(), keywords[i], keywords[i].length());
			if( current < record ){
				record = current;
				correction = keywords[i];
			}
		}
		std::cout << "Did you mean '" << correction << "' ?" << std::endl;
	}

	int execute(std::string command){
		if     ( command == interpreter::getKeyword(1) )  return database::edit();
		else if( command == interpreter::getKeyword(2) )  return database::exclude();
		else if( command == interpreter::getKeyword(3) )  return database::init();
		else if( command == interpreter::getKeyword(4) )  return database::select();
		else if( command == interpreter::getKeyword(5) )  return database::truncate();
		else if( command == interpreter::getKeyword(6) )  return database::update();
		else if( command == interpreter::getKeyword(0) )  return -1;
		else correction(command);
		return 0;
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
