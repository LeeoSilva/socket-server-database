#include "../headers/database.hpp"

// void database::setDatabaseName(const std::string& databaseName){
// 	this->databases.insert(
// 		std::pair<std::string, unsigned>(databaseName, this->databases.size()
// 	));
//  }

// void database::setDesc(const std::string& desc){ this->desc = desc; }
// std::string database::getDatabaseName(){ return this->databases; }
// std::string database::getDesc(){ return this->desc; }

void database::updateSize(){ this->n_tables = this->databases.size(); }

int database::init(const std::string& databaseName){
	databases.insert(std::pair<std::string, int>(databaseName, (n_tables + 1) ));
	if( this->n_tables > this->databases.size() ) this->updateSize();
	else return -1;
	return 1;
}


int database::exclude(const std::string& command){
	std::cout << "Exclude Function" << std::endl;
	return 1;
}
int database::edit(const std::string& command){
	std::cout << "Edit Function" << std::endl;
	return 1;
}
int database::select(const std::string& command){
	std::cout << "Select function" << std::endl;
	return 1;
}
int database::truncate(const std::string& command){
	std::cout << "Truncate function" << std::endl;
	return 1;
}
int database::update(const std::string& command){
	std::cout << "Update function" << std::endl;
	return 1;
}
