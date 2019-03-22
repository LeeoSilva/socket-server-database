#include "../headers/database.hpp"

namespace interpreter{

	std::vector<std::string> getKeywords(void){
		return {
			"EXIT",
			"EDIT",
			"EXCLUDE",
			"INIT",
			"SELECT",
			"TRUNCATE",
			"UPDATE",
			"HELP"
		};
	}

	std::string getKeyword(unsigned id){
		std::vector<std::string> keywords = interpreter::getKeywords();
		return keywords[id];
	}

	std::vector<std::string> getKeywordsDesc(void){
		return {
			"\t\tTerminates the program",
			"\t\tDeletes a given row from the database",
			"\tEdits a given row from the database",
			"\t\tInits the database structure",
			"\tGets content from a given row from the database",
			"\tDeletes all the content from the database structure",
			"\tUpdates a given database content",
			"\t\tShows this message"
		};
	}

	std::string getKeywordDesc(unsigned id){
		std::vector<std::string> desc = interpreter::getKeywordsDesc();
		return desc[id];
	}


 	unsigned getKeywordsSize(void){
		std::vector<std::string> keywords = interpreter::getKeywords();
		return keywords.size();
	}

	std::string initTerminal(void){
		std::string bufferInput;
		std::cout << "[$]> ";
		getline(std::cin, bufferInput);
		return bufferInput;
	}

	// Finds the modification distance betwheen 2 words
	int deletion(const std::string& word1, const std::string& word2){
		// Step 1.
		unsigned length1 = word1.length();
		unsigned length2 = word2.length();
		if ( length1 == 0 ) 	  return length2;
		if ( length2 == 0 ) 	  return length1;
		if( length1 == length2 || length1 < length2 ) return 0; // No need to delete

		return length1 - length2;
	}

	int adition(const std::string& word1, const std::string& word2){
		// Step 2.
		// ((-deletion) + (-deletion) * -1) = adition_distance
		int score_distance = deletion(word1, word2);

		unsigned length1 = word1.length();
		unsigned length2 = word2.length();
		score_distance += (length1 - length2) * -1;
		return score_distance;
	}

	int levenshtein_dist(const std::string& word1, const std::string& word2){
		// The last step (substitution)
		unsigned score_distance = adition(word1, word2);
		unsigned aux;
		unsigned length = word2.length();

		for( unsigned i = 0; i < length; i++ )
			if( word1[i] != word2[i] ){
				score_distance++;
			}

		return score_distance;
	}

	// Uses the Levenshtein Distance to do a correction
	void correction(const std::string& command){
		int record = 15;
		int result;
		unsigned MAX_THRESHOLD = 4;
		std::string correction;
		for(unsigned i = 0; i < interpreter::getKeywordsSize(); i++){
			result = interpreter::levenshtein_dist(command, interpreter::getKeyword(i));
			std::cout << result << std::endl;
			if( result > MAX_THRESHOLD ){
				std::cout << "Command not found: " << command << std::endl;
				return;
			}

			if( result < record ){
				record = result;
				correction = interpreter::getKeyword(i);
			}
		}

		std::cout << "Did you mean '" << correction << "' ?" << std::endl;
	}

	int printHelp(void){
		std::vector<std::string> keywords = interpreter::getKeywords();
		std::vector<std::string> keywords_desc = interpreter::getKeywordsDesc();
		for( unsigned i = 0; i < interpreter::getKeywordsSize(); i++ )
			std::cout << interpreter::getKeyword(i) << " - " << interpreter::getKeywordDesc(i) << std::endl;
		std::cout << std::endl;
		return 1;
	}

	int execute(const std::string& command){
		if     ( command == interpreter::getKeyword(1) )  return database::edit(command);
		else if( command == interpreter::getKeyword(2) )  return database::exclude(command);
		else if( command == interpreter::getKeyword(3) )  return database::init(command);
		else if( command == interpreter::getKeyword(4) )  return database::select(command);
		else if( command == interpreter::getKeyword(5) )  return database::truncate(command);
		else if( command == interpreter::getKeyword(6) )  return database::update(command);
		else if( command == interpreter::getKeyword(7) )  return interpreter::printHelp();
		else if( command == interpreter::getKeyword(0) )  return -1;
		else std::cout << "Command not found: " << command << std::endl;
		return 0;
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
