#pragma once
#include <iostream>
#include <string>

namespace communication{
	sockaddr_in openHint(unsigned port, std::string server_ip);
	unsigned    openSocket(unsigned port, std::string server_ip);
	int   	    openConnection(sockaddr_in hint, unsigned sock);
	int 		sendData(int sock, std::string userInput);
	int 		closeSocket(int socket);
}
