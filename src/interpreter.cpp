#include "../headers/interpreter.hpp"

namespace interpreter{
	std::vector<std::string> getKeywords(void){
		return {
			"EXIT",
			"SELECT",
			"HELP",
			"INIT",
			"TRUNCATE",
			"EXCLUDE",
			"UPDATE"
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


 	std::size_t getKeywordsSize(void){
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
		if ( length1 == 0 ) return length2;
		if ( length2 == 0 ) return length1;
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

	void correction(const std::string& command){
		// Uses the Levenshtein Distance to do a correction
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

	unsigned printHelp(void){
		/*
		Display a message for the user with the descripton of the command
		from the dictionary.
		*/

		std::vector<std::string> keywords = interpreter::getKeywords();
		std::vector<std::string> keywords_desc = interpreter::getKeywordsDesc();
		for( unsigned i = 0; i < interpreter::getKeywordsSize(); i++ )
			std::cout << interpreter::getKeyword(i) << " - " << interpreter::getKeywordDesc(i) << std::endl;
		std::cout << std::endl;
		return 1;
	}

	std::string getFirstOccurence(const std::string& command){
		/*
		Gets the fist word of the command passed by the server for later check.
			@command const std::string&
		*/
		std::size_t space_pos = command.find(" ");
		if( space_pos == std::string::npos ){
		std::cout << "npos" << std::endl;
		return command;
	}
		std::cout << "Command len: " << command.length() << std::endl;
		std::cout << "Space pos: " << space_pos << std::endl;
		if( space_pos == std::string::npos || ( space_pos == command.length()-1 ) ){
			std::string modCommand = command;
			modCommand.erase(space_pos, space_pos);
			return modCommand;
		}
	}

	int execute(const std::string& command){

		if(         interpreter::getFirstOccurence(command) == interpreter::getKeyword(1) ) return prepare::init(command);
		// if     ( interpreter::getFirstOccurence(command) == interpreter::getKeyword() )  return prepare::edit(command);
		// else if( interpreter::getFirstOccurence(command) == interpreter::getKeyword() )  return prepare::exclude(command);
		// else if( interpreter::getFirstOccurence(command) == interpreter::getKeyword() )  return prepare::select(command);
		// else if( interpreter::getFirstOccurence(command) == interpreter::getKeyword() )  return prepare::truncate(command);
		// else if( interpreter::getFirstOccurence(command) == interpreter::getKeyword() )  return prepare::update(command);
		// else if( interpreter::getFirstOccurence(command) == interpreter::getKeyword() )  return interpreter::printHelp();
		else if( command == interpreter::getKeyword(0) )  return -1;
		else std::cout << "Command not found: " << command << std::endl;
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
