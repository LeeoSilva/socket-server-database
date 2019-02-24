#pragma once
#include "../includes/communication.cpp"

sockaddr_in communication::openHint(unsigned port, std::string server_ip);
unsigned communication::openSocket(unsigned port, std::string server_ip);
int communication::openConnection(sockaddr_in hint, unsigned sock);
int communication::sendData(int sock, std::string userInput);
int communication::closeSocket(int socket);
