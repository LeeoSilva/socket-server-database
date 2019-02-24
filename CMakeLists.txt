cmake_minimum_required(VERSION 3.1)

project(socket-server-database)

set(socket-server-database_VERSION_MAJOR 0)
set(socket-server-database_VERSION_MINOR 1)

set(DATABASE_EXECUTABLE_NAME "socket-server-database")
set(SERVER_EXECUTABLE_NAME "server-side-database")
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

add_library(interpreter
	includes/interpreter.cpp
	headers/interpreter.hpp
)

add_library(database
	includes/database.cpp
	headers/database.hpp
)

add_library(communication
	includes/communication.cpp
	headers/communication.hpp
)

add_executable(socket-server-database
	../src/main.cpp
)

add_executable(server
	../includes/server.cpp
)

target_link_libraries(socket-server-database PRIVATE interpreter)
target_link_libraries(socket-server-database PRIVATE database)
