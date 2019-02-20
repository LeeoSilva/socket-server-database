#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string>
#include <cstring>

int main(int argc, char* argv[]){
	// Creates a socket.
	int sock = socket(AF_INET, SOCK_STREAM, 0);
	if( sock == -1 ){
		std::cerr << "Could not create communication socket." << std::endl;
		return -1;
	}

	// Creating a structure for the server connection.
	int port = 5300; // Default port
	std::string server_ip = "127.0.0.1";

	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(port); // Host to network short (arch the structure needs)
	inet_pton(AF_INET, server_ip.c_str(), &hint.sin_addr);

	// Uses the socket to connect to the server.
	int conn = connect(sock, (sockaddr*)&hint, sizeof(hint));
	if( conn == -1  ){
		std::cerr << "Could not connect to the server." << std::endl;
		return -1;
	}

	do{
		std::string userInput;
		// buffer = interpreter::initTerminal();
		std::cout << "> ";
		std::getline(std::cin, userInput);

		// Send to server
		unsigned BUFFER_SIZE_LIMIT = 4096;
		char buffer[BUFFER_SIZE_LIMIT];
		int sent = send(sock, userInput.c_str(), userInput.size() + 1, 0);
		if( sent == -1 ){
			std::cerr << "Could not send data to server." << std::endl;
			continue;
		}

		// Wait for server response.
		memset(buffer, 0, BUFFER_SIZE_LIMIT);
		int received = recv(sock, buffer, BUFFER_SIZE_LIMIT, 0);

		// Display response
		std::cout << ":: " << std::string(buffer, received) << std::endl;
	}while(true);

	close(sock);

}
