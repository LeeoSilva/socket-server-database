#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <string>
#include <cstring>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]){
	// Creates a socket
	int listening = socket(AF_INET, SOCK_STREAM, 0);
	if( listening == -1 ){
		std::cerr << "Could not create a socket." << std::endl;
		return -1;
	}

	// Bind the socket to a IP / Port
	unsigned port = 5400; // Default port.
	sockaddr_in hint;
	hint.sin_family = AF_INET; // IPv4 structure
	hint.sin_port = htons(port);
	const char* server_ip = "0.0.0.0";  // The Ip address means
										// That everybody can connect.
	inet_pton(AF_INET, server_ip, &hint.sin_addr);

    if( (bind(listening, (sockaddr*)&hint, sizeof(hint)) == -1)){
		std::cerr << "Could not bind to IP/Port" << std::endl;
		return -1;
	}

	// Mark the socket for listening
	unsigned MAX_CONNECTIONS_ALLOWED = 5;
	if( listen(listening, MAX_CONNECTIONS_ALLOWED) == -1 ){
		std::cerr << "Could not listen to socket" << std::endl;
		return -1;
	}

	// Accept a call
	sockaddr_in client;
	socklen_t clientSize;
	char host[NI_MAXHOST]; // Buffer for the host name.
	char service[NI_MAXSERV]; // Buffer for the service name.

	int clienSocket = accept(listening, (sockaddr*)&client, &clientSize);
	if( clienSocket == -1 ){
		std::cerr << "Problem with client connection" << std::endl;
		return -1;
	}

	close(listening); // Close the listening socket
	memset(host, 0, NI_MAXHOST); // Zeroing the host buffer
	memset(service, 0, NI_MAXSERV); // Zeroing the service buffer

	int result = getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST, service, NI_MAXSERV, 0);

	if( result ){
		std::cout << host << " connected on " << service << std::endl;
		std::cout << "The server is on: " << server_ip << ':' << port << std::endl;
	}else{
		inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
		std::cout << host << " connected on " << ntohs(client.sin_port) << std::endl;
		std::cout << "The server is on: " << server_ip << ':' << port << std::endl;
	}

	char buffer[4096];
	while(true){
		// Clear the buffer
		memset(buffer, 0, 4096);

		// Wait for a message
		int bytesRecv = recv(clienSocket, buffer, 4096, 0);
		if( bytesRecv == -1 ){
			std::cerr << "There was a connection issue" << std::endl;
			break;
		}

		if( bytesRecv == 0 ){
			std::cerr << "The client disconnected" << std::endl;
			break;
		}

		std::cout << "Received: " << std::string(buffer, 0, bytesRecv) << std::endl;
		send(clientSize, buffer, bytesRecv + 1, 0);
	}

	close(clientSize);
	return 0;
}
