#include "../headers/helper.hpp"

namespace helper{
	void select(){
		std::cout << "SELECT usage: SELECT <row> <table_name>" << std::endl;
	}

	void exclude(){
		std::cout << "EXCLUDE usage: EXCLUDE <row> <table_name>" << std::endl;
	}

	void truncate(){
		std::cout << "TRUNCATE usage: TRUNCATE <table_name>" << std::endl;
	}

	void update(){
		std::cout << "UPDATE usage: UPDATE <table_name> <row>=<modification>" << std::endl;
	}
};
