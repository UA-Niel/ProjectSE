compile:
	g++ -std=c++98 -o main main.cpp classes/*.h classes/*.cpp classes/*.hpp parsers/*.h parsers/*.cpp parsers/library/* utils.h utils.cpp
