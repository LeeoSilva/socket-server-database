
std::vector<std::string> keywords = {"CREATE DATABASE", "CREATE TABLE", "SELECT", "INSERT", "DELETE", "HELP"};
std::vector<std::string> keywords_desc = {"Creates a new database.",
 										"Defines a new table.",
										"Retrieve rows from a table.",
										"Create new rows in a table.",
										"Delete rows from a table.",
										"Displays this message :)"};

int help(){
	for(unsigned i = 0; i < keywords.size(); ++i)
		std::cout << keywords[i] << " - " << keywords_desc[i] << std::endl;
}
