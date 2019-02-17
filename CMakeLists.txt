cmake_minimum_required(VERSION 3.1)

project(database_system)

set(database_system_VERSION_MAJOR 0)
set(database_system_VERSION_MINOR 1)

set(EXECUTABLE_NAME "database_system")
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

add_library(interpreter
	includes/interpreter.cpp
	headers/interpreter.hpp
)


add_executable(database_system
	../src/main.cpp
)

target_link_libraries(database_system PRIVATE interpreter)
