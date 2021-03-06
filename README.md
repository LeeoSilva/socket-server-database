# Database system:
A simple database system, written in C++ with client and server side communications via sockets.

## How does it works:
Fist an **interpreter** is called and is responsible for the input of the user
	and his meaning, then a command is sent to an **socket** responsible for
	the parsing of the informations and making sure that the final **database**
	understands and execute it flawlessly.

## Installation:
* First get the source code:
`git clone https://github.com/LeeoSilva/socket-server-database.git`

* Run configure.sh:
`sh socket-server-database/configure.sh`

* Enter in the `build` tree:
`cd socket-server-database/build`

* Compile from source:
`make`

## TODOLIST:
- [x] Write interpreter code;
- [x] Implement command correction;
- [x] Implement Levenshtein Distance algorithm;
- [x] Add ./configure.sh file;
- [ ] Optimize the Levenshtein Distance algorithm;
- [x] Create a client-side socket;
- [x] Create a server-side socket;
- [ ] Solve EOF input infinite loop;
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
