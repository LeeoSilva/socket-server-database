# Database system:
A simple database system, written in C++ with client and server side communications via sockets.

## How does it works:
Fist an **interpreter** is called and is responsible for the input of the user
	and his meaning, then a command is sent to an **socket** responsible for
	the parsing of the informations and making sure that the final **database**
	understands and execute it flawlessly.

## TODOLIST:
- [x] Write interpreter code;
- [x] Implement command correction;
- [x] Implement Levenshtein Distance algorithm;
- [x] Add ./configure.sh file;
- [ ] Optimize the Levenshtein Distance algorithm;
- [ ] Create a client-side socket;
- [ ] Create a server-side socket;
- [ ] Send data from client-side to server-side;
- [ ] Parse data received from the interpreter;
- [ ] Implement Edit database basic function;
- [ ] Implement Exclude database basic function;
- [ ] Implement Init database basic function;
- [ ] Implement Select database basic function;
- [ ] Implement Truncate database basic function;
- [ ] Implement Update database basic function;
- [ ] Create a log system;
- [ ] Setup a web page for visualization of the database;
