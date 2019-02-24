#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string>
#include <cstring>
#include "../includes/interpreter.cpp"

namespace communication{

	sockaddr_in openHint(unsigned port, std::string server_ip){
		// Opens the communication structure
		sockaddr_in hint;
		hint.sin_family = AF_INET; // Ipv4 structure
		hint.sin_port = htons(port); // Host to network short (arch the structure needs)
		inet_pton(AF_INET, server_ip.c_str(), &hint.sin_addr);
		return hint;
	}

	unsigned openSocket(){
		// Creates a socket.
		int sock = socket(AF_INET, SOCK_STREAM, 0);
		if( sock == -1 ){
			std::cerr << "Could not create communication socket." << std::endl;
			return -1;
		}
		return 0;
	}

	int openConnection(sockaddr_in hint, unsigned sock){
		// Uses the socket to connect to the server.
		// To make the communication.
		if( connect(sock, (sockaddr*)&hint, sizeof(hint)) == -1 ){
			std::cerr << "Could not connect to the server." << std::endl;
			return -1;
		}
		return 0;
	}

	void sendData(int sock, std::string userInput){
		// Send to server.
		unsigned BUFFER_SIZE_LIMIT = 4096; // Max receivable output.
		char buffer[BUFFER_SIZE_LIMIT]; // Buffer with max index of 4096.
		int sent = send(sock, userInput.c_str(), userInput.size() + 1, 0);
		if( sent == -1 ){
			std::cerr << "Could not send data to server." << std::endl;
		}

		// Wait for server response.
		memset(buffer, 0, BUFFER_SIZE_LIMIT);
		// Receives the response of the server
		int received = recv(sock, buffer, BUFFER_SIZE_LIMIT, 0);

		// Display response
		std::cout << ":: " << std::string(buffer, received) << std::endl;
	}

	int closeSocket(int socket){
		// Just closes the socket
		if( close(socket) == -1 ) return -1;
		else return 0;
	}
}
