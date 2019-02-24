
int main(int argc, char* argv[]){


	// Send to server
	unsigned BUFFER_SIZE_LIMIT = 4096;
	char buffer[BUFFER_SIZE_LIMIT];
	int sent = send(sock, userInput.c_str(), userInput.size() + 1, 0);
	if( sent == -1 ){
		std::cerr << "Could not send data to server." << std::endl;
	}

	// Wait for server response.
	memset(buffer, 0, BUFFER_SIZE_LIMIT);
	int received = recv(sock, buffer, BUFFER_SIZE_LIMIT, 0);

	// Display response
	std::cout << ":: " << std::string(buffer, received) << std::endl;
}
