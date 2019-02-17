#include <iostream>
#include <string>
#include <vector>

namespace interpreter{

	std::vector<std::string> getKeywords(){
		return {
			"CREATE",
			"DELETE",
			"UPDATE",
			"EDIT",
			"SELECT"
		};
	}

 	unsigned getKeywordsSize() return interpreter::getKeywords().size();

	std::string initTerminal(){
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
			if( interpreter::levenshtein_dist(command, keywords[i]) < record ){
				record = interpreter::levenshtein_dist(command, keywords[i]);
				correction = keywords[i];
			}
		std::cout << "Did you mean '" << correction << "'?'" << std::endl;
	}

	// int execute(std::string command){
	// 	for( unsigned i = 0; i <= interpreter::getKeywordsSize(); i++ ){
	// 		if(  )
	// 	}
	// }

	void printHelp(){
		std::vector<std::string> keywords = {
			"INIT",
			"DELETE"
	 	};

		std::vector<std::string> keywords_desc = {
			"Inits the database",
			"Deletes all content"
		};
		for( unsigned i = 0; i < interpreter::getKeywordsSize(); i++ )
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
